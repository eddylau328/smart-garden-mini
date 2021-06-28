#include "DateSettingPage.h"

DateSettingPage::DateSettingPage() {
  input[InputIndex::Year].setLinkage(&staticContents[InputIndex::Year]);
  input[InputIndex::Month].setLinkage(&staticContents[InputIndex::Month]);
  input[InputIndex::DayOfMonth].setLinkage(&staticContents[InputIndex::DayOfMonth]);

  input[InputIndex::Year].setCircleLoop(true);
  input[InputIndex::Month].setCircleLoop(true);
  input[InputIndex::DayOfMonth].setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

DateSettingPage::~DateSettingPage() {}

void DateSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 9);

  LocalSettingManager *manager = DeviceManager::getLocalSettingManager();
  DateTime dateTime = manager->getDeviceDateTime();
  input[InputIndex::Year].set((int8_t)(dateTime.year()-2000), 0, 99, true);
  input[InputIndex::Month].set((int8_t)dateTime.month(), 1, 12, true);
  input[InputIndex::DayOfMonth].set((int8_t)dateTime.day(), 1, 31, true);

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
  if (inputIndex == InputIndex::Arrow && isPress) {
    if (shouldStoreDateTime())
      storeDateTime();
    proceedNextPage(counter, isPress);
  }
  else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
  else
    inputInteractiveUpdate(counter, isPress);
}

void DateSettingPage::proceedNextPage(int counter, bool isPress) {
  SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
  bool isBeginSystemReset = manager->getIsBeginSystemReset();
  if (isBeginSystemReset)
    proceedSystemResetNextPage();
  else
    proceedNormalNextPage(counter, isPress);
}

void DateSettingPage::proceedNormalNextPage(int counter, bool isPress) {
  if (shouldStoreDateTime())
    Page::nextPageCallback(PageCollection::PageKey::TimeSettingPageKey);
  else
    Page::interactiveUpdate(counter, isPress);
}

void DateSettingPage::proceedSystemResetNextPage() {
  if (shouldStoreDateTime())
    Page::nextPageCallback(PageCollection::PageKey::TimeSettingPageKey);
  else
    Page::nextPageCallback(PageCollection::PageKey::UsernameSettingPageKey);
}

void DateSettingPage::changeTopic() {
  switch(inputIndex) {
    case InputIndex::Year:
      staticContents[4].updateContent("Set Year", 8);
      break;
    case InputIndex::Month:
      staticContents[4].updateContent("Set Month", 9);
      break;
    case InputIndex::DayOfMonth:
      staticContents[4].updateContent("Set Day", 7);
      break;
    case InputIndex::Arrow:
      staticContents[4].updateContent("Set Date", 8);
      break;
  }
}

void DateSettingPage::inputInteractiveUpdate(int counter, bool isPress) {
  bool isFinish = input[inputIndex].interactiveUpdate(counter, isPress);
  if (isFinish) {
    inputIndex++;
    if (inputIndex == InputIndex::Arrow)
      staticContents[InputIndex::Arrow].updateContent(">", 1);
    else if (inputIndex == InputIndex::DayOfMonth) {
      setupDayInputRange();
      input[inputIndex].startBlink();
    }
    else
      input[inputIndex].startBlink();
    changeTopic();
  }
}

void DateSettingPage::setupDayInputRange() {
  int year, month, dayOfMonth;
  year = input[InputIndex::Year].getInputValue() + 2000;
  month = input[InputIndex::Month].getInputValue();
  dayOfMonth = input[InputIndex::DayOfMonth].getInputValue();
  int maxDayOfMonth = Helper::getDayOfMonth(year, month);
  input[inputIndex].set((int8_t)min(dayOfMonth, maxDayOfMonth), 1, maxDayOfMonth, true);
}

void DateSettingPage::storeDateTime() {
  int year, month, dayOfMonth, dayOfWeek;
  year = input[InputIndex::Year].getInputValue() + 2000;
  month = input[InputIndex::Month].getInputValue();
  dayOfMonth = input[InputIndex::DayOfMonth].getInputValue();
  DateTime dateTime(year, month, dayOfMonth);
  TempStorage::setDateTime(dateTime);
}

bool DateSettingPage::shouldStoreDateTime() {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  return row == 1;
}