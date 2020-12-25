#include "DateSettingPage.h"

DateSettingPage::DateSettingPage() {
  input[InputIndex::Year].setLinkage(&contents[InputIndex::Year]);
  input[InputIndex::Month].setLinkage(&contents[InputIndex::Month]);
  input[InputIndex::DayOfMonth].setLinkage(&contents[InputIndex::DayOfMonth]);
  input[InputIndex::DayOfWeek].setLinkage(&contents[InputIndex::DayOfWeek]);

  input[InputIndex::Year].setCircleLoop(true);
  input[InputIndex::Month].setCircleLoop(true);
  input[InputIndex::DayOfMonth].setCircleLoop(true);
  input[InputIndex::DayOfWeek].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

DateSettingPage::~DateSettingPage() {}

void DateSettingPage::mountPage() {
  int year, month, dayOfMonth, dayOfWeek;
  DeviceSetting::getDate(&year, &month, &dayOfMonth, &dayOfWeek);
  input[InputIndex::Year].set((int8_t)(year-2000), 0, 99, true);
  input[InputIndex::Month].set((int8_t)month, 1, 12, true);
  input[InputIndex::DayOfMonth].set((int8_t)dayOfMonth, 1, 31, true);
  input[InputIndex::DayOfWeek].set((int8_t)dayOfWeek, 1, 7, true);

  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Year;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  changeTopic();
}

void DateSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
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
        Helper::convertStrToNum(contents[InputIndex::Year].getContent(), year);
        year += 2000;
        Helper::convertStrToNum(contents[InputIndex::Month].getContent(), month);
        Helper::convertStrToNum(contents[InputIndex::DayOfMonth].getContent(), dayOfMonth);
        Helper::convertStrToNum(contents[InputIndex::DayOfWeek].getContent(), dayOfWeek);
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
        contents[InputIndex::Arrow].updateContent(">", 1);
      else {
        if (inputIndex == InputIndex::DayOfMonth) {
          int year, month, dayOfMonth;
          Helper::convertStrToNum(contents[InputIndex::Year].getContent(), year);
          year += 2000;
          Helper::convertStrToNum(contents[InputIndex::Month].getContent(), month);
          Helper::convertStrToNum(contents[InputIndex::DayOfMonth].getContent(), dayOfMonth);
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
      contents[5].updateContent("Set Year", 8);
      break;
    case InputIndex::Month:
      contents[5].updateContent("Set Month", 9);
      break;
    case InputIndex::DayOfMonth:
      contents[5].updateContent("Set Day", 7);
      break;
    case InputIndex::DayOfWeek:
      contents[5].updateContent("Mon=1 Sun=7", 11);
      break;
    case InputIndex::Arrow:
      contents[5].updateContent("Set Date", 8);
      break;
  }
}