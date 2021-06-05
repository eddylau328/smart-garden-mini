#ifndef SetupFinishPage_h
#define SetupFinishPage_h

#include "../../Page.h"
#include "../../../../DeviceSetting/SettingManager/SetupSettingManager/SetupSettingManager.h"

/**
 * @brief Page derived class use to show setup is finish
 * 
 */
class SetupFinishPage : public Page {
  public:
    void mountPage();
    void interactiveUpdate(int counter, bool isPress);

  private:
    PageContent staticContents[2] = {
      PageContent("Setup is finish", 15, PageLayoutPosition(0,0)),
      PageContent("> next", 6, PageLayoutPosition(10,1)),
    };

};

#endif