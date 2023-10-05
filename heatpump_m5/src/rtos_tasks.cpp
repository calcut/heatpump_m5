#include "rtos_tasks.h"

SemaphoreHandle_t nc_mutex = xSemaphoreCreateMutex();

void setup_rtos_tasks(void){

    xTaskCreate(
        poll, // task function
        "Poll Yotta Module", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        notecard_time_sync, // task function
        "Notecard Time Sync", // task name
        32768, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle


    xTaskCreate(
        control, // task function
        "PID Control", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        state_machine, // task function
        "State Machine", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        notecard_service, // task function
        "Notecard Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        gui_service, // task function
        "LVGL GUI Service", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xTaskCreate(
        read_pulses, // task function
        "Read Pulses", // task name
        1024, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle
}

void gui_service(void * pvParameters){
    while(1){
        int delay_ms = lv_timer_handler();
        vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    }
}

void notecard_service(void * pvParameters){
    while(1){

        if (nc_service_enable){
            Serial.printf("Notecard info service\n");
            xSemaphoreTake(nc_mutex, portMAX_DELAY);
            notecardManager.hubGet();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.cardStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.getEnvironment();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.hubStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.hubSyncStatus();
            vTaskDelay(10 / portTICK_PERIOD_MS);
            notecardManager.cardWireless();
            vTaskDelay(10 / portTICK_PERIOD_MS);

            nc_service_tick = !nc_service_tick;
            xSemaphoreGive(nc_mutex);

            vTaskDelay(db_vars.nc_info_interval_s*1000 / portTICK_PERIOD_MS);
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void notecard_time_sync(void * pvParameters){
  while(1) {
    xSemaphoreTake(nc_mutex, portMAX_DELAY);
    notecardManager.cardStatus();

    if(notecardManager.connected){
        Serial.printf("Notecard time sync\n");

        notecardManager.getTime();
        setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    }
    else{
        Serial.printf("Notecard not connected, skipping time sync\n");
    }
    xSemaphoreGive(nc_mutex);
    vTaskDelay(db_vars.nc_time_sync_interval_s*1000 / portTICK_PERIOD_MS);
  }
}

void control(void * pvParameters){
    while(1){
        compressorPID.Compute();
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    
}

bool check_limits(){
    // Check if the compressor speed is within limits etc
    return true;
}



void state_machine(void * pvParameters){
    while(1){
        vTaskDelay(100 / portTICK_PERIOD_MS);

        if(db_vars.enabled == false){
            db_vars.mode = STANDBY;
            continue;
        }

        if(check_limits() == false){
            // Add logging or error handling
            db_vars.enabled = false;
            db_vars.mode = ERROR;
            continue;
        }

        if(qo_vars.tw_dhw > db_vars.dhw_setpoint){
            //DHW is above setpoint, no heating requested
            db_vars.mode = STANDBY;
            continue;
        }

        if(db_vars.mode == DEFROST){
            //This means a defrost timer is still running
            continue;
        }

        if(qo_vars.t_ambient < env_vars.defrost_thr_ambient){
            //Ambient temperature is below defrost threshold
            //Start defrost timer
            db_vars.mode = DEFROST;
            continue;
        }

        if(qo_vars.tw_flex > db_vars.thr_flex){
            //Flex store is above threshold
            db_vars.mode = DISCHARGING;
            continue;
        }
        if(qo_vars.tw_flex < db_vars.thr_flex){
            //Flex store is below threshold
            db_vars.mode = CHARGING;
            continue;
        }
    }
}

void poll(void * pvParameters){
    while(1){
        Serial.printf("Polling at %d ms\n", db_vars.poll_interval_ms);
        yottaModule.readTC_float(qo_vars.tc);
        time_t now;
        time(&now);
        qo_vars.last_poll_time = now;
        vTaskDelay(db_vars.poll_interval_ms / portTICK_PERIOD_MS);
    }
    
}

void read_pulses(void *pvParameters)
{
    (void)pvParameters;

    pcnt_config_t pcntCh1 = {
        .pulse_gpio_num = 36,
        .ctrl_gpio_num = PCNT_PIN_NOT_USED,
        .lctrl_mode = PCNT_MODE_KEEP,
        .hctrl_mode = PCNT_MODE_KEEP,
        .pos_mode = PCNT_COUNT_DIS,
        .neg_mode = PCNT_COUNT_INC,
        .counter_h_lim = 32767,
        .counter_l_lim = -32768,
        .unit = PCNT_UNIT_0,
        .channel = PCNT_CHANNEL_0,
    };
    pinMode(26, OUTPUT);
    Serial.begin(115200);
    Serial.print("Calling unit_config: ");
    Serial.println(pcnt_unit_config(&pcntCh1));
    pcnt_counter_clear(PCNT_UNIT_0);

    static int previous_pulse_count = 0;
    static int previous_pulse_time = 0;
    static int temp = 0;

    while (true) {

        for (int i = 0; i < 50; i++) {
            digitalWrite(26, HIGH);
            vTaskDelay(1 / portTICK_PERIOD_MS);
            digitalWrite(26, LOW);
            vTaskDelay(1 / portTICK_PERIOD_MS);
        }


        int16_t counterVal;
        pcnt_get_counter_value(PCNT_UNIT_0, &counterVal);
        Serial.print("Counter Value: ");
        Serial.println(counterVal);

        Serial.print("Time since last pulse: ");
        Serial.println(millis() - previous_pulse_time);

        Serial.print("previous_pulse_count: ");
        Serial.println(previous_pulse_count);

        temp = ((counterVal - previous_pulse_count)*1000)/(millis() - previous_pulse_time);
        Serial.print("temp: ");
        Serial.println(temp);

        if (millis() - previous_pulse_time != 0){
            qo_vars.water_flow_pps = ((counterVal - previous_pulse_count)*1000)/(millis() - previous_pulse_time);
        }
        Serial.print("PPS: ");
        Serial.println(qo_vars.water_flow_pps);

        previous_pulse_count = counterVal;
        previous_pulse_time = millis();

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}