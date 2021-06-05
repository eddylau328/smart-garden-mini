#include "SettingPage.h"

SettingPage::SettingPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 6));
  scroll.setCursor(&staticContents[7], 0);
}

void SettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 8);
  scroll.resetScroll(contents, contentSize);
}

void SettingPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    switch (index) {
      case RowIndex::DateTime:
        LOG_ERROR("Enter DateTime Setting");
        Page::nextPageCallback(PageCollection::PageKey::DateSettingPageKey);
        break;
      case RowIndex::Wifi:
        LOG_ERROR("Enter WiFi Setting");
        Page::nextPageCallback(PageCollection::PageKey::WifiSettingPageKey);
        break;
      case RowIndex::Watering:
        LOG_ERROR("Enter Watering Setting");
        Page::nextPageCallback(PageCollection::PageKey::ControlPagePageKey);
        break;
      case RowIndex::IdleTime:
        LOG_ERROR("Enter Idle Time Setting");
        break;
      case RowIndex::Username:
        LOG_ERROR("Enter User Name Setting");
        Page::nextPageCallback(PageCollection::PageKey::UsernameSettingPageKey);
        break;
      case RowIndex::Restore:
        LOG_ERROR("Enter Restore Setting");
        Page::nextPageCallback(PageCollection::PageKey::RestoreDefaultPageKey);
        break;
      case RowIndex::Return:
        LOG_ERROR("Return");
        Page::nextPageCallback(Page::defaultPageKey);
        break;
      default:
        Page::nextPageCallback(Page::defaultPageKey);
        break;
    }
  }
}