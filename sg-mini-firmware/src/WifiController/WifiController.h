#ifndef WifiController_h
#define WifiController_h

#include <WiFi.h>
#include <DebugLog.h>
#include <Arduino.h>

// Own Library
#include "../DeviceSetting/DeviceSetting.h"
#include "../Helper/Helper.h"

#include "WifiScan.h"
#include "WifiConnect.h"

/**
 * @brief provides wifi connection functions for connecting to the backend server for receiving/sending data
 * 
 */
class WifiController: public WifiScan, public WifiConnect {

  public:
    static void init();
  
  private:
    static TaskHandle_t wifiMainLoop;
    static void mainLoop(void * pvParameters );

};

#endif