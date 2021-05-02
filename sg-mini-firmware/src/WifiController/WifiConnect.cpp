#include "WifiConnect.h"

char *WifiConnect::ssid;
char *WifiConnect::password;
bool WifiConnect::isRequestConnect = false;
bool WifiConnect::isFinishEvent = true;

/* public function */
void WifiConnect::connect(char *ssid, char *password) {
  delete [] WifiConnect::ssid;
  delete [] WifiConnect::password;
  WifiConnect::ssid = new char[strlen(ssid) + 1];
  WifiConnect::password = new char[strlen(password) + 1];
  Helper::assignStrValue(WifiConnect::ssid, '\0', strlen(ssid) + 1);
  Helper::assignStrValue(WifiConnect::password, '\0', strlen(password) + 1);
  Helper::copyString(WifiConnect::ssid, ssid, strlen(ssid) + 1);
  Helper::copyString(WifiConnect::password, password, strlen(password) + 1);
  isRequestConnect = true;
}

void WifiConnect::connect(AccessPointSetting setting) {
  delete [] WifiConnect::ssid;
  delete [] WifiConnect::password;
  char *ssidTemp = setting.getAccessPointName();
  int ssidLength = Helper::getStringLength(ssidTemp);
  char *passwordTemp = setting.getAccessPointPassword();
  int passwordLength = Helper::getStringLength(passwordTemp);
  WifiConnect::ssid = new char[ssidLength];
  WifiConnect::password = new char[passwordLength];
  Helper::copyString(WifiConnect::ssid, ssidTemp, ssidLength);
  Helper::copyString(WifiConnect::password, passwordTemp, passwordLength);
  isRequestConnect = true;
}

void WifiConnect::disconnect() {
  WiFi.disconnect();
}

bool WifiConnect::isConnectedNetwork() {
  return WiFi.status() == WL_CONNECTED;
}

void WifiConnect::connectEvent() {
  isFinishEvent = false;
  disconnect();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    LOG_WARNING("Connecting to WiFi..");
    delay(500);
  }
}

void WifiConnect::handleConnect(WiFiEvent_t event, WiFiEventInfo_t info) {
  LOG_WARNING("Connected to the WiFi network");
  isFinishEvent = true;
}

void WifiConnect::mainLoop() {
  if (isRequestConnect && isFinishEvent) {
    isRequestConnect = false;
    connectEvent();
  }
}