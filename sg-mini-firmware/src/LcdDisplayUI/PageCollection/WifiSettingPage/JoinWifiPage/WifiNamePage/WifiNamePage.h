#ifndef WifiNamePage_h
#define WifiNamePage_h

#include "../../../Page.h"
#include "../../../../Components/Input/InputAscii/InputAscii.h"
#include "../../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../../Storage/StorageConstant.h"
#include "../../../../Components/Input/InputCharacter/InputCharacter.h"
#include "../../../../TempStorage/TempStorage.h"
#include "../../../../../DeviceSetting/SettingManager/WifiSettingManager/AccessPointSetting/AccessPointSetting.h"

/**
 * @brief Page derived class use to join wifi
 * 
 */
class WifiNamePage : public Page {
  public:
    WifiNamePage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();

  private:
    enum InputIndex {
      Name = 0,
      Arrow = 1
    };

    int8_t staticContentSize = 7;
    PageContent staticContents[7] = {
      PageContent(8, PageLayoutPosition(1, 1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent("Wifi Name", 9, PageLayoutPosition(0, 0)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Next", 4, PageLayoutPosition(12, 1)),
      PageContent("[", 1, PageLayoutPosition(0, 1)),
      PageContent("]", 1, PageLayoutPosition(9, 1))
    };

    int8_t inputIndex;

    InputCharacter input;
    PageVerticalScroll scroll;
};

#endif