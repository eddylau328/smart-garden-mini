#include "ManualSettingPage.h"

ManualSettingPage::ManualSettingPage(){
   input.setLinkage(&staticContents[InputIndex::Second]);
   input.setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void ManualSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 6);

  toggleArrowContent(InputIndex::Second);

  int second;
  input.set((int8_t)second, 0, 20, true);
  input.startBlink();

  scroll.resetScroll(contents, contentSize);
  
}

void ManualSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void ManualSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow && isPress)
    processActions(counter, isPress);
  else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
  else
    processInputAction(counter, isPress);
}

void ManualSettingPage::processActions(int counter, bool isPress) {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  if (row == RowIndex::Fire && !WaterController::getIsWaterPumpOn()) {
    processFireAction();
    toggleArrowContent(InputIndex::Second);
  }
  else
    processReturnAction(counter, isPress);
}

void ManualSettingPage::processFireAction() {
  WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
  ManualModeSetting setting = manager->getManualModeSetting();
  int8_t second = input.getInputValue();
  setting.setTurnOnDuration((uint8_t) second);
  setting.setIsTurnOnWaterPump(true);
  manager->setManualModeSetting(setting);
}

void ManualSettingPage::processReturnAction(int counter, bool isPress) {
  Page::interactiveUpdate(counter, isPress);
}

void ManualSettingPage::processInputAction(int counter, bool isPress) {
  bool isFinish = input.interactiveUpdate(counter, isPress);
  if (isFinish)
    toggleArrowContent(InputIndex::Arrow);
}

void ManualSettingPage::toggleArrowContent(InputIndex index) {
  inputIndex = index;
  if (index == InputIndex::Second)
    staticContents[InputIndex::Arrow].updateContent(" ", 1);
  else
    staticContents[InputIndex::Arrow].updateContent(">", 1);
}