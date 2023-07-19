#include <M5Core2.h>
#include "ArduinoRS485.h"
#include "notecard_manager.h"
#include "yotta_module.h"

#define RX_PIN_RS485 13
#define TX_PIN_RS485 14
#define YOTTA_MODULE_ID 0
#define YOTTA_POLL_INTERVAL_MS (1 * 1000)
#define NOTECARD_FETCH_INTERVAL_MS (20 * 1000)



RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, -1, -1);
YottaModule yottaModule(YOTTA_MODULE_ID);
NotecardManager notecardManager;

uint32_t currentMs = millis();
uint32_t lastPollMs = 0;



void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.
    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT
    M5.Lcd.fillScreen(WHITE);

    notecardManager.hubSet();


    M5.Lcd.setCursor(
        10, 10);  //Move the cursor position to (x,y).
    M5.Lcd.setTextColor(
        WHITE);  //Set the font color to white.
    M5.Lcd.setTextSize(1);  //Set the font size.
    // M5.Lcd.printf(
    //     "Display Test!");  //Serial output format string.

    #define buttonWidth 145
    #define buttonHeight 50
    #define buttonRadius 5
    #define rowDelta 55
    #define colDelta 160

    // display size = 320x240
    M5.Lcd.clear(BLACK);
    int col = 0;
    int row = 0;
    for (int i = 0; i < 8; i++) {
        if (i == 4) {
            col = 1;
            row = 0;
        }
        M5.Lcd.drawRoundRect(10 + colDelta*col, 10+rowDelta*row, buttonWidth, buttonHeight, buttonRadius, WHITE);
        row++;
    }

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
    if (currentMs - lastPollMs >= YOTTA_POLL_INTERVAL_MS) {
        lastPollMs = currentMs;

        float_t tc[8];
        yottaModule.readTC_float(tc);

        M5.Lcd.clear(WHITE);
        int col = 0;
        int row = 0;
        for (int i = 0; i < 8; i++) {
            if (i == 4) {
                col = 1;
                row = 0;
            }
            M5.Lcd.setTextColor(RED);
            M5.Lcd.drawRoundRect(10 + colDelta*col, 10+rowDelta*row, buttonWidth, buttonHeight, buttonRadius, WHITE);
            M5.Lcd.setFreeFont(&TomThumb);
            M5.Lcd.setCursor(15 + colDelta*col, 25+rowDelta*row);
            M5.Lcd.printf("TC%d:", i);
            M5.Lcd.setFreeFont(&FreeSans18pt7b);
            M5.Lcd.setCursor(30 + colDelta*col, 45+rowDelta*row);
            M5.Lcd.printf("%.2f", tc[i]);


            row++;
        }

    }
}