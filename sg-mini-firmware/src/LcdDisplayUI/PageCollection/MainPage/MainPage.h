#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent contents[1] = {
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 0)),
    };
};

#endif