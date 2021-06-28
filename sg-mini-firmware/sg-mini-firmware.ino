#include "src/Config/Config.h"
#include "src/LcdDisplayUI/LcdDisplayUI.h"
#include "src/LcdDisplayUI/PageControl.h"
#include "src/Sensors/Sensors.h"
#include "src/LcdDisplayUI/RotaryEncoder.h"
#include "src/WifiController/WifiController.h"
#include "src/DataTransmitter/TransmitterController.h"
#include "src/DataTransmitter/MqttTransmitter/MqttTransmitter.h"
#include "src/WaterController/WaterController.h"
#include "src/DeviceSetting/DeviceManager.h"
#include "src/Storage/Storage.h"


LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);

unsigned long lastSend;


void init() {
  Storage::init();
  WaterController::init();

  DeviceManager::init();
  WifiController::init();
  Sensors::init();

  TransmitterController::init();

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

  // if (millis() - lastSend > 5000) {
  //   transmitter.send(TransmitAction::SendAction::SensorData);
  //   lastSend = millis();
  // }
}
