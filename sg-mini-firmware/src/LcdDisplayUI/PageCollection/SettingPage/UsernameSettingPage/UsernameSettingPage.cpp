#include "UsernameSettingPage.h"

UsernameSettingPage::UsernameSettingPage() {
  input.setLinkage(&contents[InputIndex::Name]);
  input.setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

UsernameSettingPage::~UsernameSettingPage() {}

void UsernameSettingPage::mountPage() {
  char *name;
  int length;
  DeviceSetting::getUserName(&name, &length);
  input.set(name, (int8_t)length);
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Name;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
}

void UsernameSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
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
        DeviceSetting::setUserName(input.getInputValue(), 8);
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
        contents[InputIndex::Arrow].updateContent(">", 1);
    }
  }
}