#include "WifiConnectPage.h"

WifiConnectPage::WifiConnectPage() {
  loadingSpinner.setLinkage(&staticContents[ContentIndex::Loading]);
}

void WifiConnectPage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);

  TempStorage::getSelectWifiName(&wifiName, &wifiNamelength);
  
  staticContents[2] = PageContent(wifiNamelength, PageLayoutPosition(0, 0));
  staticContents[2].updateContent(wifiName, wifiNamelength);

  loadingSpinner.spin(true);
}

void WifiConnectPage::updateContents() {
  loadingSpinner.updateSpinner();
}

void WifiConnectPage::dismountPage() {
  staticContents[ContentIndex::WifiName].~PageContent();
  TempStorage::freeSelectWifiName();
  TempStorage::freeSelectWifiPassword();
}