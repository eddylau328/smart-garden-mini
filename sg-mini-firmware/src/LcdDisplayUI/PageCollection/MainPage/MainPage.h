#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../../DeviceSetting/DeviceSetting.h"
#include "../../../Sensors/Sensors.h"
#include "../../../Sensors/SensorsCollection/SensorCollection.h"

class MainPage : public Page {
  public:
    MainPage(Sensors *sensors);
    ~MainPage();
    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();

  private:
    PageContent contents[7] = {
      PageContent(2, PageLayoutPosition(0, 0)),
      PageContent(":", 1, PageLayoutPosition(2, 0)),
      PageContent(2, PageLayoutPosition(3, 0)),
      PageContent("T", 1, PageLayoutPosition(0, 1)),
      PageContent(2, PageLayoutPosition(2, 1)),
      PageContent("H", 1, PageLayoutPosition(5, 1)),
      PageContent(3, PageLayoutPosition(7, 1))
    };
    Sensors *sensors;
    void updateSensorData(SensorCollection::SensorDataType dataType, int contentIndex);
};

#endif