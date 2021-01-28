#include "ControlPage.h"

ControlPage::ControlPage(){
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 2));
  scroll.setCursor(&contents[3], 0);
}

ControlPage::~ControlPage(){

}

void ControlPage::mountPage() {
    scroll.resetScroll(contents, contentSize);
}

void ControlPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void ControlPage::updateContents() {}

void ControlPage::interactiveUpdate(int counter, bool isPress) {
    scroll.updateScroll(contents, contentSize, counter);
    if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    switch (index) {
      case 0:
        LOG_ERROR("Enter Mode Setting");
        Page::nextPageCallback(PageCollection::PageKey::ModeSettingPageKey); 
        break;
      case 1:
        LOG_ERROR("Enter Manual Setting");
        Page::nextPageCallback(PageCollection::PageKey::ManualSettingPageKey); 
        break;
      case 2:
        LOG_ERROR("Go Back to Setting Page");
        Page::nextPageCallback(PageCollection::PageKey::SettingPageKey); 
        break;
      default:
        Page::nextPageCallback(Page::defaultPageKey);
        break;
}
    }
}

