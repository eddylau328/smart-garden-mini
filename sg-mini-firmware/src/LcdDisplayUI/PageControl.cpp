#include "PageControl.h"


Page *PageControl::pages[TotalPage];
uint8_t PageControl::currentPageKey = PageCollection::PageKey::SensorPageKey;
uint8_t PageControl::newPageKey = PageCollection::PageKey::MainPageKey;

PageControl::PageControl(LcdDisplayUI *display) {
  this->display = display;
}

PageControl::~PageControl() {
  for (int i = 0; i < TotalPage; i++) {
    delete pages[i];
  }
}

void PageControl::init() {
  pages[PageCollection::PageKey::MainPageKey] = new MainPage();
  pages[PageCollection::PageKey::SensorPageKey] = new SensorPage();
  pages[PageCollection::PageKey::SettingPageKey] = new SettingPage();
  pages[PageCollection::PageKey::TimeSettingPageKey] = new TimeSettingPage();
  pages[PageCollection::PageKey::DateSettingPageKey] = new DateSettingPage();
  pages[PageCollection::PageKey::UsernameSettingPageKey] = new UsernameSettingPage();
  pages[PageCollection::PageKey::ControlPagePageKey] = new ControlPage();
  pages[PageCollection::PageKey::ModeSettingPageKey] = new ModeSettingPage();
  pages[PageCollection::PageKey::ManualSettingPageKey] = new ManualSettingPage();
  pages[PageCollection::PageKey::AutoSettingPageKey] = new AutoSettingPage();
  pages[PageCollection::PageKey::ScheduleSettingPageKey] = new ScheduleSettingPage();
  pages[PageCollection::PageKey::WifiSettingPageKey] = new WifiSettingPage();

  pages[PageCollection::PageKey::MainPageKey]->setNextPageCallback(PageCollection::PageKey::SensorPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SensorPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SettingPageKey]->setNextPageCallback(PageCollection::PageKey::WifiSettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::WifiSettingPageKey]->setNextPageCallback(PageCollection::PageKey::MainPageKey, &nextPageCallback);

  pages[PageCollection::PageKey::TimeSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::DateSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::UsernameSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ControlPagePageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ModeSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ManualSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::AutoSettingPageKey]->setNextPageCallback(PageCollection::PageKey::ModeSettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ScheduleSettingPageKey]->setNextPageCallback(PageCollection::PageKey::ModeSettingPageKey, &nextPageCallback);

  this->display->init();
}

void PageControl::initInput(RotaryEncoder *rotaryEncoder) {
  this->rotaryEncoder = rotaryEncoder;

  this->rotaryEncoder->init(&pressInputCallback, &rotateInputCallback);
}

void PageControl::mainLoop() {
  if (millis() - lastUpdate > 500) {
    handleUpdateContents();
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