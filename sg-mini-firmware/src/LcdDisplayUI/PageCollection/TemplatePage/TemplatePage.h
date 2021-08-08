#ifndef TemplatePage_h
#define TemplatePage_h

#include "../Page.h"

/**
 * @brief Page derived class use to show how to create a derived page class
 * 
 */
class TemplatePage : public Page {

  public:
    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);
    void dismountPage();

  private:
    PageContent staticContents[2] = {
      PageContent("Template", 8, PageLayoutPosition(0,0)),
      PageContent("Page", 4, PageLayoutPosition(0,1))
    };

};

#endif