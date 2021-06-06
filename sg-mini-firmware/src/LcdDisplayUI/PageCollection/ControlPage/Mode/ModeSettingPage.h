#ifndef ModeSettingPage_h
#define ModeSettingPage_h

#include "../../Page.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../DeviceSetting/SettingManager/WaterSettingManager/WaterSettingManager.h"
#include "../../../../WaterController/WaterController.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ModeSettingPage : public Page {
  public:
    ModeSettingPage();
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);
   

  private:
    enum RowIndex {
      Manual = 0,
      Humidity = 1,
      Schedule = 2,
    };

    const uint8_t CURSOR_INDEX = 4;
    const uint8_t INDICATOR_INDEX = 5;

    PageContent staticContents[6] = {
      PageContent("Manual", 6, PageLayoutPosition(2,0)),
      PageContent("Humidity", 8, PageLayoutPosition(2,1)),
      PageContent("Schedule", 8, PageLayoutPosition(2,2)),
      PageContent("...", 3, PageLayoutPosition(2,3)),
      PageContent(">", 1, PageLayoutPosition(0,0)),
      PageContent("*", 1, PageLayoutPosition(12,0))
    };

    PageVerticalScroll scroll;

};

#endif