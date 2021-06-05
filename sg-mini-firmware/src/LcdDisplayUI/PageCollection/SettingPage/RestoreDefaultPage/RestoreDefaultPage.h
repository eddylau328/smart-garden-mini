#ifndef RestoreDefaultPage_h
#define RestoreDefaultPage_h

#include "../../Page.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"

/**
 * @brief Page derived class use to change the user name 
 * 
 */
class RestoreDefaultPage : public Page {
  public:
    RestoreDefaultPage();
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum InputIndex {
      Arrow = 2, 
    };

    PageContent staticContents[5] = {
      PageContent("Reset to", 8, PageLayoutPosition(0, 0)),
      PageContent("Default", 7, PageLayoutPosition(0, 1)),
      PageContent(">", 1, PageLayoutPosition(10, 1)),
      PageContent("Next", 4, PageLayoutPosition(12, 0)),
      PageContent("Back", 4, PageLayoutPosition(12, 1)),
    };

    PageVerticalScroll scroll;

    void proceedNextPage(int counter, bool isPress);
    bool shouldResetSystem();
};

#endif