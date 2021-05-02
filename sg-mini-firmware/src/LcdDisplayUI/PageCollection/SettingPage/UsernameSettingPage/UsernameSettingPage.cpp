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

  char *name;
  int length;
  DeviceSetting::getUserName(&name, &length);
  input.set(name, UserNameLength);
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
      if (row == 1)
        DeviceSetting::setUserName(input.getInputValue(), UserNameLength);
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