#include "WifiNamePage.h"

WifiNamePage::WifiNamePage() {
  input.setLinkage(&staticContents[InputIndex::Name]);
  input.setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void WifiNamePage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);
  input.init(8, 15);
  input.startBlink();
  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Name;
  scroll.resetScroll(contents, contentSize);
}

void WifiNamePage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void WifiNamePage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int length;
        char *wifiName;
        input.getInputValue(&wifiName, &length);
        AccessPointSetting accessPointSetting = TempStorage::getAccessPointSetting();
        accessPointSetting.setAccessPointName(wifiName, length);
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

void WifiNamePage::dismountPage() {
  input.destroy();
  Page::dismountPage();
}