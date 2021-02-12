#ifndef WifiScan_h
#define WifiScan_h

#define BufferSize 20

#include <WiFi.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"

class WifiScan{

  public:
    static int getNetworkCount();
    static void getNetwork(char **name, int *length, int index);
    static void startScanNetwork(uint8_t rescanCount=3);
    static void stopScanNetwork();

  protected:
    static void mainLoop();
    static void handleScanNetworks(WiFiEvent_t event, WiFiEventInfo_t info);

  private:
    static void scanNetworks();
    static void initializeNetworks(int networkCount);
    static void setNetwork(String networkName, int index);
    static char **networks;
    static int networkCount;
    static unsigned long lastAction;
    static bool isScanNetwork;
    static int scanNetworkCount;
    static uint8_t rescanNetworkCount;
};

#endif