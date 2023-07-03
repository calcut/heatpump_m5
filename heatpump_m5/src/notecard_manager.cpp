#include "notecard_manager.h"

const char *envVars[] = {
    "variable_a",
    "variable_b",
    "variable_c"
};
static const size_t numEnvVars = sizeof(envVars) / sizeof(envVars[0]);

void envVarManagerCb(const char *var, const char *val, void *userCtx)
{
    // Cast the userCtx to the appropriate type.
    EnvVarCache *cache = (EnvVarCache *)userCtx;

    Serial.print("\nCallback received variable \"");
    Serial.print(var);
    Serial.print("\" with value \"");
    Serial.print(val);
    Serial.print("\" and context 0x");
    Serial.print((unsigned long)userCtx, HEX);
    Serial.println(".");

    // Cache the values for each variable.
    if (strcmp(var, "variable_a") == 0) {
        strlcpy(cache->valueA, val, sizeof(cache->valueA));
    }
    else if (strcmp(var, "variable_b") == 0) {
        strlcpy(cache->valueB, val, sizeof(cache->valueB));
    }
    else if (strcmp(var, "variable_c") == 0) {
        strlcpy(cache->valueC, val, sizeof(cache->valueC));
    }

    Serial.println("Cached values:");
    Serial.print("- variable_a has value ");
    Serial.println(cache->valueA);
    Serial.print("- variable_b has value ");
    Serial.println(cache->valueB);
    Serial.print("- variable_c has value ");
    Serial.println(cache->valueC);
}

NotecardManager::NotecardManager(){
    
    notecard.begin(NOTE_I2C_ADDR_DEFAULT, NOTE_I2C_MAX_DEFAULT, Wire1);
    notecard.setDebugOutputStream(Serial);

    envVarManager = NotecardEnvVarManager_alloc();
    if (envVarManager == NULL) {
        // Handle failed allocation.
        Serial.println("Failed to allocate NotecardEnvVarManager.");
        }
    if (NotecardEnvVarManager_setEnvVarCb(envVarManager, envVarManagerCb, &envVarCache) != NEVM_SUCCESS)
    {
    Serial.println("Failed to set callback for NotecardEnvVarManager.");
    }


    // envVarManager.setEnvVar("test", "test");
    // envVarManager.getEnvVar("test");
}



void NotecardManager::hubSet(){
    J *req = notecard.newRequest("hub.set");
    if (req) {
        JAddStringToObject(req, "product", productUID);
        JAddStringToObject(req, "mode", "continuous");
        JAddBoolToObject(req, "sync", true);
        if (!notecard.sendRequest(req)) {
            notecard.logDebug("FATAL: Failed to configure Notecard!\n");
            Serial.println("FATAL: Failed to configure Notecard!");
            while(1);
        }
    }
}

void NotecardManager::cardStatus(){
    char status[20];
        if (J *req = notecard.newRequest("card.status")) {
            J *rsp = notecard.requestAndResponse(req);
            notecard.logDebug(JConvertToJSONString(rsp));

            bool connected = JGetBool(rsp, "connected");
            char *tempStatus = JGetString(rsp, "status");
            strlcpy(status, tempStatus, sizeof(status));
            int storage = JGetInt(rsp, "storage");
            int time = JGetInt(rsp, "time");
            bool cell = JGetBool(rsp, "cell");

            Serial.printf("status: %s\n", status);

            notecard.deleteResponse(rsp);
        }
}


void NotecardManager::service(int fetch_interval_ms){
    currentMs = millis();
    if (currentMs - lastFetchMs >= fetch_interval_ms) {
        lastFetchMs = currentMs;
        
        notecard.logDebug("Fetch interval lapsed. Fetching environment "
        "variables...\n");
        if (NotecardEnvVarManager_fetch(envVarManager, envVars, numEnvVars)
            != NEVM_SUCCESS) {
            Serial.println("NotecardEnvVarManager_fetch failed.");
        }
        }
}