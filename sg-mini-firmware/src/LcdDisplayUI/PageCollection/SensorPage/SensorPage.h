#ifndef SensorPage_h
#define SensorPage_h

#include "../Page.h"
#include "../../../Sensors/Sensors.h"
#include "../../../Sensors/SensorsCollection/SensorCollection.h"

class SensorPage : public Page {

  public:
    SensorPage(Sensors *sensors);
    ~SensorPage();

    void getContents(PageContent **contents, int *length);
    void updateContents();

  private:
    PageContent contents[4] = {
      PageContent("Air Temp", 8, PageContent::ContentType::Constant, PageLayoutPosition(0, 0)),
      PageContent("Air Hum",  7, PageContent::ContentType::Constant, PageLayoutPosition(0, 1)),
      PageContent("",         6, PageContent::ContentType::Variable, PageLayoutPosition(9, 0)),
      PageContent("",         6, PageContent::ContentType::Variable, PageLayoutPosition(9, 1))
    };

    Sensors *sensors; // no need to free this pointer, as you are just referencing it

};

#endif