#include "UsernameSettingPage.h"

UsernameSettingPage::UsernameSettingPage() {
  input.setLinkage(&staticContents[InputIndex::Name]);
  input.setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void UsernameSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 7);

  LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
  const char* name = localSettingManager->getUsername();
  input.set(name, USERNAME_LENGTH);

  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Name;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
}

void UsernameSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void UsernameSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
        localSettingManager->setUsername(input.getInputValue());
      }
      Page::interactiveUpdate(counter, isPress);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input.interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        staticContents[InputIndex::Arrow].updateContent(">", 1);
    }
  }
}