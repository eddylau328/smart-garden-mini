#ifndef WifiController_h
#define WifiController_h

#include <WiFi.h>
#include <DebugLog.h>
#include <Arduino.h>

// Own Library
#include "../DeviceSetting/DeviceSetting.h"

/**
 * @brief provides wifi connection functions for connecting to the backend server for receiving/sending data
 * 
 */
class WifiController {

  public:
    static void init();
    static void getIsConnected();
    static void getAccessPoint();
    static void connect(char *ssid, char *password);
    static void scanNetworks();
    static void disconnect();
    static void mainLoop();

  private:
    static int networkCount;
    static void handleConnected(WiFiEvent_t event, WiFiEventInfo_t info);
    static void handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info);
    static String ssids;
};

#endif