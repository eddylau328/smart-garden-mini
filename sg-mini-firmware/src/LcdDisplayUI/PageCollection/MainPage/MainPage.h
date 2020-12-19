#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../../DeviceSetting/DeviceSetting.h"

class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();

  private:
    PageContent contents[2] = {
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 0)),
      PageContent()
    };
};

#endif