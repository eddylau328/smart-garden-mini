#include "WifiConnectPage.h"

WifiConnectPage::WifiConnectPage() {
  loadingSpinner.setLinkage(&staticContents[ContentIndex::Loading]);
}

void WifiConnectPage::mountPage() {
  Page::allocateStaticContents(staticContents, staticContentSize);

  TempStorage::getSelectWifiName(&wifiName, &wifiNameLength);
  for (int i = 0 ; i < wifiNameLength; i++) 
    Serial.print(wifiName[i]);
  Serial.println();
  Serial.println(wifiNameLength);
  staticContents[ContentIndex::WifiName] = PageContent(wifiNameLength, PageLayoutPosition(0, 1));
  staticContents[ContentIndex::WifiName].updateContent(wifiName, wifiNameLength);

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