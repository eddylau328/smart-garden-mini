#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../UI/Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent contents[6] = {
      PageContent("SG Mini beta 1", 14, PageLayoutPosition(0, 0)),
      PageContent("SG Mini beta 2", 14, PageLayoutPosition(0, 1)),
      PageContent("SG Mini beta 3", 14, PageLayoutPosition(0, 2)),
      PageContent("SG Mini beta 4", 14, PageLayoutPosition(0, 3)),
      PageContent("SG Mini beta 5", 14, PageLayoutPosition(0, 4)),
      PageContent("SG Mini beta 6", 14, PageLayoutPosition(0, 5)),
    };

    PageVerticalScroll scroll;
};

#endif