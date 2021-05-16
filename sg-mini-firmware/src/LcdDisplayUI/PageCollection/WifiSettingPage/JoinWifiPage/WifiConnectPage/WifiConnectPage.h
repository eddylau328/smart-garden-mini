#ifndef WifiConnectPage_h
#define WifiConnectPage_h

#include "../../../Page.h"
#include "../../../../../Helper/Helper.h"
#include "../../../../../DeviceSetting/DeviceSetting.h"
#include "../../../../TempStorage/TempStorage.h"
#include "../../../../Components/LoadingSpinner/LoadingSpinner.h"
#include "../../../../../WifiController/WifiController.h"
#include "../../../../../DeviceSetting/SettingManager/WifiSettingManager/AccessPointSetting/AccessPointSetting.h"


/**
 * @brief Page derived class use to show to the user when the system is idle
 * 
 */
class WifiConnectPage : public Page {
  public:
    WifiConnectPage();
    void mountPage();
    void updateContents();
    void dismountPage();

  private:
    enum ContentIndex {
      Loading = 1,
      WifiName = 2,
    };

    int8_t staticContentSize = 3;
    PageContent staticContents[3] = {
      PageContent("Connecting", 10, PageLayoutPosition(0, 0)),
      PageContent(" ", 1, PageLayoutPosition(15, 0)),
      PageContent()
    };
    LoadingSpinner loadingSpinner;
    char *wifiName;
    int wifiNameLength;
};

#endif