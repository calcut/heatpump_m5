#include <M5Core2.h>
#include <lvgl.h>
#include <ui.h>

#include "m5_core2_hal.h"
#include "notecard_manager.h"
#include "yotta_module.h"
#include "rtc_helpers.h"
#include "var_structs.h"


#define YOTTA_MODULE_ID 0
#define YOTTA_POLL_INTERVAL_MS (10 * 1000)
#define NOTECARD_FETCH_INTERVAL_MS (10 * 1000)

#define NC_SYNC true
#define NC_MODE "continuous"
#define NC_INBOUND 1
#define NC_OUTBOUND 1
#define NC_UID "dwt.ac.uk.heatpump"

#undef min // conflicts with ReactESP
#include <ReactESP.h>
using namespace reactesp;
ReactESP app;

NotecardManager notecardManager;
YottaModule yottaModule(YOTTA_MODULE_ID);

uint32_t currentMs = millis();
uint32_t poll_interval = YOTTA_POLL_INTERVAL_MS;

db_variables_t db_vars;
qo_variables_t qo_vars;
env_variables_t env_vars;


void setup() {
  hal_setup();

  notecardManager.init(NC_UID, NC_MODE, NC_INBOUND, NC_OUTBOUND, NC_SYNC);
  yottaModule.init();


  app.onRepeat(poll_interval, []() {
    yottaModule.readTC_float(qo_vars.tc);

  });

  app.onRepeat(1000, []() {
      updateDateLabel();
  });

  app.onRepeat(NOTECARD_FETCH_INTERVAL_MS, []() {
    notecardManager.service();
    if(notecardManager.connected){
      char bars_str[10];
      sprintf(bars_str, "bars: %d", notecardManager.bars);
      lv_label_set_text(ui_Header_Date, bars_str);
      setRTC(notecardManager.epoch_time, notecardManager.utc_offset_minutes);
    }
    else{
      lv_label_set_text(ui_Header_Date,"Disconnected");
    }
  });
  Serial.println( "Setup done" );

}

void loop(){ 
  hal_loop();
  app.tick();

}