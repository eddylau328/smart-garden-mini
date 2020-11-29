#include "PageControl.h"

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

void PageControl::handleUI() {
  // render the page
  display->render(pages[PageControl::PageKey::MainPageKey]);
}