#ifndef WifiSettingPage_h
#define WifiSettingPage_h

#include "../Page.h"

// Components
#include "../../Components/PageContent/PageContent.h"
#include "../../Components/Input/InputBoolean/InputBoolean.h"
#include "../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"

// Modules
#include "../../../WifiController/WifiController.h"

/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class WifiSettingPage : public Page {

  public:
    WifiSettingPage();
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();

  private:
    enum ContentIndex {
      WifiModeInput = 1,
      ReturnInput = 2,
      Arrow = 3,
      ScanWifiInput = 4,
    };

    PageContent staticContents[5] = {
      PageContent("Wifi Mode", 9, PageLayoutPosition(2, 0)),
      PageContent(3, PageLayoutPosition(13, 0)),
      PageContent("...      ", 9, PageLayoutPosition(2, 1)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
      PageContent("Scan Wifi", 9, PageLayoutPosition(2, 1)),
    };

    // Inputs
    InputBoolean input;
    int8_t inputIndex;
    bool wifiMode;

    PageVerticalScroll scroll;

    void processPageContent();

    void updateIsWifiOn();
};

#endif