#ifndef WifiController_h
#define WifiController_h

#include <WiFi.h>
#include <DebugLog.h>
#include <Arduino.h>

// Own Library
#include "../DeviceSetting/DeviceSetting.h"
#include "../Helper/Helper.h"

#include "WifiScan.h"

/**
 * @brief provides wifi connection functions for connecting to the backend server for receiving/sending data
 * 
 */
class WifiController: public WifiScan {

  public:
    static void init();
    static void getIsConnected();
    static void connect(char *ssid, char *password);
    static void disconnect();
    static void mainLoop();

  private:
    static void handleConnected(WiFiEvent_t event, WiFiEventInfo_t info);
};

#endif