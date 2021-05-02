#include "WifiConnectPage.h"

WifiConnectPage::WifiConnectPage() {
  loadingSpinner.setLinkage(&staticContents[ContentIndex::Loading]);
}

void WifiConnectPage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);

  AccessPointSetting accessPointSetting = TempStorage::getAccessPointSetting();
  wifiName = accessPointSetting.getAccessPointName();
  wifiNameLength = Helper::getStringLength(wifiName);

  staticContents[ContentIndex::WifiName] = PageContent(wifiNameLength, PageLayoutPosition(0, 1));
  staticContents[ContentIndex::WifiName].updateContent(wifiName, wifiNameLength);

  loadingSpinner.spin(true);
  WifiController::connect(accessPointSetting);
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
}