#include "src/Config/Config.h"
#include "src/LcdDisplayUI/LcdDisplayUI.h"
#include "src/LcdDisplayUI/PageControl.h"
#include "src/Sensors/Sensors.h"
#include "src/LcdDisplayUI/RotaryEncoder.h"
#include "src/WifiController/WifiController.h"
#include "src/WaterController/WaterController.h"
#include "src/DeviceSetting/DeviceManager.h"
#include "src/Storage/Storage.h"


LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);


//---------------------------------------SET UP--------------------------------------------------------------------
void init() {
  Storage::init();
  WaterController::init();

  DeviceManager::init();
  WifiController::init();
  Sensors::init();

  pageControl.init();
  pageControl.initInput(&rotaryEncoder);
}


void setup() {
  Serial.begin(9600);
  LOG_SET_LEVEL(DebugLogLevel::ERRORS);
  init();
}

void loop() {
  pageControl.mainLoop();
  display.render();
  Sensors::mainLoop();
  WaterController::mainLoop();
}