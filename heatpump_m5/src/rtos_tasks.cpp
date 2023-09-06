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
        16384, // stack size in bytes
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