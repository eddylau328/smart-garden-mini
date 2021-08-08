#include "WifiController.h"

TaskHandle_t WifiController::wifiMainLoop;
millisDelay WifiController::reconnectDelay;

void WifiController::init() {
  WifiConnect::disconnect();

  // set event listener
  WiFi.onEvent(WifiConnect::handleConnect, SYSTEM_EVENT_STA_CONNECTED);
  WiFi.onEvent(WifiScan::handleScanNetworks, SYSTEM_EVENT_SCAN_DONE);

  xTaskCreatePinnedToCore(
                    mainLoop,   /* Task function. */
                    "WifiMainLoop",     /* name of task. */
                    9999,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &wifiMainLoop,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */       
}

void WifiController::mainLoop(void * pvParameters ) {
  reconnectDelay.start(5000);
  const TickType_t xDelay = 2000 / portTICK_PERIOD_MS;
  while (true) {
    WifiScan::mainLoop();
    WifiConnect::mainLoop();

    if (!WifiConnect::isConnectedNetwork() && !WifiConnect::isConnecting()) {
      if (reconnectDelay.justFinished()) {
        Serial.println("enter reconnect");
        WifiSettingManager *manager = DeviceManager::getWifiSettingManager();
        if (manager->getIsWifiOn() && manager->getIsAccessPointSet()) {
          WifiConnect::connect(manager->getAccessPointSetting());
        }
        reconnectDelay.repeat();
      }
    }

    vTaskDelay(xDelay);
  }
}