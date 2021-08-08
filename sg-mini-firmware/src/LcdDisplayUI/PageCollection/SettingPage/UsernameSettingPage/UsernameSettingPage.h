#ifndef UsernameSettingPage_h
#define UsernameSettingPage_h

#include "../../Page.h"
#include "../../../Components/Input/InputAlphabet/InputAlphabet.h"
#include "../../../Components/PageScroll/PageVerticalScroll/PageVerticalScroll.h"
#include "../../../../Storage/StorageConstant.h"

/**
 * @brief Page derived class use to change the user name 
 * 
 */
class UsernameSettingPage : public Page {
  public:
    UsernameSettingPage();

    void mountPage();
    void updateContents();
    void interactiveUpdate(int counter, bool isPress);

  private:
    enum InputIndex {
      Name = 0,
      Arrow = 1
    };

    PageContent staticContents[7] = {
      PageContent(USERNAME_LENGTH, PageLayoutPosition(1, 1)),
      PageContent(" ", 1, PageLayoutPosition(10, 1)),
      PageContent("Set Name", 8, PageLayoutPosition(0, 0)),
      PageContent("Back", 4, PageLayoutPosition(12, 0)),
      PageContent("Save", 4, PageLayoutPosition(12, 1)),
      PageContent("[", 1, PageLayoutPosition(0, 1)),
      PageContent("]", 1, PageLayoutPosition(9, 1))
    };

    InputIndex inputIndex;

    InputAlphabet input;
    PageVerticalScroll scroll;

    void proceedNextPage(int counter, bool isPress);
    void proceedSetupNextPage();
    void inputInteractiveUpdate(int counter, bool isPress);

    void storeUsername();
    bool shouldStoreUsername();
};

#endif