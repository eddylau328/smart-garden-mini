#include "HumiditySettingPage.h"

HumiditySettingPage::HumiditySettingPage(){
    input[InputIndex::TargetHumidity].setLinkage(
       &staticContents[InputIndex::TargetHumidity]
    );
    input[InputIndex::TargetHumidity].setCircleLoop(true);
    input[InputIndex::MinHumidity].setLinkage(
       &staticContents[InputIndex::MinHumidity]
    );
    input[InputIndex::MinHumidity].setCircleLoop(true);
    input[InputIndex::MaxHumidity].setLinkage(
       &staticContents[InputIndex::MaxHumidity]
    );
    input[InputIndex::MaxHumidity].setCircleLoop(true);

    scroll.init(LCDScreenWidth, LCDScreenHeight);
    scroll.setCoverArea(PageLayoutRange(0, 4));
    scroll.setCursor(&staticContents[InputIndex::Arrow], 0);
}

void HumiditySettingPage::mountPage() {
    Page::allocateStaticContents(staticContents, 9);

    toggleArrowContent(InputIndex::Arrow);

    WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
    HumidityModeSetting modeSetting = settingManager->getHumidityModeSetting();
    int8_t targetHumidity = (int8_t) modeSetting.getTargetHumidity();
    int8_t minHumidity = (int8_t) modeSetting.getMinHumidity();
    int8_t maxHumidity = (int8_t) modeSetting.getMaxHumidity();
    updateInputHumidityRange(targetHumidity, minHumidity, maxHumidity);

    scroll.resetScroll(contents, contentSize);
}

void HumiditySettingPage::updateContents() {
    if (inputIndex != InputIndex::Arrow)
        input[inputIndex].blinkUpdate();
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
    uint8_t targetHumidity = (uint8_t) input[InputIndex::TargetHumidity].getInputValue();
    uint8_t minHumidity = (uint8_t) input[InputIndex::MinHumidity].getInputValue();
    uint8_t maxHumidity = (uint8_t) input[InputIndex::MaxHumidity].getInputValue();
    HumidityModeSetting setting = HumidityModeSetting(
        targetHumidity, 
        minHumidity, 
        maxHumidity
    );
    WaterSettingManager *manager = DeviceManager::getWaterSettingManager();
    manager->setHumidityModeSetting(setting);
}

void HumiditySettingPage::processActions(int counter, bool isPress) {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  switch (row) {
      case RowIndex::TargetHumidityRow:
        toggleArrowContent(InputIndex::TargetHumidity);
        break;
      case RowIndex::MinHumidityRow:
        toggleArrowContent(InputIndex::MinHumidity);
        break;
      case RowIndex::MaxHumidityRow:
        toggleArrowContent(InputIndex::MaxHumidity);
        break;
      case RowIndex::SaveRow:
        updateHumidityModeSetting();
        break;
      case RowIndex::ReturnRow:
        Page::interactiveUpdate(counter, isPress);  
        break;
  }
}

void HumiditySettingPage::processInputAction(int counter, bool isPress) {
  bool isFinish = input[inputIndex].interactiveUpdate(counter, isPress);
  if (isFinish) {
    toggleArrowContent(InputIndex::Arrow);
    updateInputHumidityRange(
        input[InputIndex::TargetHumidity].getInputValue(),
        input[InputIndex::MinHumidity].getInputValue(),
        input[InputIndex::MaxHumidity].getInputValue()
    );
  }
}

void HumiditySettingPage::toggleArrowContent(InputIndex index) {
  inputIndex = index;
  if (inputIndex == InputIndex::Arrow)
    staticContents[InputIndex::Arrow].updateContent(">", 1);
  else {
    staticContents[InputIndex::Arrow].updateContent("~", 1);
    input[inputIndex].startBlink();
  }
}

void HumiditySettingPage::updateInputHumidityRange(int8_t target, int8_t min, int8_t max) {
  input[InputIndex::MinHumidity].set(min, 0, target, true);
  input[InputIndex::MaxHumidity].set(max, target, 99, true);
  input[InputIndex::TargetHumidity].set(target, min, max, true);
}