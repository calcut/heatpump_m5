#ifndef NOTECARD_MANAGER_H
#define NOTECARD_MANAGER_H

#include <Arduino.h>
#include <Notecard.h>
#include "NotecardEnvVarManager.h"

// 5 second timeout for retrying the hub.set request.
#define HUB_SET_RETRY_SECONDS 5
// Fetch every 20 seconds.
#define FETCH_INTERVAL_MS (10 * 1000)

#define productUID "dwt.ac.uk.heatpump"

// A struct to cache the values of environment variables.
typedef struct {
    char valueA[16];
    char valueB[16];
    char valueC[16];
} EnvVarCache;

void envVarManagerCb(const char *var, const char *val, void *userCtx);

class NotecardManager {

    private:
        EnvVarCache envVarCache;
        Notecard notecard;
        NotecardEnvVarManager *envVarManager = NULL;
        uint32_t lastFetchMs = 0;
        uint32_t currentMs = millis();

    public:
        NotecardManager();
        void hubSet();
        void cardStatus();
        void service(int fetch_interval_ms);
};
#endif