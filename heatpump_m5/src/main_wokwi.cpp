/**
  ESP32s3 adaptation by Tyeth Gundry of Adafruit LvGL Glue example

  Work in progress LVGL simple test. TODO: exciting features/widgets.
  Currently the helloworld demo loads and works, but no touch support

  Takes 105 seconds on a private build server to first build, then
  for a text change takes 29seconds when using empty attr: {} for ESP.
  If you wish you can vary the esp32 core version and try 2.0.7 etc:
        "attrs": { "fastTLS": "1", "builder":"esp32-core-2.0.7" }
  If removed then build max is 60secs for free instead of 90, but they
  take less time (2.0.7 adds many things and slows builds so 90s given)

  On free plan with no attr value I was once able to build with 2 trys
  https://wokwi.com/projects/359264266487565313
 */

/***************************************************
  This uses code written by Limor Fried/Ladyada for Adafruit Industries.
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!
 ****************************************************/

// /*
//   Adafruit LVGL Glue Example for pyportal (uses IL9341)
//   https://github.com/adafruit/Adafruit_LvGL_Glue/blob/master/examples/hello_pyportal/hello_pyportal.ino
// */
///////////////////////////////////

// Minimal "Hello" example for LittlevGL on Adafruit PyPortal. Requires
// LittlevGL, Adafruit_LvGL_Glue, Adafruit Touchscreen, Adafruit_GFX and
// Adafruit_ILI9341 (PyPortal, PyPortal Pynt) or Adafruit_HX8357 (PyPortal
// Titano) libraries. This example doesn't use any touchscreen input, but
// it's declared anyway so this sketch can be copied-and-pasted to serve
// as a starting point for other projects. If display is scrambled, check
// that the correct board is selected -- PyPortal vs PyPortal Titano.

// Prior Adafruit_LvGL_Glue users: see hello_changes example for updates!
#include "Arduino.h"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_LvGL_Glue.h> // Always include this BEFORE lvgl.h!
#include <lvgl.h>
// #include <TouchScreen.h>
#include <Adafruit_ILI9341.h>

////For now touch defined TP_Point occurs in both STMPE610 (in lvgl_GLUE) and FT6206...
// #include <Adafruit_FT6206.h>
// // The FT6206 uses hardware I2C (SCL/SDA)
// Adafruit_FT6206 ctp = Adafruit_FT6206();

// // The display also uses hardware SPI, plus #9 & #10
// #define TFT_CS 10
// #define TFT_DC 9
#define TFT_DC 2
#define TFT_CS 15
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#define TFT_ROTATION   3 // Landscape orientation on PyPortal
#define TFT_D0        34 // PyPortal TFT pins
#define TFT_WR        26
// #define TFT_DC        10
// #define TFT_CS        11
#define TFT_RST       24
#define TFT_RD         9
#define TFT_BACKLIGHT 6 // 25
#define YP            A4 // PyPortal touchscreen pins
#define XP            A5
#define YM            A6
#define XM            A7

// #if defined(ADAFRUIT_PYPORTAL_M4_TITANO)
//   #include <Adafruit_HX8357.h>
//   Adafruit_HX8357  tft(tft8bitbus, TFT_D0, TFT_WR, TFT_DC, TFT_CS, TFT_RST,
//     TFT_RD);
// #else
//   #include <Adafruit_ILI9341.h>
//   Adafruit_ILI9341 tft(tft8bitbus, TFT_D0, TFT_WR, TFT_DC, TFT_CS, TFT_RST,
//     TFT_RD);
// #endif

////Touch should come from i2c chip instead of analog pins(Adafruit_Touchscreen)
//TouchScreen        ts(XP, YP, XM, YM, 300);

Adafruit_LvGL_Glue glue;

// This example sketch's LittlevGL UI-building calls are all in this
// function rather than in setup(), so simple programs can just 
// copy-and-paste this sketch as a starting point, then embellish here:
void lvgl_setup(void) {
  // Create simple label centered on screen
  lv_obj_t *label = lv_label_create(lv_scr_act());
  lv_label_set_text(label, "Hello Adafruit + Wokwi lovers!");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

void setup(void) {
  Serial.begin(115200);

  // Initialize display BEFORE glue setup
  tft.begin();
  tft.setRotation(TFT_ROTATION);
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH);

  // PyPortal touchscreen needs no init

  // Initialize glue, passing in address of display & touchscreen
  LvGLStatus status = glue.begin(&tft, false);//, &ctp);
  if(status != LVGL_OK) {
    Serial.printf("Glue error %d\r\n", (int)status);
    for(;;);
  }
  
  Serial.println("Begun, loading lvgl...");
  lvgl_setup(); // Call UI-building function above
  Serial.println("Done.");
}

void loop(void) {
  lv_task_handler(); // Call LittleVGL task handler periodically
  delay(5);
}