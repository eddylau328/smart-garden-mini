#include "WifiConnectPage.h"

WifiConnectPage::WifiConnectPage() {
  loadingSpinner.setLinkage(&staticContents[ContentIndex::Loading]);
}

void WifiConnectPage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);

  TempStorage::getSelectWifiName(&wifiName, &wifiNameLength);
  staticContents[ContentIndex::WifiName] = PageContent(wifiNameLength, PageLayoutPosition(0, 1));
  staticContents[ContentIndex::WifiName].updateContent(wifiName, wifiNameLength);

  loadingSpinner.spin(true);
  char *wifiPassword;
  int passwordLength;
  TempStorage::getSelectWifiPassword(&wifiPassword, &passwordLength);
  WifiController::connect(wifiName, wifiPassword);
}

void WifiConnectPage::updateContents() {
  loadingSpinner.updateSpinner();
  if (loadingSpinner.isSpinning() && WifiController::isConnectedNetwork()) {
    loadingSpinner.spin(false);
    loadingSpinner.clear();
  }
}

void WifiConnectPage::dismountPage() {
  staticContents[ContentIndex::WifiName].~PageContent();
  TempStorage::freeSelectWifiName();
  TempStorage::freeSelectWifiPassword();
}