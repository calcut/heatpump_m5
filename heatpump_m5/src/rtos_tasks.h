#ifndef RTOS_TASKS_H
#define RTOS_TASKS_H

#include <M5Core2.h>
#include <QuickPID.h>
#include <lvgl.h>

#include "rtc_helpers.h"
#include "yotta_module.h"
#include "notecard_manager.h"
#include "var_structs.h"

extern YottaModule yottaModule;
extern NotecardManager notecardManager;
extern QuickPID compressorPID;
extern db_variables_t db_vars;
extern qo_variables_t qo_vars;
extern env_variables_t env_vars;

extern bool nc_service_enable;
extern bool nc_service_tick;

void setup_rtos_tasks(void);

void poll(void * pvParameters);
void notecard_time_sync(void * pvParameters);
void notecard_service(void * pvParameters);
void control(void * pvParameters);
void gui_service(void * pvParameters);


#endif