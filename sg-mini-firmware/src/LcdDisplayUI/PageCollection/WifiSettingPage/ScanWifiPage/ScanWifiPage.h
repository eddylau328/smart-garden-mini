#ifndef ScanWifiPage_h
#define ScanWifiPage_h

#include "../../Page.h"

#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"

#include "../../../../WifiController/WifiController.h"

class ScanWifiPage : public Page {

  public:
    ScanWifiPage();
    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();
  
  private:
    enum ContentIndex {
      Header = 0,
      Loading = 1,
      Arrow = 2,
      JoinOther = 3,
      ReturnInput = 4
    };

    bool isCreatedDynamicContent = false;

    PageVerticalScroll scroll;

    int8_t contentSize = 0;
    PageContent **contents;

    int8_t staticContentSize = 5;
    PageContent staticContents[5] = {
      PageContent("Scan Wifi", 9, PageLayoutPosition(0, 0)),
      PageContent(2, PageLayoutPosition(14, 0)),
      PageContent(">", 1, PageLayoutPosition(0, 1)),
      PageContent("Join Other", 10, PageLayoutPosition(2, 2)),
      PageContent("...", 3, PageLayoutPosition(2, 3))
    };

    int8_t dynamicContentSize = 0;
    PageContent **dynamicContents;

    int8_t contentRow = 0;
    void contentSetup();
    void getDynamicContents();
};

#endif`