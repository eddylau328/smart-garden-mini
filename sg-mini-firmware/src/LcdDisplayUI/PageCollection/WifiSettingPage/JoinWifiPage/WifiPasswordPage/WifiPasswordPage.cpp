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
  input.init(8, 15);
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
        char *wifiPassword;
        input.getInputValue(&wifiPassword, &length);
        AccessPointSetting accessPointSetting = TempStorage::getAccessPointSetting();
        accessPointSetting.setAccessPointPassword(wifiPassword, length);
        TempStorage::setAccessPointSetting(accessPointSetting);
        Page::interactiveUpdate(counter, isPress);
      }
      else
        Page::nextPageCallback(PageCollection::PageKey::WifiSettingPageKey);
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