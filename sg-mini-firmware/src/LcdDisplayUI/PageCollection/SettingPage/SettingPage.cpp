#include "SettingPage.h"

SettingPage::SettingPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 5));
  scroll.setCursor(&contents[6], 0);
}

SettingPage::~SettingPage() {
}

void SettingPage::mountPage() {
  scroll.resetScroll(contents, contentSize);
}

void SettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void SettingPage::updateContents() {
  // if sensors pointer is not null

}

void SettingPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, 6, counter);
  Page::interactiveUpdate(counter, isPress);
}