#ifndef HumiditySettingPage_h
#define HumiditySettingPage_h

#include "../../../Page.h"
#include "../../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class HumiditySettingPage : public Page {

  public:
    HumiditySettingPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum InputIndex {
        TargetHumidity = 0,
        MinHumidity = 1,
        MaxHumidity = 2,
        Arrow = 3,
    };

    enum RowIndex {
      TargetHumidityRow = 0,
      MinHumidityRow = 1,
      MaxHumidityRow = 2,
      SaveRow = 3,
      ReturnRow = 4,
    };
    
    PageContent staticContents[9] = {
      PageContent(2, PageLayoutPosition(10, 0)),
      PageContent(2, PageLayoutPosition(10, 1)),
      PageContent(2, PageLayoutPosition(10, 2)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
      PageContent("Target H", 8, PageLayoutPosition(2, 0)),
      PageContent("Min H", 5, PageLayoutPosition(2 ,1)),
      PageContent("Max H", 5, PageLayoutPosition(2, 2)),
      PageContent("Save", 4, PageLayoutPosition(2, 3)),
      PageContent("...", 3, PageLayoutPosition(2, 4))
    };

    InputIndex inputIndex;
    InputNumber input[3];
    PageVerticalScroll scroll;

    void updateHumidityModeSetting();
    void processActions(int counter, bool isPress);
    void processInputAction(int counter, bool isPress);
    void toggleArrowContent(InputIndex index);
    void updateInputHumidityRange(int8_t range, int8_t min, int8_t max);
};

#endif