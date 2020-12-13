#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../UI/Components/PageScroll/PageHorizontalScroll/PageHorizontalScroll.h"
class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent contents[4] = {
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 0)),
      PageContent("SG Mini beta", 12, PageLayoutPosition(14, 0)),
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 1)),
      PageContent("SG Mini beta", 12, PageLayoutPosition(14, 1)),
    };

    PageHorizontalScroll scroll;
};

#endif