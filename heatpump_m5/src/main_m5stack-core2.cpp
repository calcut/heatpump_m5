#include <M5Core2.h>
// #include <lvgl.h>
// #include <ui.h>
// #include <ArduinoRS485.h>

#include "m5_core2_hal.h"
// #include "ui_init.h"
// #include "notecard_manager.h"
// #include "yotta_module.h"
// #include "rtc_helpers.h"


// #define RX_PIN_RS485 13
// #define TX_PIN_RS485 14
// #define DE_PIN_RS485 25
// #define YOTTA_MODULE_ID 0
// #define YOTTA_POLL_INTERVAL_MS (10 * 1000)
// #define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)

// #define NC_SYNC true
// #define NC_MODE "continuous"
// #define NC_INBOUND 1
// #define NC_OUTBOUND 1
// #define NC_UID "dwt.ac.uk.heatpump"

// #undef min // conflicts with ReactESP
// #include <ReactESP.h>
// using namespace reactesp;
// ReactESP app;

// RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, DE_PIN_RS485, -1);
// NotecardManager notecardManager;
// YottaModule yottaModule(YOTTA_MODULE_ID);

// uint32_t currentMs = millis();
// uint32_t poll_interval = YOTTA_POLL_INTERVAL_MS;

// float_t tc[8];
// StaticJsonDocument<200> vars;



void setup() {
  hal_setup();
    // // M5.begin(true, true, true, true, kMBusModeOutput);  //Init M5Core2.
    // M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.


    // Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    // Wire.begin(32, 33, 400000);  //Init I2C_EXT

    // setSystemTime(); //from RTC chip

    // // pinMode(DE_PIN_RS485, OUTPUT);
    // // digitalWrite(DE_PIN_RS485, HIGH);

    // tft_lv_initialization();
    // init_disp_driver();
    // init_touch_driver();
    // ui_init();
    // Serial.println( "about to init notecard old version" );

    // notecardManager.init(NC_UID, NC_MODE, NC_INBOUND, NC_OUTBOUND, NC_SYNC);
    // // yottaModule.getModuleName();

    // Serial.println( "Setup done" );

    // app.onRepeat(poll_interval, []() {
    //   yottaModule.readTC_float(tc);

    //   // poll_interval = poll_interval +1000;

    // });




    // app.onRepeat(1000, []() {
    //    updateDateLabel();

    // });

    // app.onRepeat(NOTECARD_FETCH_INTERVAL_MS, []() {
    //   notecardManager.service();
    //   if(notecardManager.connected){
    //     char bars_str[10];
    //     sprintf(bars_str, "bars: %d", notecardManager.bars);
    //     lv_label_set_text(ui_Header_Date, bars_str);
    //     setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    //   }
    //   else{
    //     lv_label_set_text(ui_Header_Date,"Disconnected");
    //   }
    // });


}

void loop(){ 
  hal_loop();

    // M5.update();  //Read the press state of the key. A, B, C
    // lv_task_handler();
    // app.tick();

}