#ifndef ScheduleSettingPage_h
#define ScheduleSettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


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
      Arrow = 3
    };

    PageContent staticContents[9] = {
      PageContent(2, PageLayoutPosition(0, 1)),
      PageContent(2, PageLayoutPosition(3, 1)),
      PageContent(2, PageLayoutPosition(6, 1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent(10, PageLayoutPosition(0, 0)),
      PageContent(":", 1, PageLayoutPosition(2, 1)),
      PageContent(":", 1, PageLayoutPosition(5, 1)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1))
    };
    int8_t inputIndex;

    InputNumber input[3];
    PageVerticalScroll scroll;

     void changeTopic();
};

#endif