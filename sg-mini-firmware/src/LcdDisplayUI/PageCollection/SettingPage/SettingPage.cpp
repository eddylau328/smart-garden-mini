#include "SettingPage.h"
#include "../../PageControl.h"

SettingPage::SettingPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 6));
  scroll.setCursor(&contents[7], 0);
}

SettingPage::~SettingPage() {
}

void SettingPage::mountPage() {
  scroll.resetScroll(contents, 7);
}

void SettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void SettingPage::updateContents() {
  // if sensors pointer is not null

}

void SettingPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, 7, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, 7);
    switch (index) {
      case 0:
        LOG_ERROR("Enter Time Setting");
        break;
      case 1:
        LOG_ERROR("Enter Date Setting");
        break;
      case 2:
        LOG_ERROR("Enter WiFi Setting");
        break;
      case 3:
        LOG_ERROR("Enter Watering Setting");
        break;
      case 4:
        LOG_ERROR("Enter Idle Time Setting");
        break;
      case 5:
        LOG_ERROR("Enter User Name Setting");
        break;
      case 6:
        LOG_ERROR("Return");
        Page::nextPageCallback(Page::defaultPageKey);
        break;
      default:
        Page::nextPageCallback(Page::defaultPageKey);
        break;
    }
  }
}