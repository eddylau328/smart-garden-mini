#ifndef ManualSettingPage_h
#define ManualSettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ManualSettingPage : public Page {

  public:
     ManualSettingPage();
     ~ManualSettingPage();

    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();

  private:
    enum InputIndex{
        Second = 0,
        Arrow = 1
    };
    const int8_t contentSize = 6;
    PageContent contents[6] = {
      PageContent("Sec2Water", 9, PageLayoutPosition(0,0)),
      PageContent("Second", 6, PageLayoutPosition(0,1)),
      PageContent(2, PageLayoutPosition(9,0)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
      PageContent(">", 1, PageLayoutPosition(0, 1))
    };

    int8_t inputIndex;
    InputNumber input;
    PageVerticalScroll scroll;
};

#endif