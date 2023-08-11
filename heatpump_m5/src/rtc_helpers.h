#include <M5Core2.h>
#include <ui.h>

RTC_TimeTypeDef TimeStruct;
RTC_DateTypeDef DateStruct;

void setSystemTime(){
    //To set the system time from the on-board RTC chip

    struct tm time_info;
    M5.Rtc.GetTime(&TimeStruct);
    M5.Rtc.GetDate(&DateStruct);

    time_info.tm_hour = TimeStruct.Hours;
    time_info.tm_min = TimeStruct.Minutes;
    time_info.tm_sec = TimeStruct.Seconds;
    time_info.tm_wday = DateStruct.WeekDay;
    time_info.tm_mon = DateStruct.Month - 1;
    time_info.tm_mday = DateStruct.Date;
    time_info.tm_year = DateStruct.Year - 1900;

    struct timeval tv;
    tv.tv_sec = mktime(&time_info);
    Serial.printf("Setting time to %ld\n", tv.tv_sec);
    Serial.printf("Setting time to %02d:%02d:%02d\n", TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
    settimeofday(&tv, NULL);
}

void setRTC(time_t epoch_time, int UTC_offset_minutes){
    //To set the on-board RTC chip from time obtained by notecard
    struct tm *time_info;

    epoch_time += UTC_offset_minutes * 60;
    time_info = localtime(&epoch_time);
    
    TimeStruct.Hours   = time_info->tm_hour;
    TimeStruct.Minutes = time_info->tm_min;
    TimeStruct.Seconds = time_info->tm_sec;
    M5.Rtc.SetTime(&TimeStruct);

    DateStruct.WeekDay = time_info->tm_wday;
    DateStruct.Month = time_info->tm_mon + 1;
    DateStruct.Date = time_info->tm_mday;
    DateStruct.Year = time_info->tm_year + 1900;
    M5.Rtc.SetDate(&DateStruct);

    setSystemTime();
}

void updateDateLabel(){
    //Get Time from system, then update the label on the display
    time_t now;
    struct tm *time_info;
    char time_str[64];

    time(&now);
    time_info = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %X", time_info);
    lv_label_set_text(ui_Header_Time, time_str);
}