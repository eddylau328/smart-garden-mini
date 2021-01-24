#ifndef ControlPage_h
#define ControlPage_h

#include "../Page.h"
#include "../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../Components/PageLayoutRange/PageLayoutRange.h"

/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class ControlPage : public Page {

  public:
   ControlPage();
   ~ControlPage();     //What does this mean?

    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    

  private:
    
    const int8_t contentSize = 4;
    PageContent contents[4] = {
      PageContent("Mode", 4, PageLayoutPosition(2,0)),
      PageContent("Manual", 6, PageLayoutPosition(2,1)),
      PageContent("...", 3, PageLayoutPosition(2,2)),
      PageContent(">", 1, PageLayoutPosition(0, 0)),
    };

    PageVerticalScroll scroll;
};

#endif