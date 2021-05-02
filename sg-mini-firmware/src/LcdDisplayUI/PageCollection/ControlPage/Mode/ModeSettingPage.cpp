#include "ModeSettingPage.h"

void ModeSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 4);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 2));
  scroll.setCursor(&staticContents[3], 0);
}

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
          Page::nextPageCallback(PageCollection::PageKey::ScheduleSettingPageKey);
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

