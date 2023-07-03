#include <M5Core2.h>

#include "ArduinoRS485.h"

#include "notecard_manager.h"
#include "yotta_module.h"

#define RX_PIN_RS485 13
#define TX_PIN_RS485 14
#define YOTTA_MODULE_ID 0
#define POLL_INTERVAL_MS (5 * 1000)
#define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)



RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, -1, -1);
YottaModule yottaModule(YOTTA_MODULE_ID);
NotecardManager notecardManager;

uint32_t currentMs = millis();
uint32_t lastPollMs = 0;


void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.
    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT

    notecardManager.hubSet();

    M5.Lcd.fillScreen(BLACK);

    M5.Lcd.setCursor(
        10, 10);  //Move the cursor position to (x,y).
    M5.Lcd.setTextColor(
        WHITE);  //Set the font color to white.
    M5.Lcd.setTextSize(1);  //Set the font size.
    M5.Lcd.printf(
        "Display Test!");  //Serial output format string.

    yottaModule.getModuleName();
}

void loop(){ 

  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(
        BLACK);  // Clear the screen and set white to the background color.
    M5.Lcd.setCursor(0, 0);
  }

    M5.update();  //Read the press state of the key. A, B, C
    notecardManager.service(NOTECARD_FETCH_INTERVAL_MS);

    currentMs = millis();
    if (currentMs - lastPollMs >= POLL_INTERVAL_MS) {
        lastPollMs = currentMs;

        float_t tc[8];
        yottaModule.readTC_float(tc);

    }
}