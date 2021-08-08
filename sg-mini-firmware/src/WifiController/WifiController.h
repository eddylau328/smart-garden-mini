#ifndef WifiController_h
#define WifiController_h


// Own Library

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