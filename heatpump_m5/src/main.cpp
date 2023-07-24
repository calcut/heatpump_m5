#include <M5Core2.h>
#include <lvgl.h>
#include <ui.h>

#include "ui_init.h"
#include "ArduinoRS485.h"
#include "notecard_manager.h"
#include "yotta_module.h"

#define RX_PIN_RS485 13
#define TX_PIN_RS485 14
#define YOTTA_MODULE_ID 0
#define YOTTA_POLL_INTERVAL_MS (1 * 1000)
#define NOTECARD_FETCH_INTERVAL_MS (20 * 1000)
#define productUID "dwt.ac.uk.heatpump"

#undef min // conflicts with ReactESP
#include <ReactESP.h>
using namespace reactesp;
ReactESP app;

RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, -1, -1);
NotecardManager notecardManager;
YottaModule yottaModule(YOTTA_MODULE_ID);

uint32_t currentMs = millis();
uint32_t last_modbus_poll = 0;


void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.
    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT

    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    ui_init();

    notecardManager.hubSet();
    yottaModule.getModuleName();

    Serial.println( "Setup done" );
}

void loop(){ 

    M5.update();  //Read the press state of the key. A, B, C

    notecardManager.service(NOTECARD_FETCH_INTERVAL_MS);

    currentMs = millis();
    if (currentMs - last_modbus_poll >= YOTTA_POLL_INTERVAL_MS) {
      last_modbus_poll = currentMs;

      float_t tc[8];
      yottaModule.readTC_float(tc);
    }
    
    lv_task_handler();
    app.tick();
    currentMs = millis();


}