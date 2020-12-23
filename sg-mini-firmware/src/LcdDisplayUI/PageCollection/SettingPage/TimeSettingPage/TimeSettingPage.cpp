#include "TimeSettingPage.h"

TimeSettingPage::TimeSettingPage() {
  input[InputIndex::Hour].setLinkage(&contents[InputIndex::Hour]);
  input[InputIndex::Minute].setLinkage(&contents[InputIndex::Minute]);
  input[InputIndex::Second].setLinkage(&contents[InputIndex::Second]);

  input[InputIndex::Hour].setCircleLoop(true);
  input[InputIndex::Minute].setCircleLoop(true);
  input[InputIndex::Second].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&contents[3], 1);
}

TimeSettingPage::~TimeSettingPage() {}

void TimeSettingPage::mountPage() {
  int hour, minute, second;
  DeviceSetting::getTime(&hour, &minute, &second);
  input[InputIndex::Hour].set((int8_t)hour, 0, 23, true);
  input[InputIndex::Minute].set((int8_t)minute, 0, 59, true);
  input[InputIndex::Second].set((int8_t)second, 0, 59, true);
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Hour;
  scroll.resetScroll(contents, contentSize);
}

void TimeSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void TimeSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      LOG_ERROR(row);
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
    }
  }
}