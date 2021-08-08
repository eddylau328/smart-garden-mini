#include "UsernameSettingPage.h"

UsernameSettingPage::UsernameSettingPage() {
  input.setLinkage(&staticContents[InputIndex::Name]);
  input.setCircleLoop(true);

  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 1));
  scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void UsernameSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 7);

  LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
  const char* name = localSettingManager->getUsername();
  input.set(name, USERNAME_LENGTH);

  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Name;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
}

void UsernameSettingPage::updateContents() {
  if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void UsernameSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow && isPress) {
    if (shouldStoreUsername())
      storeUsername();
    proceedNextPage(counter, isPress);
  }
  else if (inputIndex == InputIndex::Arrow)
    scroll.updateScroll(contents, contentSize, counter);
  else
    inputInteractiveUpdate(counter, isPress);
}

// private

void UsernameSettingPage::proceedNextPage(int counter, bool isPress) {
  SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
  bool isBeginSystemReset = manager->getIsBeginSystemReset();
  if (isBeginSystemReset)
    proceedSetupNextPage();
  else
    Page::interactiveUpdate(counter, isPress);
}

void UsernameSettingPage::proceedSetupNextPage() {
  if (shouldStoreUsername())
    Page::nextPageCallback(PageCollection::PageKey::DateSettingPageKey);
  else
    Page::nextPageCallback(PageCollection::PageKey::WelcomePageKey);
}

void UsernameSettingPage::inputInteractiveUpdate(int counter, bool isPress) {
  bool isFinish = input.interactiveUpdate(counter, isPress);
  if (isFinish) {
    inputIndex = InputIndex::Arrow;
    staticContents[InputIndex::Arrow].updateContent(">", 1);
  }
}

void UsernameSettingPage::storeUsername() {
  LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
  localSettingManager->setUsername(input.getInputValue());
}

bool UsernameSettingPage::shouldStoreUsername() {
  int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
  return row == 1;
}