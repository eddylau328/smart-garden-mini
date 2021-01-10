#ifndef AutoSettingPage_h
#define AutoSettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class AutoSettingPage : public Page {

  public:
     AutoSettingPage();
     ~AutoSettingPage();

    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();

  private:
    enum InputIndex{
        Humidity = 0,
        Arrow = 1
    };
    const int8_t contentSize = 6;
    PageContent contents[6] = {
      PageContent("Set Auto", 8, PageLayoutPosition(0,0)),
      PageContent("Humidity", 8, PageLayoutPosition(0,1)),
      PageContent(2, PageLayoutPosition(9,0)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
      PageContent(">", 1, PageLayoutPosition(0, 1))
    };

    int8_t inputIndex;
    InputNumber input[1];
    PageVerticalScroll scroll;
};

#endif