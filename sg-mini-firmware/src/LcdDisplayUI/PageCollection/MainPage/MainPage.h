#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();

  private:
    PageContent contents[1] = {
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 0)),
    };
};

#endif