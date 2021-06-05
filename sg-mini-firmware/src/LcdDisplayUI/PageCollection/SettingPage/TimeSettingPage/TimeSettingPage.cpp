#include "TimeSettingPage.h"

TimeSettingPage::TimeSettingPage() {
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

TimeSettingPage::~TimeSettingPage() {}

void TimeSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 9);

  LocalSettingManager *manager = DeviceManager::getLocalSettingManager();
  DateTime dateTime = manager->getDeviceDateTime();
  input[InputIndex::Hour].set((int8_t)dateTime.hour(), 0, 23, true);
  input[InputIndex::Minute].set((int8_t)dateTime.minute(), 0, 59, true);
  input[InputIndex::Second].set((int8_t)dateTime.second(), 0, 59, true);

  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Hour;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  changeTopic();
}

void TimeSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void TimeSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow && isPress) {
    if (shouldStoreDateTime())
      storeDateTime();
    proceedNextPage(counter, isPress);
  }
  else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
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

void TimeSettingPage::proceedNextPage(int counter, bool isPress) {
  SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
  bool isBeginSystemReset = manager->getIsBeginSystemReset();
  if (isBeginSystemReset)
    proceedSystemResetNextPage();
  else
    Page::interactiveUpdate(counter, isPress);
}

void TimeSettingPage::proceedSystemResetNextPage() {
  if (shouldStoreDateTime())
    Page::nextPageCallback(PageCollection::PageKey::SetupFinishPageKey);
  else
    Page::nextPageCallback(PageCollection::PageKey::DateSettingPageKey);
}

void TimeSettingPage::changeTopic() {
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
      staticContents[4].updateContent("Set Time", 8);
      break;
  }
}

void TimeSettingPage::storeDateTime() {
  int hour, minute, second;
  hour = input[InputIndex::Hour].getInputValue();
  minute = input[InputIndex::Minute].getInputValue();
  second = input[InputIndex::Second].getInputValue();
  LocalSettingManager *manager = DeviceManager::getLocalSettingManager();
  DateTime tempDateTime = TempStorage::getDateTime();
  DateTime newDateTime(
    tempDateTime.year(),
    tempDateTime.month(),
    tempDateTime.day(),
    hour,
    minute,
    second
  );
  manager->setDeviceDateTime(newDateTime);
}

bool TimeSettingPage::shouldStoreDateTime() {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  return row == 1;
}