#ifndef RTC_HELPERS_H
#define RTC_HELPERS_H

#include <M5Core2.h>
#include <ui.h>

//To set the system time from the on-board RTC chip
void setSystemTime();

//To set the on-board RTC chip from time obtained by notecard
void setRTC(time_t epoch_time, int UTC_offset_minutes);

//Get Time from system, then update the label on the display
void updateDateLabel();

#endif