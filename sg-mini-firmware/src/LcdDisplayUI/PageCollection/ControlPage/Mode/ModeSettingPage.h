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
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);
   

  private:
    PageContent staticContents[4] = {
      PageContent("Auto", 4, PageLayoutPosition(2,0)),
      PageContent("Schedule", 8, PageLayoutPosition(2,1)),
      PageContent("...", 3, PageLayoutPosition(2, 2)),
      PageContent(">", 1, PageLayoutPosition(0, 0))
    };

    PageVerticalScroll scroll;
};

#endif