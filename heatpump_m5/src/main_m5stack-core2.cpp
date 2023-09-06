#include <M5Core2.h>
#include <lvgl.h>
#include <ui.h>
#include <QuickPID.h>

#include "lv_conf.h"
#include "m5_core2_hal.h"
#include "notecard_manager.h"
#include "yotta_module.h"
#include "rtc_helpers.h"
#include "gui_helpers.h"
#include "var_structs.h"


#define YOTTA_MODULE_ID 0
#define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)

#define NC_SYNC true
#define NC_MODE "continuous"
#define NC_INBOUND 1
#define NC_OUTBOUND 1
#define NC_UID "dwt.ac.uk.heatpump"

#define FLOAT_DECIMALS 1


NotecardManager notecardManager;
YottaModule yottaModule(YOTTA_MODULE_ID);

uint32_t currentMs = millis();

db_variables_t db_vars;
qo_variables_t qo_vars;
env_variables_t env_vars;

// static mutex_t lvgl_mutex;
SemaphoreHandle_t lvgl_mutex;

QuickPID compressorPID(
    &qo_vars.tc[0],             //Input
    &qo_vars.compressor_speed,  //Output
    &db_vars.setpoint          //Setpoint
);   

// int timer_poll = 0;
// int timer_nc_service = 0;

char buffer[64];

void poll(void * pvParameters);
void notecard_time_sync(void * pvParameters);
void control(void * pvParameters);

void setup() {
    hal_setup();


    lvgl_mutex = xSemaphoreCreateMutex();
    // Take the mutex
    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);

    // For Date/Time counter in UI
    lv_timer_t * timer_1s = lv_timer_create(lv_timer_1s, 1000, NULL);


    notecardManager.init(NC_UID, NC_MODE, NC_INBOUND, NC_OUTBOUND, NC_SYNC);
    yottaModule.init();

    compressorPID.SetTunings(env_vars.kp, env_vars.ki, env_vars.kd);
    compressorPID.SetMode(1); //Automatic mode
    compressorPID.SetSampleTimeUs(100000); // 1 second
    compressorPID.SetOutputLimits(env_vars.comp_speed_min, env_vars.comp_speed_max);
    compressorPID.Reset(); //Sometimes outputSum is not initialised to zero otherwise

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

    Serial.println( "Setup done" );

    xTaskCreate(
        display_notecard_info, // task function
        "Notecard Info", // task name
        16384, // stack size in bytes
        NULL, // pointer to parameters
        1, // priority
        NULL); // out pointer to task handle

    xSemaphoreGive(lvgl_mutex);
    Serial.println( "Setup done" );

}

void loop(){

    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    lv_timer_handler();
    xSemaphoreGive(lvgl_mutex);
    
    // notecard_time_sync();

    // M5.update();  //Read the press state of the key. A, B, C. Probably not needed


}


void notecard_time_sync(void * pvParameters){
  while(1) {
    notecardManager.cardStatus();
    // lv_timer_handler();

    if(notecardManager.connected){
        Serial.printf("Notecard time sync\n");

        notecardManager.getTime();
        // lv_timer_handler();
        setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    }
    else{
        Serial.printf("Notecard not connected, skipping time sync\n");
    }
    vTaskDelay(db_vars.nc_time_sync_interval_s*1000 / portTICK_PERIOD_MS);

  }
}

void control(void * pvParameters){
    while(1){
        compressorPID.Compute();

        if (lv_scr_act() == ui_Screen4){
            display_pid_info();
        }
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
        display_sensor_info();
        vTaskDelay(db_vars.poll_interval_ms / portTICK_PERIOD_MS);
    }
    
}

