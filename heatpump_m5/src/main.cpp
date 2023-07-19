#include <M5Core2.h>
#include <lvgl.h>
#include <Preferences.h>

#include "ArduinoRS485.h"
#include "notecard_manager.h"
#include "yotta_module.h"

#undef min // conflicts with ReactESP
#include <ReactESP.h>

#define LV_HOR_RES_MAX 320
#define LV_VER_RES_MAX 240

#define RX_PIN_RS485 13
#define TX_PIN_RS485 14
#define YOTTA_MODULE_ID 0
#define YOTTA_POLL_INTERVAL_MS (1 * 1000)
#define NOTECARD_FETCH_INTERVAL_MS (20 * 1000)

using namespace reactesp;

// config store.
Preferences preferences;

#include "hw_brightness.h"
#include "ui_init.h"
#include "ui_gestures.h"
#include "ui_theme.h"
#include "ui_screens.h"
#include "ui_settings.h"
// #include "ui_clock.h"
#include "ui_about.h"
#include "ui_reboot.h"


ReactESP app;


RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, -1, -1);

uint32_t lastPollMs = 0;
unsigned long last_ui_upd = 0;

lv_updatable_screen_t* screens[] = {

  // &windScreen,
  // &heelScreen,
  // &rudderScreen,
  // &engineScreen,
  // &autopilotScreen,
#ifdef ENABLE_MPD  // TODO:
  &playerScreen,
#endif
  // &victronScreen,
  // &tanksScreen,
  // &vesselScreen,
  &rebootScreen,
  &aboutScreen,
  // &devStatusScreen,
  // &clockScreen,
  // &compassScreen,
  // &tripDataScreen,
  // &weatherScreen,
  // &gpsScreen,
  // &speedScreen,
  // &depthScreen,
};

int page = 0;
int pages_count = sizeof(screens) / sizeof(screens[0]);

void next_page() {
  lv_obj_clean(screens[page]->screen);
  page++;
  if (page >= pages_count) page = 0;
  init_screen(*screens[page]);
  lv_scr_load(screens[page]->screen);
}

void prev_page() {
  lv_obj_clean(screens[page]->screen);
  page--;
  if (page < 0) page = pages_count - 1;
  init_screen(*screens[page]);
  lv_scr_load(screens[page]->screen);
}

bool handle_swipe() {
  if (swipe_vert_detected()) {
    toggle_ui_theme();
    return true;
  } else if (swipe_right_detected()) {
    next_page();
    return true;
  } else if (swipe_left_detected()) {
    prev_page();
    return true;
  }
  return false;
}


void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.
    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT
    M5.Lcd.fillScreen(WHITE);



    M5.Lcd.setCursor(
        10, 10);  //Move the cursor position to (x,y).
    M5.Lcd.setTextColor(
        WHITE);  //Set the font color to white.
    M5.Lcd.setTextSize(1);  //Set the font size.
    // M5.Lcd.printf(
    //     "Display Test!");  //Serial output format string.
    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    init_theme();
    init_aboutScreen();
    init_rebootScreen();

    page = 0;
    init_screen(*screens[page]);
    lv_scr_load(screens[page]->screen);

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
    lv_task_handler();
    app.tick();
    lv_tick_inc(1);

    bool detected = handle_swipe();
      if (detected || (millis() - last_ui_upd > 300)){
        // derive_data();
        update_screen(*screens[page]);
        last_ui_upd = millis();
      }

}