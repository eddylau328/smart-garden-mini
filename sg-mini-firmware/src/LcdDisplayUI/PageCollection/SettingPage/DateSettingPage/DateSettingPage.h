#ifndef DateSettingPage_h
#define DateSettingPage_h

#include <RTClib.h>
#include "../../Page.h"
#include "../../../TempStorage/TempStorage.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"

/**
 * @brief Page derived class use to set the date of the device
 * 
 */
class DateSettingPage : public Page {
  public:
    DateSettingPage();
    ~DateSettingPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum InputIndex {
      Year = 0,
      Month = 1,
      DayOfMonth = 2,
      Arrow = 3 
    };

    PageContent staticContents[9] = {
      PageContent(2, PageLayoutPosition(0, 1)),
      PageContent(2, PageLayoutPosition(3, 1)),
      PageContent(2, PageLayoutPosition(6, 1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent(11, PageLayoutPosition(0, 0)),
      PageContent("-", 1, PageLayoutPosition(2, 1)),
      PageContent("-", 1, PageLayoutPosition(5, 1)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1))
    };
    int8_t inputIndex;
    InputNumber input[3];
    PageVerticalScroll scroll;

    void changeTopic();
    void storeDateTime();

    void setupDayInputRange();
    void inputInteractiveUpdate(int counter, bool isPress);
    bool shouldStoreDateTime();

    void proceedNextPage(int counter, bool isPress);
    void proceedNormalNextPage(int counter, bool isPress);
    void proceedSystemResetNextPage();
};

#endif