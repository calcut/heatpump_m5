#include <M5Core2.h>
#include <ui.h>

#include "ui_init.h"

void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.

    tft_lv_initialization();
    init_disp_driver();
    init_touch_driver();
    ui_init();


    M5.Lcd.print("Hello World");


    Serial.println( "Setup done" );
}

void loop(){
    lv_task_handler();
// Nothing here. All the work is done in the RTOS tasks
}






