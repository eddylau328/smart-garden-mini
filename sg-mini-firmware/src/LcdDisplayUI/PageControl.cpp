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
  pages[PageControl::PageKey::MainPageKey] = new MainPage();
  pages[PageControl::PageKey::SensorPageKey] = new SensorPage(sensors);

  pages[PageControl::PageKey::MainPageKey]->setNextPageCallback(PageControl::PageKey::SensorPageKey, &nextPageCallback);
  pages[PageControl::PageKey::SensorPageKey]->setNextPageCallback(PageControl::PageKey::MainPageKey, &nextPageCallback);

  this->display->init();
}

void PageControl::initInput(RotaryEncoder *rotaryEncoder) {
  this->rotaryEncoder = rotaryEncoder;

  this->rotaryEncoder->init(&pressInputCallback, &rotateInputCallback);
}

void PageControl::mainLoop() {
  if (millis() - lastUpdate > 2000) {
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