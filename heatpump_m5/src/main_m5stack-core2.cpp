#include <M5Core2.h>
#include <ui.h>
// #include <QuickPID.h>

// #include "m5_core2_hal.h"
// #include "notecard_manager.h"
// #include "yotta_module.h"
// #include "gui_helpers.h"
// #include "var_structs.h"
// #include "rtos_tasks.h"


// #define YOTTA_MODULE_ID 0
// #define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)

// #define NC_SYNC true
// #define NC_MODE "continuous"
// #define NC_INBOUND 1
// #define NC_OUTBOUND 1
// #define NC_UID "dwt.ac.uk.heatpump"

// #define FLOAT_DECIMALS 1


// NotecardManager notecardManager;
// YottaModule yottaModule(YOTTA_MODULE_ID);

// uint32_t currentMs = millis();

// db_variables_t db_vars;
// qo_variables_t qo_vars;
// env_variables_t env_vars;

// bool nc_service_enable = false;
// bool nc_service_tick = false;

// QuickPID compressorPID(
//     &qo_vars.tc[0],             //Input
//     &qo_vars.compressor_speed,  //Output
//     &db_vars.setpoint          //Setpoint
// );   


// char buffer[64];

void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.
    // M5.begin(true, true, true, true, kMBusModeOutput);  //Init M5Core2.
    M5.Lcd.print("Hello World");

    // hal_setup();

    // // Start the display before notecard etc
    // lv_timer_handler();

    // notecardManager.init(NC_UID, NC_MODE, NC_INBOUND, NC_OUTBOUND, NC_SYNC);
    // yottaModule.init();

    // compressorPID.SetTunings(env_vars.kp, env_vars.ki, env_vars.kd);
    // compressorPID.SetMode(1); //Automatic mode
    // compressorPID.SetSampleTimeUs(100000); // 1 second
    // compressorPID.SetOutputLimits(env_vars.comp_speed_min, env_vars.comp_speed_max);
    // compressorPID.Reset(); //Sometimes outputSum is not initialised to zero otherwise

    // setup_gui_timers();
    // setup_rtos_tasks();

    Serial.println( "Setup done" );
}

void loop(){
    lv_task_handler();
// Nothing here. All the work is done in the RTOS tasks
}






