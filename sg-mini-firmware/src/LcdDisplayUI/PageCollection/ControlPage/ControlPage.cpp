#include "ControlPage.h"

ControlPage::ControlPage(){
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 2));
  scroll.setCursor(&staticContents[CURSOR_INDEX], 0);
}

void ControlPage::mountPage() {
  Page::allocateStaticContents(staticContents, 5);
  scroll.resetScroll(contents, contentSize);
  setupWaterMode();
}


void ControlPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    switch (index) {
      case RowIndex::Mode:
        LOG_ERROR("Enter Mode Setting");
        Page::nextPageCallback(PageCollection::PageKey::ModeSettingPageKey); 
        break;
      case RowIndex::ModeSetting:
        LOG_ERROR("Enter Water Setting");
        Page::nextPageCallback(waterModeSettingPageKey); 
        break;
      case RowIndex::Return:
        LOG_ERROR("Go Back to Setting Page");
        Page::nextPageCallback(PageCollection::PageKey::SettingPageKey); 
        break;
      default:
        Page::nextPageCallback(Page::defaultPageKey);
        break;
    }
  }
}

void ControlPage::setupWaterMode() {
  WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
  WaterControllerConstant::WaterMode waterMode = manager->getWaterMode();
  switch (waterMode) {
    case WaterControllerConstant::WaterMode::ManualMode:
      staticContents[MODE_NAME_INDEX].updateContent("Manual", 6);
      waterModeSettingPageKey = PageCollection::PageKey::ManualSettingPageKey;
      break;
    case WaterControllerConstant::WaterMode::HumidityMode:
      staticContents[MODE_NAME_INDEX].updateContent("Humidity", 8);
      waterModeSettingPageKey = PageCollection::PageKey::HumiditySettingPageKey;
      break;
    case WaterControllerConstant::WaterMode::ScheduleMode:
      staticContents[MODE_NAME_INDEX].updateContent("Schedule", 8);
      waterModeSettingPageKey = PageCollection::PageKey::ScheduleSettingPageKey;
      break;
  }
}