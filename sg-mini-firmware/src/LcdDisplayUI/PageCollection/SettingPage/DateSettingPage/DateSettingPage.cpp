#include "DateSettingPage.h"

DateSettingPage::DateSettingPage() {
  input[InputIndex::Year].setLinkage(&staticContents[InputIndex::Year]);
  input[InputIndex::Month].setLinkage(&staticContents[InputIndex::Month]);
  input[InputIndex::DayOfMonth].setLinkage(&staticContents[InputIndex::DayOfMonth]);
  input[InputIndex::DayOfWeek].setLinkage(&staticContents[InputIndex::DayOfWeek]);

  input[InputIndex::Year].setCircleLoop(true);
  input[InputIndex::Month].setCircleLoop(true);
  input[InputIndex::DayOfMonth].setCircleLoop(true);
  input[InputIndex::DayOfWeek].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

DateSettingPage::~DateSettingPage() {}

void DateSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 11);

  int year, month, dayOfMonth, dayOfWeek;
  DeviceSetting::getDate(&year, &month, &dayOfMonth, &dayOfWeek);
  input[InputIndex::Year].set((int8_t)(year-2000), 0, 99, true);
  input[InputIndex::Month].set((int8_t)month, 1, 12, true);
  input[InputIndex::DayOfMonth].set((int8_t)dayOfMonth, 1, 31, true);
  input[InputIndex::DayOfWeek].set((int8_t)dayOfWeek, 1, 7, true);

  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Year;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  changeTopic();
}

void DateSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void DateSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int year, month, dayOfMonth, dayOfWeek;
        year = input[InputIndex::Year].getInputValue() + 2000;
        month = input[InputIndex::Month].getInputValue();
        dayOfMonth = input[InputIndex::DayOfMonth].getInputValue();
        dayOfWeek = input[InputIndex::DayOfWeek].getInputValue();
        DeviceSetting::setDate(year, month, dayOfMonth, dayOfWeek);
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
        staticContents[InputIndex::Arrow].updateContent(">", 1);
      else {
        if (inputIndex == InputIndex::DayOfMonth) {
          int year, month, dayOfMonth;
          year = input[InputIndex::Year].getInputValue() + 2000;
          month = input[InputIndex::Month].getInputValue();
          dayOfMonth = input[InputIndex::DayOfMonth].getInputValue();
          if (month == 2) {
            if (Helper::isLeapYear(year))
              input[inputIndex].set((int8_t)min(dayOfMonth, 29), 1, 29);
            else
              input[inputIndex].set((int8_t)min(dayOfMonth, 28), 1, 28);
          }
          else {
            if (month == 4 || month == 6 || month == 9 || month == 11) 
              input[inputIndex].set((int8_t)min(dayOfMonth, 30), 1, 30);
            else
              input[inputIndex].set((int8_t)min(dayOfMonth, 31), 1, 31);
          }
        }
        input[inputIndex].startBlink();
      }
      changeTopic();
    }
  }
}

void DateSettingPage::changeTopic() {
  switch(inputIndex) {
    case InputIndex::Year:
      staticContents[5].updateContent("Set Year", 8);
      break;
    case InputIndex::Month:
      staticContents[5].updateContent("Set Month", 9);
      break;
    case InputIndex::DayOfMonth:
      staticContents[5].updateContent("Set Day", 7);
      break;
    case InputIndex::DayOfWeek:
      staticContents[5].updateContent("Mon=1 Sun=7", 11);
      break;
    case InputIndex::Arrow:
      staticContents[5].updateContent("Set Date", 8);
      break;
  }
}