#include <M5Core2.h>
#include "lv_conf.h"
#include <lvgl.h>
#include <ui.h>

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

NotecardManager notecardManager;
YottaModule yottaModule(YOTTA_MODULE_ID);

uint32_t currentMs = millis();

db_variables_t db_vars;
qo_variables_t qo_vars;
env_variables_t env_vars;

int timer_poll = 0;
int timer_nc_service = 0;

char buffer[64];
#define FLOAT_DECIMALS 1

void poll(void);
void notecard_time_sync(void);
void IRAM_ATTR Timer0_ISR(void);

hw_timer_t *Timer0_Cfg = NULL;
void lv_timer_1s(lv_timer_t * timer);



void setup() {
    hal_setup();

    notecardManager.init(NC_UID, NC_MODE, NC_INBOUND, NC_OUTBOUND, NC_SYNC);
    yottaModule.init();

    Timer0_Cfg = timerBegin(0, 80, true);
    timerAttachInterrupt(Timer0_Cfg, &Timer0_ISR, true);
    timerAlarmWrite(Timer0_Cfg, 10000, true);
    timerAlarmEnable(Timer0_Cfg);

    static uint32_t user_data = 10;
    lv_timer_t * timer_1s = lv_timer_create(lv_timer_1s, 1000, &user_data);
    Serial.println( "Setup done" );

}

void loop(){

    lv_timer_handler();
    
    poll();
    notecard_time_sync();

    if (lv_scr_act() == ui_Screen3){
        display_notecard_info();
    }
    // hal_loop();
    // M5.update();  //Read the press state of the key. A, B, C


}



void notecard_time_sync(){
  if (millis() - timer_nc_service > db_vars.nc_time_sync_interval_s * 1000) {
    timer_nc_service = millis();

    notecardManager.cardStatus();
    lv_timer_handler();

    if(notecardManager.connected){
        Serial.printf("Notecard time sync\n");

        notecardManager.getTime();
        lv_timer_handler();
        setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    }
    else{
        Serial.printf("Notecard not connected, skipping time sync\n");
    }

  }
}



void poll(){
  if (millis() - timer_poll > db_vars.poll_interval_ms) {
    timer_poll = millis();

    Serial.printf("Polling at %d ms\n", db_vars.poll_interval_ms);
    yottaModule.readTC_float(qo_vars.tc);
    lv_timer_handler();

    time_t now;
    time(&now);
    qo_vars.last_poll_time = now;
    display_sensor_info();
  }
}

void lv_timer_1s(lv_timer_t * timer)
{
    display_date_time_labels();
}

void IRAM_ATTR Timer0_ISR()
{
    //hardware timer interrupt
    //currently not used
}

