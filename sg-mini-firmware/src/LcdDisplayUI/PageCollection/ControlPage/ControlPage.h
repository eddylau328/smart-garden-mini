#ifndef ControlPage_h
#define ControlPage_h

#include "../Page.h"
#include "../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../Components/PageLayoutRange/PageLayoutRange.h"
#include "../../../DeviceSetting/SettingManager/WaterSettingManager/WaterSettingManager.h"

/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ControlPage : public Page {

  public:
    ControlPage();

    void mountPage();
    void interactiveUpdate(int counter, bool isPress);
    

  private:
    enum RowIndex {
      Mode = 0,
      ModeSetting = 1,
      Return = 2,
    };

    const uint8_t CURSOR_INDEX = 4;
    const uint8_t MODE_NAME_INDEX = 1;
    
    PageContent staticContents[5] = {
      PageContent("Mode: ", 6, PageLayoutPosition(2,0)),
      PageContent(8, PageLayoutPosition(8,0)),
      PageContent("Mode Setting", 12, PageLayoutPosition(2,1)),
      PageContent("...", 3, PageLayoutPosition(2,2)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
    };

    PageVerticalScroll scroll;

    PageCollection::PageKey waterModeSettingPageKey = PageCollection::PageKey::ManualSettingPageKey;
    void setupWaterMode();
};

#endif