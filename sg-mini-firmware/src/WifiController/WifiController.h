#ifndef WifiController_h
#define WifiController_h

#include <WiFi.h>
#include <DebugLog.h>
#include <Arduino.h>

// Own Library
#include "../DeviceSetting/DeviceSetting.h"
#include "../Helper/Helper.h"

#include "WifiInfo.h"

/**
 * @brief provides wifi connection functions for connecting to the backend server for receiving/sending data
 * 
 */
class WifiController: public WifiInfo {

  public:
    static void init();
    static void getIsConnected();
    static void connect(char *ssid, char *password);
    static void disconnect();
    static void mainLoop();
    static void startScanNetwork(uint8_t rescanCount=3);
    static void stopScanNetwork();

  private:
    static void handleConnected(WiFiEvent_t event, WiFiEventInfo_t info);
    static void scanNetworks();
    static void handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info);
    static unsigned long lastActionCheck;
    static bool isScanNetwork;
    static int scanNetworkCount;
    static uint8_t rescanNetworkCount;

};

#endif