#include "WifiPasswordPage.h"

WifiPasswordPage::WifiPasswordPage() {
  input.setLinkage(&staticContents[InputIndex::Password]);
  input.setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void WifiPasswordPage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);
  input.init(8, 20);
  input.startBlink();
  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Password;
  scroll.resetScroll(contents, contentSize);
}

void WifiPasswordPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void WifiPasswordPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int length;
        char *wifiName;
        input.getInputValue(&wifiName, &length);
        TempStorage::setSelectWifiName(wifiName, length);
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

void WifiPasswordPage::dismountPage() {
  input.destroy();
  Page::dismountPage();
}