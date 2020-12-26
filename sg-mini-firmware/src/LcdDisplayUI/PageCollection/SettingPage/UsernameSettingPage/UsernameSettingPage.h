#ifndef UsernameSettingPage_h
#define UsernameSettingPage_h

#include "../../Page.h"
#include "../../../../DeviceSetting/DeviceSetting.h"
#include "../../../Components/Input/InputAlphabet/InputAlphabet.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../Storage/StorageConstant.h"
class UsernameSettingPage : public Page {
  public:
    UsernameSettingPage();
    ~UsernameSettingPage();

    void mountPage();
    void getContents(PageContent **contents, int *length);
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum InputIndex {
      Name = 0,
      Arrow = 1
    };

    const int8_t contentSize = 7;
    PageContent contents[7] = {
      PageContent(UserNameLength, PageLayoutPosition(1, 1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent("Set Name", 8, PageLayoutPosition(0, 0)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
      PageContent("[", 1, PageLayoutPosition(0, 1)),
      PageContent("]", 1, PageLayoutPosition(9, 1))
    };
    int8_t inputIndex;

    InputAlphabet input;
    PageVerticalScroll scroll;

    void changeTopic();
};

#endif