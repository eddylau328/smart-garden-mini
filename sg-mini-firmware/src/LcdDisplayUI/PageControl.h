#ifndef PageControl_h
#define PageControl_h

#include "PageCollection/Page.h"

#define TotalPage 1 // Modify it if you want to add page

class PageControl {

  // Add PageKey if you add a new page
  enum PageKey {
    MainPage
  };

  public:
    PageControl();
    ~PageControl();

  private:
    Page *pages[TotalPage];
};

#endif
