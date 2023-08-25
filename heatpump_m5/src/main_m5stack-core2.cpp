#include <M5Core2.h>
#include "lv_conf.h"
#include <lvgl.h>
#include <ui.h>

#include "m5_core2_hal.h"
#include "notecard_manager.h"
#include "yotta_module.h"
#include "rtc_helpers.h"
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
int timer_nc_info = 0;

char buffer[64];
#define FLOAT_DECIMALS 1

void poll(void);
void notecard_time_sync(void);
void display_notecard_info(void);
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

void display_notecard_info(){
    if (millis() - timer_nc_info > db_vars.nc_info_interval_s * 1000) {
        timer_nc_info = millis();

        Serial.printf("Notecard info poll\n");
        lv_obj_add_state(ui_Button3_Refresh, LV_STATE_CHECKED);
        lv_obj_clear_state(ui_Button3_Refresh, LV_STATE_DISABLED);

    
        if(notecardManager.connected){
            lv_label_set_text(ui_LabelConnected, "Connected: Yes");
        }
        else{
            lv_label_set_text(ui_LabelConnected, "Connected: No");
        }
        notecardManager.hubGet();
        lv_timer_handler();
        notecardManager.cardStatus();
        lv_timer_handler();
        notecardManager.getEnvironment();
        lv_timer_handler();
        notecardManager.hubStatus();
        lv_timer_handler();
        notecardManager.hubSyncStatus();
        lv_timer_handler();
        notecardManager.cardWireless();
        lv_timer_handler();


        sprintf(buffer, "UID: %s", notecardManager.deviceUID);
        lv_label_set_text(ui_LabelDevice, buffer);
        
        sprintf(buffer, "SN: %s", notecardManager.sn);
        lv_label_set_text(ui_LabelSerial, buffer);

        sprintf(buffer, "RSSI: %d dB", notecardManager.rssi);
        lv_label_set_text(ui_LabelRSSI, buffer);

        sprintf(buffer, "RAT: %s", notecardManager.rat);
        lv_label_set_text(ui_LabelRat, buffer);

        sprintf(buffer, "Band: %s", notecardManager.band);
        lv_label_set_text(ui_LabelBand, buffer);

        // fill in ui_BarX depending on reported bars
        if (notecardManager.bars > 0){
            lv_bar_set_value(ui_Bar1, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 1){
            lv_bar_set_value(ui_Bar2, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 2){
            lv_bar_set_value(ui_Bar3, 100, LV_ANIM_OFF);
        };
        if (notecardManager.bars > 3){
            lv_bar_set_value(ui_Bar4, 100, LV_ANIM_OFF);
        };

        lv_textarea_set_text(ui_TextAreaHubStatus, notecardManager.hub_status);
        lv_textarea_set_text(ui_TextAreaSyncStatus, notecardManager.hub_sync_status);
        lv_obj_clear_state(ui_Button3_Refresh, LV_STATE_CHECKED);
        lv_obj_add_state(ui_Button3_Refresh, LV_STATE_DISABLED);
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
    // dtostrf(qo_vars.tc[0], 0, FLOAT_DECIMALS, buffer);
    // lv_label_set_text(ui_Label_Celsius, buffer);


    lv_obj_t *tc_values[8] = {
        ui_Label2_value1,
        ui_Label2_value2,
        ui_Label2_value3,
        ui_Label2_value4,
        ui_Label2_value5,
        ui_Label2_value6
    };

    lv_obj_t *pr_values[8] = {
        ui_Label2_value7,
        ui_Label2_value8
    };

    lv_obj_t *tc_bars[8] = {
        ui_Bar2_value1,
        ui_Bar2_value2,
        ui_Bar2_value3,
        ui_Bar2_value4,
        ui_Bar2_value5,
        ui_Bar2_value6
    };

    lv_obj_t *pr_bars[8] = {
        ui_Bar2_value7,
        ui_Bar2_value8
    };

    // loop over all ui_Label2_valueX objects and update with new values
    for (int i = 0; i < 6; i++){
        sprintf(buffer, "%0.1f °C", qo_vars.tc[i]);
        // dtostrf(qo_vars.tc[i], 0, FLOAT_DECIMALS, buffer);
        lv_label_set_text(tc_values[i], buffer);
        lv_bar_set_value(tc_bars[i], qo_vars.tc[i], LV_ANIM_OFF);
    }

  }
}

void lv_timer_1s(lv_timer_t * timer)
{
    updateDateTimeLabels();
}

void IRAM_ATTR Timer0_ISR()
{
    // lv_timer_handler();
    // digitalWrite(LED, !digitalRead(LED));
  // updateDateLabel();
}

