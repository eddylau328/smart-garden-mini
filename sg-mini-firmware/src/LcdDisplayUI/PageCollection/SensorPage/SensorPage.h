#ifndef SensorPage_h
#define SensorPage_h

#include "../Page.h"
#include "../../../Sensors/Sensors.h"
#include "../../../Sensors/SensorsCollection/SensorCollection.h"
#include "../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../Components/PageLayoutRange/PageLayoutRange.h"

/**
 * @brief Page derived class use to show the sensor data 
 * 
 */
class SensorPage : public Page {

  public:
    SensorPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent staticContents[12] = {
      PageContent("Temp",  4, PageLayoutPosition(0, 0)),
      PageContent("Hum",   3, PageLayoutPosition(0, 1)),
      PageContent("STemp", 5, PageLayoutPosition(0, 2)),
      PageContent("SHum",  4, PageLayoutPosition(0, 3)),
      PageContent("Light", 5, PageLayoutPosition(0, 4)),
      PageContent("Water", 5, PageLayoutPosition(0, 5)),
      PageContent(6, PageLayoutPosition(9, 0)),
      PageContent(6, PageLayoutPosition(9, 1)),
      PageContent(6, PageLayoutPosition(9, 2)),
      PageContent(6, PageLayoutPosition(9, 3)),
      PageContent(6, PageLayoutPosition(9, 4)),
      PageContent(6, PageLayoutPosition(9, 5)),
    };

    PageVerticalScroll scroll;

    void updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex);

};

#endif