#include "WifiController.h"
#include <Arduino.h>

void WifiController::init() {
  WiFi.disconnect(true);

  // set event listener
  WiFi.onEvent(WifiController::handleConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WifiScan::handleScanNetworks, SYSTEM_EVENT_SCAN_DONE);
}

void WifiController::connect(char *ssid, char *password) {
  WiFi.disconnect(true);
  WiFi.begin(ssid, password);
}

void WifiController::handleConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  LOG_WARNING("Connected to Access Point");
}

void WifiController::mainLoop() {
  WifiScan::mainLoop();
}