#ifndef HumiditySettingPage_h
#define HumiditySettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputNumber/InputNumber.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


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
        Humidity = 0,
        Arrow = 1
    };

    enum RowIndex {
      Return = 0,
      Save = 1,
    };
    
    PageContent staticContents[6] = {
      PageContent(2, PageLayoutPosition(9,1)),
      PageContent(" ", 1, PageLayoutPosition(11, 1)),
      PageContent("Set target", 10, PageLayoutPosition(0,0)),
      PageContent("Humidity", 8, PageLayoutPosition(0,1)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
    };

    InputIndex inputIndex;
    InputNumber input;
    PageVerticalScroll scroll;

    void updateHumidityModeSetting();

    void processActions(int counter, bool isPress);
    void processInputAction(int counter, bool isPress);
    void toggleArrowContent(InputIndex index);
};

#endif