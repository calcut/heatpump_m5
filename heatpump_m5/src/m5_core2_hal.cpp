
#include "m5_core2_hal.h"

#include <M5Core2.h>
#include <lvgl.h>
// #include <ui.h>
#include <ArduinoRS485.h>

#include "ui_init.h"
#include "rtc_helpers.h"

#define RX_PIN_RS485 13
#define TX_PIN_RS485 14
#define DE_PIN_RS485 25



RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, DE_PIN_RS485, -1);


void hal_setup() {
    // M5.begin(true, true, true, true, kMBusModeOutput);  //Init M5Core2.
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.


    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT

    setSystemTime(); //from RTC chip

    // pinMode(DE_PIN_RS485, OUTPUT);
    // digitalWrite(DE_PIN_RS485, HIGH);

    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    ui_init();


    Serial.println( "HAL Setup done" );

}

void hal_loop(){ 

    // M5.update();  //Read the press state of the key. A, B, C
    // lv_task_handler();
    // lv_timer_handler();
    // lv_task_handler();



}