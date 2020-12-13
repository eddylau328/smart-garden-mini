#include "PageControl.h"

Page *PageControl::pages[TotalPage];
uint8_t PageControl::currentPageKey = PageControl::PageKey::SensorPageKey;

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

  this->display->init();
}

void PageControl::initInput(RotaryEncoder *rotaryEncoder) {
  this->rotaryEncoder = rotaryEncoder;

  this->rotaryEncoder->init(&pressInputCallback, &rotateInputCallback);
}

void PageControl::mainLoop() {
  if (millis() - lastUpdate > 2000) {
    handleUI();
    handleUpdateContents();
    lastUpdate = millis();
  }
  rotaryEncoder->eventLoop();
}

void PageControl::handleUI() {
  // render the page
  display->update(pages[currentPageKey]);
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