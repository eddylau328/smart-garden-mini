#include "SetupFinishPage.h"

void SetupFinishPage::mountPage() {
  Page::allocateStaticContents(staticContents, 2);
}

void SetupFinishPage::interactiveUpdate(int counter, bool isPress) {
  if (isPress) {
    SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
    manager->finishSystemReset();
    Page::interactiveUpdate(counter, isPress);
  }
}