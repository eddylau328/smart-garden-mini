#ifndef ConfirmRestorePage_h
#define ConfirmRestorePage_h

#include "../../Page.h"
#include "../../../../DeviceSetting/SettingManager/SetupSettingManager/SetupSettingManager.h"
#include "../../../Components/CountDownTimer/CountDownTimer.h"

/**
 * @brief Page derived class use to restore page and force to restart the system
 * 
 */
class ConfirmRestorePage : public Page {
  public:
    void mountPage();
    void updateContents();

  private:
    enum ContentIndex {
        SecondCounter = 1,
    };

    PageContent staticContents[2] = {
      PageContent("Restart in", 10, PageLayoutPosition(0,0)),
      PageContent(1, PageLayoutPosition(11, 0))
    };

    CountDownTimer countDownTimer;
};

#endif