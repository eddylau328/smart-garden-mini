#include "ScheduleSettingPage.h"

ScheduleSettingPage::ScheduleSettingPage() {
  input[InputIndex::Hour].setLinkage(&staticContents[InputIndex::Hour]);
  input[InputIndex::Minute].setLinkage(&staticContents[InputIndex::Minute]);
  input[InputIndex::Second].setLinkage(&staticContents[InputIndex::Second]);

  input[InputIndex::Hour].setCircleLoop(true);
  input[InputIndex::Minute].setCircleLoop(true);
  input[InputIndex::Second].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void ScheduleSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 9);

  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  ScheduleModeSetting modeSetting = settingManager->getScheduleModeSetting();
  unsigned long duration = modeSetting.getScheduleDuration();
  Serial.print("Get duration ");
  Serial.println(duration);
  int8_t hour, minute, second;
  hour = (int8_t) (duration / 3600);
  minute = (int8_t) ((duration - (unsigned long)hour * 3600) / 60);
  second = (int8_t) (duration - (unsigned long)hour * 3600 - (unsigned long)minute * 60);

  input[InputIndex::Hour].set((int8_t)hour, 0, 23, true);
  input[InputIndex::Minute].set((int8_t)minute, 0, 59, true);
  input[InputIndex::Second].set((int8_t)second, 0, 59, true);

  staticContents[InputIndex::Arrow].updateContent(" ", 1);

  inputIndex = InputIndex::Hour;

  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  changeTopic();
}

void ScheduleSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void ScheduleSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1)
        updateScheduleModeSetting();
      Page::interactiveUpdate(counter, isPress);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input[inputIndex].interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        staticContents[InputIndex::Arrow].updateContent(">", 1);
      else
        input[inputIndex].startBlink();
      changeTopic();
    }
  }
}

void ScheduleSettingPage::changeTopic() {
  switch(inputIndex) {
    case InputIndex::Hour:
      staticContents[4].updateContent("Set Hour", 8);
      break;
    case InputIndex::Minute:
      staticContents[4].updateContent("Set Minute", 10);
      break;
    case InputIndex::Second:
      staticContents[4].updateContent("Set Second", 10);
      break;
    case InputIndex::Arrow:
      staticContents[4].updateContent("Time2Water", 10);
      break;
  }
}

void ScheduleSettingPage::updateScheduleModeSetting() {
  int8_t hour = input[InputIndex::Hour].getInputValue();
  int8_t minute = input[InputIndex::Minute].getInputValue();
  int8_t second = input[InputIndex::Second].getInputValue();

  unsigned long duration = 0;
  duration += (unsigned long)hour * 3600;
  duration += (unsigned long)minute * 60;
  duration += (unsigned long)second;

  ScheduleModeSetting modeSetting(duration, 0);
  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  settingManager->setScheduleModeSetting(modeSetting);
}