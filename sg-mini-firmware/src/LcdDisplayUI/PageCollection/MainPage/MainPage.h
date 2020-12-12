#ifndef MainPage_h
#define MainPage_h

#include "../Page.h"
#include "../../UI/Components/Input/InputAscii/InputAscii.h"

class MainPage : public Page {
  public:
    MainPage();
    ~MainPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent contents[2] = {
      PageContent("SG Mini beta", 12, PageLayoutPosition(0, 0)),
      PageContent("", 3, PageLayoutPosition(0, 1))
    };

    InputAscii input;

};

#endif