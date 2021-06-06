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

  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  HumidityModeSetting modeSetting = settingManager->getHumidityModeSetting();
  int8_t humidity = (int8_t) modeSetting.getTargetHumidity();
  input.set(humidity, 0, 99, true);
  
  staticContents[InputIndex::Arrow].updateContent(" ", 1);

  inputIndex = InputIndex::Humidity;
  input.startBlink();

  scroll.resetScroll(contents, contentSize);
}

void HumiditySettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void HumiditySettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        updateHumidityModeSetting();
        Page::interactiveUpdate(counter, isPress);  
      }
      else
        Page::nextPageCallback(PageCollection::PageKey::ModeSettingPageKey);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input.interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        staticContents[InputIndex::Arrow].updateContent(">", 1);
      else
        input.startBlink();
    }
  }
}

void HumiditySettingPage::updateHumidityModeSetting() {
  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  uint8_t humidity = (uint8_t) input.getInputValue();
  HumidityModeSetting modeSetting(
    humidity, 
    min(humidity - 10, 0), 
    min(humidity + 10, 99)
  );
  settingManager->setHumidityModeSetting(modeSetting);
}