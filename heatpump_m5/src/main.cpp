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

// 5 second timeout for retrying the hub.set request.
#define HUB_SET_RETRY_SECONDS 5
// Fetch every 20 seconds.
#define FETCH_INTERVAL_MS (20 * 1000)

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
    Serial.println(envVarCache.valueA);
    Serial.print("- variable_b has value ");
    Serial.println(envVarCache.valueB);
    Serial.print("- variable_c has value ");
    Serial.println(envVarCache.valueC);
}

Notecard notecard;
NotecardEnvVarManager *manager = NotecardEnvVarManager_alloc();
uint32_t lastFetchMs = 0;
EnvVarCache envVarCache;

#define productUID "com.your-company.your-name:your_product"

/* After M5Core2 is started or reset
the program in the setUp () function will be run, and this part will only be run once.
在 M5Core2 启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup() {
  M5.begin();                //Init M5Core2.  初始化 M5Core2


  // Notecard with I2C
  notecard.begin();

  J *req = notecard.newRequest("hub.set");
    if (req) {
        JAddStringToObject(req, "product", productUID);
        JAddStringToObject(req, "mode", "continuous");
        JAddBoolToObject(req, "sync", true);
        if (!notecard.sendRequest(req)) {
            notecard.logDebug("FATAL: Failed to configure Notecard!\n");
            while(1);
        }
    }


  M5.Lcd.fillScreen(WHITE);  // Set the screen background.  设置屏幕底色为白色
  delay(500);                //Delay 500ms.  延迟500ms
  M5.Lcd.fillScreen(RED);
  delay(500);
  M5.Lcd.fillScreen(GREEN);
  delay(500);
  M5.Lcd.fillScreen(BLUE);
  delay(500);
  M5.Lcd.fillScreen(BLACK);
  delay(500);

  M5.Lcd.setCursor(
      10, 10);  //Move the cursor position to (x,y).  移动光标位置到 (x,y)处
  M5.Lcd.setTextColor(
      WHITE);  //Set the font color to white.  设置字体颜色为白色
  M5.Lcd.setTextSize(1);  //Set the font size.  设置字体大小
  M5.Lcd.printf(
      "Display Test!");  //Serial output format string.  输出格式化字符串

  // draw graphic
  delay(1000);
  M5.Lcd.drawRect(100, 100, 50, 50,
                  BLUE);  //Draw a 50x50 blue rectangle wireframe at (x,y).
  delay(1000);  //在（x,y）处画 长宽为50x50的蓝色矩形线框
  M5.Lcd.fillRect(100, 100, 50, 50,
                  BLUE);  //Draw a blue rectangle 50x50 at (x,y)
  delay(1000);            //在（x,y）处画 长宽为50x50的蓝色矩形
  M5.Lcd.drawCircle(100, 100, 50,
                    RED);  //Draw a red circle of radius 50 at (x,y)
  delay(1000);             //在（x,y）处画 半径为50的红色圆线圈
  M5.Lcd.fillCircle(100, 100, 50,
                    RED);  //Draw a red circle of radius 50 at (x,y)
  delay(1000);             //在（x,y）处画 半径为50的红色圆
  M5.Lcd.drawTriangle(
      30, 30, 180, 100, 80, 150,
      YELLOW);  //Make a triangle wireframe with (x1,y1) (x2,y2) (x3,y3) as the vertices
  delay(1000);  //以 (x1,y1) (x2,y2) (x3,y3)为顶点作三角形线框
  M5.Lcd.fillTriangle(30, 30, 180, 100, 80, 150,
                      YELLOW);  //以 (x1,y1) (x2,y2) (x3,y3)为顶点作三角形
}  // Construct a triangle with (x1,y1) (x2,y2) (x3,y3) as its vertices

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
在setup()函数中的程序执行完后，会接着执行loop()函数中的程序
loop()函数是一个死循环，其中的程序会不断的重复运行 */
void loop() {
  M5.Lcd.fillTriangle(random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                      random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                      random(M5.Lcd.width() - 1), random(M5.Lcd.height() - 1),
                      random(0xfffe));

  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(
        WHITE);  // Clear the screen and set white to the background color.  清空屏幕并将白色设置为底色
    M5.Lcd.setCursor(0, 0);
  }

    M5.update();  //Read the press state of the key.  读取按键 A, B, C 的状态

    // Fetch the environment variables every FETCH_INTERVAL_MS milliseconds.
    unsigned long currentMs = millis();
    if (currentMs - lastFetchMs >= FETCH_INTERVAL_MS) {
        lastFetchMs = currentMs;
        notecard.logDebug("Fetch interval lapsed. Fetching environment "
        "variables...\n");
        if (NotecardEnvVarManager_fetch(manager, envVars, numEnvVars)
            != NEVM_SUCCESS) {
            Serial.println("NotecardEnvVarManager_fetch failed.");
        }
    }
}