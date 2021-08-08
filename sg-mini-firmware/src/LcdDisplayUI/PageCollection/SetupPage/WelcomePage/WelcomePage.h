#ifndef WelcomePage_h
#define WelcomePage_h

#include "../../Page.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../Components/PageLayoutRange/PageLayoutRange.h"


/**
 * @brief WelcomePage derived class use for greetings
 * 
 */
class WelcomePage : public Page {

  public:
    WelcomePage();
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent staticContents[8] = {
      PageContent("Welcome  to  use", 16, PageLayoutPosition(0, 0)),
      PageContent("the Smart Garden", 16, PageLayoutPosition(0, 1)),
      PageContent("Mini  Prototype.", 16, PageLayoutPosition(0, 2)),
      PageContent("Here,  you  will", 16, PageLayoutPosition(0, 3)),
      PageContent("follow the basic", 16, PageLayoutPosition(0, 4)),
      PageContent("setup procedures", 16, PageLayoutPosition(0, 5)),
      PageContent("before using it.", 16, PageLayoutPosition(0, 6)),
      PageContent("> next", 6, PageLayoutPosition(10, 7)),
    };

    PageVerticalScroll scroll;
};

#endif