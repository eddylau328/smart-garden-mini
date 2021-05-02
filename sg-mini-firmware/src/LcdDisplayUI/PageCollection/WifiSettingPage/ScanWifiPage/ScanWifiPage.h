#ifndef ScanWifiPage_h
#define ScanWifiPage_h

#include "../../Page.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../WifiController/WifiController.h"
#include "../../../Components/LoadingSpinner/LoadingSpinner.h"

class ScanWifiPage : public Page {

  public:
    ScanWifiPage();
    void mountPage();
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

    int8_t staticContentSize = 5;
    PageContent staticContents[5] = {
      PageContent("Scan Wifi", 9, PageLayoutPosition(2, 0)),
      PageContent(" ", 1, PageLayoutPosition(15, 0)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
      PageContent("Join Other", 10, PageLayoutPosition(2, 1)),
      PageContent("...", 3, PageLayoutPosition(2, 2))
    };

    int8_t dynamicContentSize = 0;
    PageContent **dynamicContents;

    int8_t contentRow = 0;
    void contentSetup();
    void getDynamicContents();
    void freeDynamicContents();
    void freeContents();

    LoadingSpinner loadingSpinner;
};

#endif