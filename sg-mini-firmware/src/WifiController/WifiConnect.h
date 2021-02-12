#ifndef WifiConnect_h
#define WifiConnect_h

#include <WiFi.h>
#include <Arduino.h>
#include <DebugLog.h>

class WifiConnect{
  public:
    static void connect(char *ssid, char *password);
    static void disconnect();

  protected:
    static void handleConnect(WiFiEvent_t event, WiFiEventInfo_t info);
};

#endif