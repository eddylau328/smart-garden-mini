#ifndef ScheduleSettingPage_h
#define ScheduleSettingPage_h

#include "../../../Page.h"
#include "../../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include <RTClib.h>

/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ScheduleSettingPage : public Page {

  public:
    ScheduleSettingPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    

  private:
    enum InputIndex {
        Hour = 0,
        Minute = 1,
        Second = 2,
        TargetHumidity = 3,
        Arrow = 4,
    };
    enum RowIndex {
        DurationRow = 0,
        TargetHumidityRow = 1,
        SaveRow = 2,
        ReturnRow = 3,
    };

    PageContent staticContents[11] = {
      PageContent(2, PageLayoutPosition(8, 0)),
      PageContent(2, PageLayoutPosition(11, 0)),
      PageContent(2, PageLayoutPosition(14, 0)),
      PageContent(2, PageLayoutPosition(12, 1)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
      PageContent("Time", 4, PageLayoutPosition(2, 0)),
      PageContent("Target H", 8, PageLayoutPosition(2, 1)),
      PageContent(":", 1, PageLayoutPosition(10, 0)),
      PageContent(":", 1, PageLayoutPosition(13, 0)),
      PageContent("Save", 4, PageLayoutPosition(2, 2)),
      PageContent("...", 3, PageLayoutPosition(2, 3))
    };

    int8_t inputIndex;

    InputNumber input[4];
    PageVerticalScroll scroll;

    void updateScheduleModeSetting();
    void processActions(int counter, bool isPress);
    void processInputAction(int counter, bool isPress);
    void toggleInputContent(InputIndex index);
};

#endif