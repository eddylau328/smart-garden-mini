#ifndef WifiConnect_h
#define WifiConnect_h

#include <WiFi.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"

class WifiConnect {
  public:
    static void connect(char *ssid, char *password);
    static void disconnect();
    static bool isConnectedNetwork();

  protected:
    static void handleConnect(WiFiEvent_t event, WiFiEventInfo_t info);
    static void mainLoop();

  private:
    static void connectEvent();

    static char *ssid;
    static char *password;
    static bool isRequestConnect;
    static bool isFinishEvent;
};

#endif