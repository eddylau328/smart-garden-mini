#include "PageControl.h"

Page *PageControl::pages[TotalPage];
uint8_t PageControl::currentPageKey = PageControl::PageKey::SensorPageKey;
uint8_t PageControl::newPageKey = PageControl::PageKey::MainPageKey;

PageControl::PageControl(LcdDisplayUI *display) {
  this->display = display;
}

PageControl::~PageControl() {
  for (int i = 0; i < TotalPage; i++) {
    delete pages[i];
  }
}

void PageControl::init(Sensors *sensors) {
  pages[PageControl::PageKey::MainPageKey] = new MainPage(sensors);
  pages[PageControl::PageKey::SensorPageKey] = new SensorPage(sensors);
  pages[PageControl::PageKey::SettingPageKey] = new SettingPage();
  pages[PageControl::PageKey::TimeSettingPageKey] = new TimeSettingPage();
  pages[PageControl::PageKey::DateSettingPageKey] = new DateSettingPage();
  pages[PageControl::PageKey::UsernameSettingPageKey] = new UsernameSettingPage();

  pages[PageControl::PageKey::MainPageKey]->setNextPageCallback(PageControl::PageKey::SensorPageKey, &nextPageCallback);
  pages[PageControl::PageKey::SensorPageKey]->setNextPageCallback(PageControl::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageControl::PageKey::SettingPageKey]->setNextPageCallback(PageControl::PageKey::MainPageKey, &nextPageCallback);
  pages[PageControl::PageKey::TimeSettingPageKey]->setNextPageCallback(PageControl::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageControl::PageKey::DateSettingPageKey]->setNextPageCallback(PageControl::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageControl::PageKey::UsernameSettingPageKey]->setNextPageCallback(PageControl::PageKey::SettingPageKey, &nextPageCallback);
  this->display->init();
}

void PageControl::initInput(RotaryEncoder *rotaryEncoder) {
  this->rotaryEncoder = rotaryEncoder;

  this->rotaryEncoder->init(&pressInputCallback, &rotateInputCallback);
}

void PageControl::mainLoop() {
  if (millis() - lastUpdate > 500) {
    handleUpdateContents();
    LOG_ERROR(millis() - lastUpdate);
    lastUpdate = millis();
  }
  handleUI();
  rotaryEncoder->eventLoop();
}

void PageControl::handleUI() {
  if (newPageKey != currentPageKey) {
    // call page dismount for currentPageKey
    pages[currentPageKey]->dismountPage();
    // call page mount for newPageKey();
    pages[newPageKey]->mountPage();
    // render the page
    display->update(pages[newPageKey]);
    // update key
    currentPageKey = newPageKey;
  }
}

void PageControl::handleUpdateContents() {
  pages[currentPageKey]->updateContents();
}

void PageControl::rotateInputCallback(int counter) {
  pages[currentPageKey]->interactiveUpdate(counter, false);
}

void PageControl::pressInputCallback() {
  pages[currentPageKey]->interactiveUpdate(0, true);
}

void PageControl::nextPageCallback(uint8_t pageKey) {
  newPageKey = pageKey;
}