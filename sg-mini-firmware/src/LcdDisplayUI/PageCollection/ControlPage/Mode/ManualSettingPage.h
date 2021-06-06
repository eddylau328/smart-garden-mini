#ifndef ManualSettingPage_h
#define ManualSettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../DeviceSetting/SettingManager/WaterSettingManager/WaterSettingManager.h"
#include "../../../../DeviceSetting/SettingManager/WaterSettingManager/ModeSetting/ManualModeSetting/ManualModeSetting.h"
#include "../../../../WaterController/WaterController.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ManualSettingPage : public Page {

  public:
     ManualSettingPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
   

  private:
    enum InputIndex {
      Second = 0,
      Arrow = 1
    };
    enum RowIndex {
      Fire = 1,
      Back = 0,
    };

    PageContent staticContents[6] = {
      PageContent(2, PageLayoutPosition(7,1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent("Sec2Water", 9, PageLayoutPosition(0,0)),
      PageContent("Second", 6, PageLayoutPosition(0,1)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Fire", 4, PageLayoutPosition(12, 1)),
    };

    InputIndex inputIndex;
    InputNumber input;
    PageVerticalScroll scroll;

    void processActions(int counter, bool isPress);
    void processFireAction();
    void processReturnAction(int counter, bool isPress);
    void processInputAction(int counter, bool isPress);

    void toggleArrowContent(InputIndex index);
};

#endif