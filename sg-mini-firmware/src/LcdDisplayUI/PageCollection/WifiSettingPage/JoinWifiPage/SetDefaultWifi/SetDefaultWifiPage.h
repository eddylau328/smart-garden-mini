#ifndef SetDefaultWifiPage_h
#define SetDefaultWifiPage_h

#include "../../../Page.h"
#include "../../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../TempStorage/TempStorage.h"
#include "../../../../../WifiController/Setting/AccessPointSetting/AccessPointSetting.h"


class SetDefaultWifiPage : public Page {

  public:
    SetDefaultWifiPage();
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);
  
  private:
    enum ContentIndex {
      Arrow = 1,
    };

    PageVerticalScroll scroll;

    int8_t staticContentSize = 4;
    PageContent staticContents[4] = {
      PageContent("Default?", 8, PageLayoutPosition(0, 0)),
      PageContent(">", 1, PageLayoutPosition(10, 1)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
    };
};

#endif