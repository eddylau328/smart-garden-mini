#include "WifiConnect.h"

/* public function */
void WifiConnect::connect(char *ssid, char *password) {
  disconnect();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}

void WifiConnect::disconnect() {
  WiFi.disconnect();
}


/* protected */
void WifiConnect::handleConnect(WiFiEvent_t event, WiFiEventInfo_t info) {
  LOG_WARNING("Connected to Access Point");
}