#include "PageControl.h"


Page *PageControl::pages[TotalPage];
uint8_t PageControl::currentPageKey;
uint8_t PageControl::nextPageKey;

PageControl::PageControl(LcdDisplayUI *display) {
  this->display = display;
}

PageControl::~PageControl() {
  for (int i = 0; i < TotalPage; i++) {
    delete pages[i];
  }
}

void PageControl::init() {
  this->pageInit();
  this->retrieveCurrentPage();
  this->display->init();
  updateDelay.start(500);
}

void PageControl::initInput(RotaryEncoder *rotaryEncoder) {
  this->rotaryEncoder = rotaryEncoder;

  this->rotaryEncoder->init(&pressInputCallback, &rotateInputCallback);
}

void PageControl::mainLoop() {
  if (updateDelay.justFinished()) {
    updateDelay.repeat();
    handleUpdateContents();
  }
  handleUI();
  rotaryEncoder->eventLoop();
}

void PageControl::handleUI() {
  if (nextPageKey != currentPageKey) {
    // call page dismount for currentPageKey
    pages[currentPageKey]->dismountPage();
    // call page mount for newPageKey();
    pages[nextPageKey]->mountPage();
    // render the page
    display->update(pages[nextPageKey]);
    // update key
    currentPageKey = nextPageKey;
  }
}

void PageControl::handleUpdateContents() {
  pages[currentPageKey]->updateContents();
}

void PageControl::retrieveCurrentPage() {
  SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
  if (manager->getIsBeginSystemReset()) {
    currentPageKey = PageCollection::PageKey::MainPageKey;
    nextPageKey = PageCollection::PageKey::WelcomePageKey;
  }
  else {
    currentPageKey = PageCollection::PageKey::WelcomePageKey;
    nextPageKey = PageCollection::PageKey::MainPageKey;
  }
}

void PageControl::pageInit() {
  pages[PageCollection::PageKey::MainPageKey] = new MainPage();
  pages[PageCollection::PageKey::SensorPageKey] = new SensorPage();
  pages[PageCollection::PageKey::SettingPageKey] = new SettingPage();
  pages[PageCollection::PageKey::TimeSettingPageKey] = new TimeSettingPage();
  pages[PageCollection::PageKey::DateSettingPageKey] = new DateSettingPage();
  pages[PageCollection::PageKey::UsernameSettingPageKey] = new UsernameSettingPage();
  pages[PageCollection::PageKey::ControlPageKey] = new ControlPage();
  pages[PageCollection::PageKey::ModeSettingPageKey] = new ModeSettingPage();
  pages[PageCollection::PageKey::ManualSettingPageKey] = new ManualSettingPage();
  pages[PageCollection::PageKey::HumiditySettingPageKey] = new HumiditySettingPage();
  pages[PageCollection::PageKey::ScheduleSettingPageKey] = new ScheduleSettingPage();
  pages[PageCollection::PageKey::WifiSettingPageKey] = new WifiSettingPage();
  pages[PageCollection::PageKey::ScanWifiPageKey] = new ScanWifiPage();
  pages[PageCollection::PageKey::WifiNamePageKey] = new WifiNamePage();
  pages[PageCollection::PageKey::WifiPasswordPageKey] = new WifiPasswordPage();
  pages[PageCollection::PageKey::WifiConnectPageKey] = new WifiConnectPage();
  pages[PageCollection::PageKey::SetDefaultWifiPageKey] = new SetDefaultWifiPage();
  pages[PageCollection::PageKey::WelcomePageKey] = new WelcomePage();
  pages[PageCollection::PageKey::SetupFinishPageKey] = new SetupFinishPage();
  pages[PageCollection::PageKey::RestoreDefaultPageKey] = new RestoreDefaultPage();
  pages[PageCollection::PageKey::ConfirmRestorePageKey] = new ConfirmRestorePage();

  pages[PageCollection::PageKey::MainPageKey]->setNextPageCallback(PageCollection::PageKey::SensorPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SensorPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SettingPageKey]->setNextPageCallback(PageCollection::PageKey::MainPageKey, &nextPageCallback);

  pages[PageCollection::PageKey::TimeSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::DateSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::UsernameSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);

  pages[PageCollection::PageKey::ControlPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ModeSettingPageKey]->setNextPageCallback(PageCollection::PageKey::ControlPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ManualSettingPageKey]->setNextPageCallback(PageCollection::PageKey::ControlPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::HumiditySettingPageKey]->setNextPageCallback(PageCollection::PageKey::ControlPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ScheduleSettingPageKey]->setNextPageCallback(PageCollection::PageKey::ControlPageKey, &nextPageCallback);

  pages[PageCollection::PageKey::WifiSettingPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::ScanWifiPageKey]->setNextPageCallback(PageCollection::PageKey::WifiSettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::WifiNamePageKey]->setNextPageCallback(PageCollection::PageKey::WifiPasswordPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::WifiPasswordPageKey]->setNextPageCallback(PageCollection::PageKey::WifiConnectPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::WifiConnectPageKey]->setNextPageCallback(PageCollection::PageKey::SetDefaultWifiPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SetDefaultWifiPageKey]->setNextPageCallback(PageCollection::PageKey::WifiSettingPageKey, &nextPageCallback);

  pages[PageCollection::PageKey::WelcomePageKey]->setNextPageCallback(PageCollection::PageKey::UsernameSettingPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::SetupFinishPageKey]->setNextPageCallback(PageCollection::PageKey::MainPageKey, &nextPageCallback);
  pages[PageCollection::PageKey::RestoreDefaultPageKey]->setNextPageCallback(PageCollection::PageKey::SettingPageKey, &nextPageCallback);
}


void PageControl::rotateInputCallback(int counter) {
  pages[currentPageKey]->interactiveUpdate(counter, false);
}

void PageControl::pressInputCallback() {
  pages[currentPageKey]->interactiveUpdate(0, true);
}

void PageControl::nextPageCallback(uint8_t pageKey) {
  nextPageKey = pageKey;
}