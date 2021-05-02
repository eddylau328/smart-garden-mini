#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../../DeviceSetting/DeviceSetting.h"
#include "../../../Sensors/Sensors.h"
#include "../../../Sensors/SensorsCollection/SensorCollection.h"

/**
 * @brief Page derived class use to show to the user when the system is idle
 * 
 */
class MainPage : public Page {
  public:
    void mountPage();
    void updateContents();

  private:
    PageContent staticContents[7] = {
      PageContent(2, PageLayoutPosition(0, 0)),
      PageContent(":", 1, PageLayoutPosition(2, 0)),
      PageContent(2, PageLayoutPosition(3, 0)),
      PageContent("T", 1, PageLayoutPosition(0, 1)),
      PageContent(2, PageLayoutPosition(2, 1)),
      PageContent("H", 1, PageLayoutPosition(5, 1)),
      PageContent(3, PageLayoutPosition(7, 1))
    };
    
    void updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex);
};

#endif