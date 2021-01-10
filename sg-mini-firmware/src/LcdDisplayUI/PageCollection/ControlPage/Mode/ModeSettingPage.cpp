#include "ModeSettingPage.h"

ModeSettingPage::ModeSettingPage(){}

void ModeSettingPage::mountPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 6));
  scroll.setCursor(&contents[3], 0);
}

ModeSettingPage::~ModeSettingPage(){

}

void ModeSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void ModeSettingPage::updateContents() {}

void ModeSettingPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
      int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
      switch (index) {
        case 0:
          LOG_ERROR("Enter Auto Setting");
          Page::nextPageCallback(PageCollection::PageKey::AutoSettingPageKey);
          break;
        case 1:
          LOG_ERROR("Enter Schedule Setting");
          Page::nextPageCallback(PageCollection::PageKey::ManualSettingPageKey);
          break;
        case 2:
          LOG_ERROR("Return");
          Page::nextPageCallback(Page::defaultPageKey);
          break;
        default:
          Page::nextPageCallback(Page::defaultPageKey);
          break;
}
  }
}

