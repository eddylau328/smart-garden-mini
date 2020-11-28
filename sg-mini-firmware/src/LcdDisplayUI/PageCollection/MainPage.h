#ifndef MainPage_h
#define MainPage_h

#include "Page.h"

class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent *contents, uint8_t *length);

  private:
    PageContent contents[2] = {
      PageContent("Smart Garden Mini", 17, PageContent::ContentType::Constant, PageLayoutPosition(0, 0)),
      PageContent("beta version", 12, PageContent::ContentType::Constant, PageLayoutPosition(0, 1))
    };
};

#endif