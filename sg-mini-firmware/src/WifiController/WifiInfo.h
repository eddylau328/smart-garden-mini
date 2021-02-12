#ifndef WifiInfo_h
#define WifiInfo_h

#define BufferSize 20

#include <WiFi.h>
#include <Arduino.h>

#include "../Helper/Helper.h"

class WifiInfo{

  public:
    static int getNetworkCount();
    static void getNetwork(char **name, int *length, int index);

  protected:
    static void initializeNetworks(int networkCount);
    static void setNetwork(String networkName, int index);

  private:
    static char **networks;
    static int networkCount;

};

#endif