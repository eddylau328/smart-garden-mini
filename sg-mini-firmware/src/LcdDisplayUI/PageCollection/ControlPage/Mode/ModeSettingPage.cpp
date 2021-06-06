#include "ModeSettingPage.h"


ModeSettingPage::ModeSettingPage(){
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 3));
  scroll.setCursor(&staticContents[CURSOR_INDEX], 0);
}

void ModeSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 6);
  scroll.resetScroll(contents, contentSize);

  WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
  WaterControllerConstant::WaterMode waterMode = manager->getWaterMode();
  switch (waterMode) {
    case WaterControllerConstant::WaterMode::ManualMode:
      staticContents[INDICATOR_INDEX].updatePos(PageLayoutPosition(12, RowIndex::Manual));
      break;
    case WaterControllerConstant::WaterMode::HumidityMode:
      staticContents[INDICATOR_INDEX].updatePos(PageLayoutPosition(12, RowIndex::Humidity));
      break;
    case WaterControllerConstant::WaterMode::ScheduleMode:
      staticContents[INDICATOR_INDEX].updatePos(PageLayoutPosition(12, RowIndex::Schedule));
      break;
  }
}

void ModeSettingPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
    switch (index) {
      case RowIndex::Manual:
        LOG_ERROR("Enter Manual Setting");
        manager->setWaterMode(WaterControllerConstant::WaterMode::ManualMode);
        break;
      case RowIndex::Humidity:
        LOG_ERROR("Enter Humidity Setting");
        manager->setWaterMode(WaterControllerConstant::WaterMode::HumidityMode);
        break;
      case RowIndex::Schedule:
        LOG_ERROR("Enter Schedule Setting");
        manager->setWaterMode(WaterControllerConstant::WaterMode::ScheduleMode);
        break;
    }
    Page::interactiveUpdate(counter, isPress);
  }
}