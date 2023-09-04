#ifndef GUI_HELPERS_H
#define GUI_HELPERS_H

#include <M5Core2.h>
#include <lvgl.h>
#include <ui.h>
#include <QuickPID.h>
#include "notecard_manager.h"
#include "var_structs.h"

extern NotecardManager notecardManager;
extern QuickPID compressorPID;
extern db_variables_t db_vars;
extern qo_variables_t qo_vars;
extern env_variables_t env_vars;

void display_notecard_info(void);
void display_sensor_info(void);
void display_pid_info(void);
void display_date_time_labels(void);

//Timer to update date/time on screen
void lv_timer_1s(lv_timer_t * timer);

#endif