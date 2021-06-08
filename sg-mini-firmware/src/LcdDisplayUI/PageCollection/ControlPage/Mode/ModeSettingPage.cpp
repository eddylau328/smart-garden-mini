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
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
    WaterControllerConstant::WaterMode target;
    switch (index) {
      case RowIndex::Manual:
        LOG_ERROR("Set to manual");
        target = WaterControllerConstant::WaterMode::ManualMode;
        break;
      case RowIndex::Humidity:
        LOG_ERROR("Set to humidity");
        target = WaterControllerConstant::WaterMode::HumidityMode;
        break;
      case RowIndex::Schedule:
        LOG_ERROR("Enter Schedule Setting");
        target = WaterControllerConstant::WaterMode::ScheduleMode;
       break;
    }
    bool isAllowSet = WaterController::setMode(target);
    if (isAllowSet)
      manager->setWaterMode(target);
    Page::interactiveUpdate(counter, isPress);
  }
  else
    scroll.updateScroll(contents, contentSize, counter);
}