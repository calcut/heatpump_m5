/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5Core2 sample source code
*                          配套  M5Core2 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/core2
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/core2
*
* Describe: Display Example.  显示屏示例
* Date: 2021/7/21
*******************************************************************************
*/
#include <M5Core2.h>
#include <Notecard.h>
#include "NotecardEnvVarManager.h"
// #include "ArduinoModbus.h"
#include "ArduinoRS485.h"

#include "yotta_module.h"

#define productUID "dwt.ac.uk.heatpump"
#define RX_PIN_RS485 13
#define TX_PIN_RS485 14

#define MODULE_NAME_ADDR 211

// 5 second timeout for retrying the hub.set request.
#define HUB_SET_RETRY_SECONDS 5
// Fetch every 20 seconds.
#define FETCH_INTERVAL_MS (5 * 1000)

// A struct to cache the values of environment variables.
typedef struct {
    char valueA[16];
    char valueB[16];
    char valueC[16];
} EnvVarCache;

// These are the environment variables we'll be fetching from the Notecard.
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



Notecard notecard;
NotecardEnvVarManager *manager = NULL;
uint32_t lastFetchMs = 0;
uint32_t currentMs = millis();
EnvVarCache envVarCache;
RS485Class RS485(Serial2, RX_PIN_RS485, TX_PIN_RS485, -1, -1);
uint8_t slave_id = 0;
YottaModule yottaModule(1);

/* After M5Core2 is started or reset
the program in the setUp () function will be run, and this part will only be run once.
在 M5Core2 启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup() {
    M5.begin(true, true, true, true, kMBusModeInput);  //Init M5Core2.  初始化 M5Core2
    Wire1.begin(21, 22, 400000);  //Init I2C_SYS
    Wire.begin(32, 33, 400000);  //Init I2C_EXT

    // ModbusRTUClient.begin(9600, SERIAL_8N1);

    M5.Lcd.fillScreen(BLACK);

    // Notecard with I2C
    notecard.begin(NOTE_I2C_ADDR_DEFAULT, NOTE_I2C_MAX_DEFAULT, Wire1);
    notecard.setDebugOutputStream(Serial);

    manager = NotecardEnvVarManager_alloc();
    if (manager == NULL) {
        // Handle failed allocation.
        Serial.println("Failed to allocate NotecardEnvVarManager.");
        }
    if (NotecardEnvVarManager_setEnvVarCb(manager, envVarManagerCb, &envVarCache) != NEVM_SUCCESS)
    {
    Serial.println("Failed to set callback for NotecardEnvVarManager.");
    }


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




    M5.Lcd.setCursor(
        10, 10);  //Move the cursor position to (x,y).  移动光标位置到 (x,y)处
    M5.Lcd.setTextColor(
        WHITE);  //Set the font color to white.  设置字体颜色为白色
    M5.Lcd.setTextSize(1);  //Set the font size.  设置字体大小
    M5.Lcd.printf(
        "Display Test!");  //Serial output format string.  输出格式化字符串

    yottaModule.getModuleName();


}

void loop(){ 

  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(
        BLACK);  // Clear the screen and set white to the background color.  清空屏幕并将白色设置为底色
    M5.Lcd.setCursor(0, 0);
  }

    M5.update();  //Read the press state of the key.  读取按键 A, B, C 的状态

    // Fetch the environment variables every FETCH_INTERVAL_MS milliseconds.
    currentMs = millis();
    if (currentMs - lastFetchMs >= FETCH_INTERVAL_MS) {
        lastFetchMs = currentMs;

        float_t tc[8];
        yottaModule.readTC_float(tc);

        int32_t tci[8];
        yottaModule.readTC_int_decimal(tci);



        // readTC(tc);
        char status[20];
        // if (J *req = notecard.newRequest("card.status")) {
        //     J *rsp = notecard.requestAndResponse(req);
        //     notecard.logDebug(JConvertToJSONString(rsp));

        //     bool connected = JGetBool(rsp, "connected");
        //     char *tempStatus = JGetString(rsp, "status");
        //     strlcpy(status, tempStatus, sizeof(status));
        //     int storage = JGetInt(rsp, "storage");
        //     int time = JGetInt(rsp, "time");
        //     bool cell = JGetBool(rsp, "cell");

        //     Serial.printf("status: %s\n", status);

        //     notecard.deleteResponse(rsp);
        // }

        // m5.Lcd.println("Fetching environment variables...\n");
        // notecard.logDebug("Fetch interval lapsed. Fetching environment "
        // "variables...\n");
        // if (NotecardEnvVarManager_fetch(manager, envVars, numEnvVars)
        //     != NEVM_SUCCESS) {
        //     Serial.println("NotecardEnvVarManager_fetch failed.");
        // }
    }
}