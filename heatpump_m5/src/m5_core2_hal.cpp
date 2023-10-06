
#include "m5_core2_hal.h"

#include <M5Core2.h>
#include <lvgl.h>
#include <ArduinoRS485.h>

#include "ui_init.h"
#include "rtc_helpers.h"


RS485Class RS485(Serial2, PIN_RX_RS485, PIN_TX_RS485, PIN_DE_RS485, -1);


void hal_setup() {
    // M5.begin(true, true, true, true, kMBusModeOutput);  //Init M5Core2.
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.


    Wire1.begin(PIN_SDA_I2C_SYS, PIN_SCL_I2C_SYS, 400000);  //Init I2C_SYS
    Wire.begin(PIN_SDA_I2C_EXT, PIN_SCL_I2C_EXT, 400000);  //Init I2C_EXT

    setSystemTime(); //from RTC chip

    // pinMode(DE_PIN_RS485, OUTPUT);
    // digitalWrite(DE_PIN_RS485, HIGH);

    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    ui_init();


    Serial.println( "HAL Setup done" );

}