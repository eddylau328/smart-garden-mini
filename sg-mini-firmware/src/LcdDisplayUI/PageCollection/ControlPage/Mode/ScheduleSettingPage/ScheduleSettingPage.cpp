#include "ScheduleSettingPage.h"

ScheduleSettingPage::ScheduleSettingPage() {
  input[InputIndex::Hour].setLinkage(&staticContents[InputIndex::Hour]);
  input[InputIndex::Minute].setLinkage(&staticContents[InputIndex::Minute]);
  input[InputIndex::Second].setLinkage(&staticContents[InputIndex::Second]);
  input[InputIndex::TargetHumidity].setLinkage(&staticContents[InputIndex::TargetHumidity]);

  input[InputIndex::Hour].setCircleLoop(true);
  input[InputIndex::Minute].setCircleLoop(true);
  input[InputIndex::Second].setCircleLoop(true);
  input[InputIndex::TargetHumidity].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 3));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void ScheduleSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 11);

  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  ScheduleModeSetting modeSetting = settingManager->getScheduleModeSetting();
  unsigned long duration = modeSetting.getScheduleDuration();
  int8_t hour, minute, second;
  hour = (int8_t) (duration / 3600);
  minute = (int8_t) ((duration - (unsigned long)hour * 3600) / 60);
  second = (int8_t) (duration - (unsigned long)hour * 3600 - (unsigned long)minute * 60);

  input[InputIndex::Hour].set((int8_t)hour, 0, 23, true);
  input[InputIndex::Minute].set((int8_t)minute, 0, 59, true);
  input[InputIndex::Second].set((int8_t)second, 0, 59, true);

  int8_t targetHumidity = (int8_t) modeSetting.getTargetHumidity();
  input[InputIndex::TargetHumidity].set(targetHumidity, 0, 99);

	toggleInputContent(InputIndex::Arrow);
  scroll.resetScroll(contents, contentSize);
}

void ScheduleSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void ScheduleSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow && isPress)
		processActions(counter, isPress);
	else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
	else
		processInputAction(counter, isPress);
}

void ScheduleSettingPage::updateScheduleModeSetting() {
  int8_t hour = input[InputIndex::Hour].getInputValue();
  int8_t minute = input[InputIndex::Minute].getInputValue();
  int8_t second = input[InputIndex::Second].getInputValue();
	int8_t targetHumidity = input[InputIndex::TargetHumidity].getInputValue();

  unsigned long duration = 0;
  duration += (unsigned long)hour * 3600;
  duration += (unsigned long)minute * 60;
  duration += (unsigned long)second;

  ScheduleModeSetting modeSetting(duration, (uint8_t) targetHumidity);
  WaterSettingManager *settingManager = DeviceManager::getWaterSettingManager();
  settingManager->setScheduleModeSetting(modeSetting);
}

void ScheduleSettingPage::processActions(int counter, bool isPress) {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  switch (row) {
    case RowIndex::DurationRow:
      toggleInputContent(InputIndex::Hour);
      break;
    case RowIndex::TargetHumidityRow:
      toggleInputContent(InputIndex::TargetHumidity);
      break;
    case RowIndex::SaveRow:
			updateScheduleModeSetting();
			Page::interactiveUpdate(counter, isPress);
      break;
    case RowIndex::ReturnRow:
			Page::interactiveUpdate(counter, isPress);
      break;
  }
}

void ScheduleSettingPage::processInputAction(int counter, bool isPress) {
  bool isFinish = input[inputIndex].interactiveUpdate(counter, isPress);
	if (!isFinish) return;

	InputIndex updateIndex;
  if (inputIndex == InputIndex::Hour)
		updateIndex = InputIndex::Minute;
	else if (inputIndex == InputIndex::Minute)
		updateIndex = InputIndex::Second;
	else
		updateIndex = InputIndex::Arrow;
	toggleInputContent(updateIndex);
}
 
void ScheduleSettingPage::toggleInputContent(InputIndex index) {
  inputIndex = index;
  if (inputIndex == InputIndex::Arrow)
    staticContents[InputIndex::Arrow].updateContent(">", 1);
  else {
    staticContents[InputIndex::Arrow].updateContent("~", 1);
    input[inputIndex].startBlink();
  }
}