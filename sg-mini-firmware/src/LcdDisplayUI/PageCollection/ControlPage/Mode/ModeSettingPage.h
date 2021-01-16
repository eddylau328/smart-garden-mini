#ifndef ModeSettingPage_h
#define ModeSettingPage_h

#include "../../Page.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"


/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ModeSettingPage : public Page {
  public:
     ModeSettingPage();
     ~ModeSettingPage();

    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
   

  private:
    const int8_t contentSize = 4;
    PageContent contents[4] = {
      PageContent("Auto", 4, PageLayoutPosition(2,0)),
      PageContent("Schedule", 8, PageLayoutPosition(2,1)),
      PageContent("Back", 4, PageLayoutPosition(2, 2)),
      PageContent(">", 1, PageLayoutPosition(0, 0))
    };

    PageVerticalScroll scroll;
};

#endif