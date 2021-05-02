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
    PageContent staticContents[8] = {
      PageContent("Time",  4, PageLayoutPosition(2, 0)),
      PageContent("Date",   4, PageLayoutPosition(2, 1)),
      PageContent("WiFi", 4, PageLayoutPosition(2, 2)),
      PageContent("Watering",  8, PageLayoutPosition(2, 3)),
      PageContent("Idle Time", 9, PageLayoutPosition(2, 4)),
      PageContent("User Name", 9, PageLayoutPosition(2, 5)),
      PageContent("...", 3, PageLayoutPosition(2, 6)),
      PageContent(">", 1, PageLayoutPosition(0, 0))
    };

    PageVerticalScroll scroll;

};

#endif