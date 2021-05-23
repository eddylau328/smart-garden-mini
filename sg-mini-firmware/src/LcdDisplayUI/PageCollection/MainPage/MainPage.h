#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../../DeviceSetting/DeviceSetting.h"
#include "../../../Sensors/Sensors.h"
#include "../../../Sensors/SensorsCollection/SensorCollection.h"
#include "../../../WifiController/WifiController.h"


/**
 * @brief Page derived class use to show to the user when the system is idle
 * 
 */
class MainPage : public Page {
  public:
    void mountPage();
    void updateContents();

  private:
    enum ContentIndex {
      USERNAME = 0,
      HOUR = 1,
      SECOND = 2,
      MINUTE = 3,
      TEMPERATURE = 5,
      HUMIDITY = 7,
      WIFI_STATUS = 8,
    };

    PageContent staticContents[9] = {
      PageContent(8, PageLayoutPosition(0, 0)),
      PageContent(2, PageLayoutPosition(10, 0)),
      PageContent(":", 1, PageLayoutPosition(12, 0)),
      PageContent(2, PageLayoutPosition(13, 0)),
      PageContent("T", 1, PageLayoutPosition(0, 1)),
      PageContent(2, PageLayoutPosition(2, 1)),
      PageContent("H", 1, PageLayoutPosition(5, 1)),
      PageContent(3, PageLayoutPosition(7, 1)),
      PageContent(1, PageLayoutPosition(15, 0))
    };
    
    void updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex);

    void updateWifiStatus();
};

#endif