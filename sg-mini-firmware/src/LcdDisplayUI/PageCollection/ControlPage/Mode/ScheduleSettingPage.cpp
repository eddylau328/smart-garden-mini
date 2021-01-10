#include "ScheduleSettingPage.h"

ScheduleSettingPage::ScheduleSettingPage() {
  input[InputIndex::Hour].setLinkage(&contents[InputIndex::Hour]);
  input[InputIndex::Minute].setLinkage(&contents[InputIndex::Minute]);
  input[InputIndex::Second].setLinkage(&contents[InputIndex::Second]);

  input[InputIndex::Hour].setCircleLoop(true);
  input[InputIndex::Minute].setCircleLoop(true);
  input[InputIndex::Second].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

ScheduleSettingPage::~ScheduleSettingPage() {}

void ScheduleSettingPage::mountPage() {
  int hour, minute, second;

  input[InputIndex::Hour].set((int8_t)hour, 0, 23, true);
  input[InputIndex::Minute].set((int8_t)minute, 0, 59, true);
  input[InputIndex::Second].set((int8_t)second, 0, 59, true);
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Hour;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  changeTopic();
}

void ScheduleSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void ScheduleSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void ScheduleSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int hour, minute, second;
        hour = input[InputIndex::Hour].getInputValue();
        minute = input[InputIndex::Minute].getInputValue();
        second = input[InputIndex::Second].getInputValue();
        
      }
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
        contents[InputIndex::Arrow].updateContent(">", 1);
      else
        input[inputIndex].startBlink();
      changeTopic();
    }
  }
}

void ScheduleSettingPage::changeTopic() {
  switch(inputIndex) {
    case InputIndex::Hour:
      contents[4].updateContent("Set Hour", 8);
      break;
    case InputIndex::Minute:
      contents[4].updateContent("Set Minute", 10);
      break;
    case InputIndex::Second:
      contents[4].updateContent("Set Second", 10);
      break;
    case InputIndex::Arrow:
      contents[4].updateContent("Time2Water", 10);
      break;
  }
}