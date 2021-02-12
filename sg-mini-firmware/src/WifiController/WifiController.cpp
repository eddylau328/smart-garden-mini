#include "WifiController.h"
#include <Arduino.h>

void WifiController::init() {
  WifiConnect::disconnect();

  // set event listener
  WiFi.onEvent(WifiConnect::handleConnect, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WifiScan::handleScanNetworks, SYSTEM_EVENT_SCAN_DONE);
}

void WifiController::mainLoop() {
  WifiScan::mainLoop();
}