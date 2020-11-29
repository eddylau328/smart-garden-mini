#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"

class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);

  private:
    PageContent contents[1] = {
      PageContent("SG Mini beta", 12, PageContent::ContentType::Constant, PageLayoutPosition(0, 0)),
    };
};

#endif