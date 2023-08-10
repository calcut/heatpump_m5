#ifndef NOTECARD_MANAGER_H
#define NOTECARD_MANAGER_H

#include <Arduino.h>
#include <Notecard.h>
#include "NotecardEnvVarManager.h"
#include <ArduinoJson.h>

// A struct to cache the values of environment variables.
typedef struct {
    char serial_number[32];
    char string_a[16] = "example_string";
    int mode = 0;
    float set_point = 20.0;
    float comp_speed_max = 100.0;
    float comp_speed_min = 0.0;
    float fan_speed_max = 100.0;
    float fan_speed_min = 0.0;
    float pump_speed_max = 100.0;
    float pump_speed_min = 0.0;

} EnvVarCache;


void envVarManagerCb(const char *var, const char *val, void *userCtx);


class NotecardManager {

    private:
        Notecard notecard;
        NotecardEnvVarManager *envVarManager = NULL;
        uint32_t env_modified_time = 0;
        
    public:
        NotecardManager();
        void init(const char *uid, const char *mode, int inbound, int outbound, bool sync);
        void cardStatus();
        void cardWireless();
        void getEnvironment();
        void setDefaultEnvironment();
        void service();
        void getTime();
        EnvVarCache envVarCache;
        bool connected;
        int bars;
        int epoch_time = 0;
        int utc_offset_minutes = 0;


};
#endif