#include "WifiController.h"
#include <Arduino.h>

unsigned long WifiController::lastActionCheck;
bool WifiController::isScanNetwork = false;
uint8_t WifiController::rescanNetworkCount = 0;
int WifiController::scanNetworkCount = 0;

void WifiController::init() {
  WiFi.disconnect(true);

  // set event listener
  WiFi.onEvent(WifiController::handleConnected, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WifiController::handleScanNetworks, SYSTEM_EVENT_SCAN_DONE);
}

void WifiController::connect(char *ssid, char *password) {
  WiFi.disconnect(true);
  WiFi.begin(ssid, password);
}

void WifiController::startScanNetwork(uint8_t rescanCount) {
  isScanNetwork = true;
  rescanNetworkCount = rescanCount;
}

void WifiController::stopScanNetwork() {
  isScanNetwork = false;
  rescanNetworkCount = 0;
}


/* Private Methods */
void WifiController::scanNetworks() {
  scanNetworkCount = WiFi.scanNetworks();
}

void WifiController::handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info) {
  initializeNetworks(scanNetworkCount);
  LOG_WARNING("Finish scan network");
  if (getNetworkCount() == 0)
    LOG_WARNING("No networks found");
  else
    for (int i = 0 ; i < getNetworkCount(); i++)
      setNetwork(WiFi.SSID(i), i);
}

void WifiController::handleConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  LOG_WARNING("Connected to Access Point");
}

void WifiController::mainLoop() {
  if (millis() - lastActionCheck > 2000) {
    if (isScanNetwork) {
      scanNetworks();
      rescanNetworkCount--;
      if (rescanNetworkCount <= 0)
        isScanNetwork = false;
    }
    lastActionCheck = millis();
  }
}