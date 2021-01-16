#include "WifiController.h"

int WifiController::networkCount = 0;
String WifiController::ssids;

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

void WifiController::scanNetworks() {
  networkCount = WiFi.scanNetworks();
}

void WifiController::handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info) {
  if (networkCount == 0) {
    LOG_WARNING("No networks found");
  }
  else {
    for (int i = 0 ; i < networkCount; i++) {
      ssids = WiFi.SSID(i);
      LOG_WARNING(ssids);
    }
  }
}

void WifiController::handleConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
  LOG_WARNING("Connected to Access Point");
}