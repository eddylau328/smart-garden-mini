#ifndef PageControl_h
#define PageControl_h

#define TotalPage 1 // Modify it if you want to add page

#include "PageCollection/Page.h"
#include "PageCollection/MainPage.h"

class PageControl {

  // Add PageKey if you add a new page
  enum PageKey {
    MainPageKey
  };

  public:
    PageControl();
    ~PageControl();

  private:
    Page *pages[TotalPage];
};

#endif
