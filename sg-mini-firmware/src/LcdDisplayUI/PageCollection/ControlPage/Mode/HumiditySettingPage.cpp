#include "HumiditySettingPage.h"

HumiditySettingPage::HumiditySettingPage(){
   input.setLinkage(&staticContents[InputIndex::Humidity]);
   input.setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void HumiditySettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 6);

  toggleArrowContent(InputIndex::Humidity);

  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  HumidityModeSetting modeSetting = settingManager->getHumidityModeSetting();
  int8_t humidity = (int8_t) modeSetting.getTargetHumidity();
  input.set(humidity, 0, 99, true);
  input.startBlink();

  scroll.resetScroll(contents, contentSize);
}

void HumiditySettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void HumiditySettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow && isPress)
    processActions(counter, isPress);
  else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
  else
    processInputAction(counter, isPress);
}

void HumiditySettingPage::updateHumidityModeSetting() {
  uint8_t targetHumidity = (uint8_t) input.getInputValue();
  HumidityModeSetting setting = HumidityModeSetting(
    targetHumidity, 
    max(targetHumidity - 10, 0), 
    min(targetHumidity + 10, 99)
  );
  WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
  manager->setHumidityModeSetting(setting);
}

void HumiditySettingPage::processActions(int counter, bool isPress) {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  if (row == 1)
    updateHumidityModeSetting();
  Page::interactiveUpdate(counter, isPress);  
}

void HumiditySettingPage::processInputAction(int counter, bool isPress) {
  bool isFinish = input.interactiveUpdate(counter, isPress);
  if (isFinish)
    toggleArrowContent(InputIndex::Arrow);
}

void HumiditySettingPage::toggleArrowContent(InputIndex index) {
  inputIndex = index;
  if (inputIndex == InputIndex::Arrow)
    staticContents[InputIndex::Arrow].updateContent(">", 1);
  else
    staticContents[InputIndex::Arrow].updateContent(" ", 1);
}