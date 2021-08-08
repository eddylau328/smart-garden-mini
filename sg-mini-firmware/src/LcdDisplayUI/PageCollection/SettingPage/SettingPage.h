#ifndef SettingPage_h
#define SettingPage_h

#include "../Page.h"
#include "../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../Components/PageLayoutRange/PageLayoutRange.h"

/**
 * @brief Page derived class use to show the user which settings can be alter
 * 
 */
class SettingPage : public Page {

  public:
    SettingPage();

    void mountPage();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum RowIndex {
      DateTime = 0,
      Wifi = 1,
      Watering = 2,
      IdleTime = 3,
      Username = 4,
      Restore = 5,
      Return = 6,
    };

    PageContent staticContents[8] = {
      PageContent("DateTime",  8, PageLayoutPosition(2, 0)),
      PageContent("WiFi", 4, PageLayoutPosition(2, 1)),
      PageContent("Watering",  8, PageLayoutPosition(2, 2)),
      PageContent("Idle Time", 9, PageLayoutPosition(2, 3)),
      PageContent("User Name", 9, PageLayoutPosition(2, 4)),
      PageContent("Restore", 7, PageLayoutPosition(2, 5)),
      PageContent("...", 3, PageLayoutPosition(2, 6)),
      PageContent(">", 1, PageLayoutPosition(0, 0))
    };

    PageVerticalScroll scroll;

};

#endif