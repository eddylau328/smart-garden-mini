#include "ScanWifiPage.h"


ScanWifiPage::ScanWifiPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  loadingSpinner.setLinkage(&staticContents[ContentIndex::Loading]);
}

void ScanWifiPage::mountPage() {
  isCreatedDynamicContent = false;
  contentSetup();
  WifiController::startScanNetwork(2);
  loadingSpinner.spin(true);
}

void ScanWifiPage::updateContents() {
  loadingSpinner.updateSpinner();
  if (!WifiController::isScanningNetwork() && !isCreatedDynamicContent) {
    getDynamicContents();
    contentSetup();
  }
}

void ScanWifiPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    if (index > 0 && index < contentRow - 1) {
      // SELECT WIFI NAME
      char wifiName[25];
      int length = 0;
      WifiController::getNetwork(wifiName, &length, index - 1, 25);
      AccessPointSetting accessPointSetting = TempStorage::getAccessPointSetting();
      accessPointSetting.setAccessPointName(wifiName, length);
      TempStorage::setAccessPointSetting(accessPointSetting);
      Page::nextPageCallback(PageCollection::PageKey::WifiPasswordPageKey);
    }
    else if (index == contentRow - 1) {
      // JOIN OTHER
      Page::nextPageCallback(PageCollection::PageKey::WifiNamePageKey);
    }
    else
      // Return
      Page::nextPageCallback(Page::defaultPageKey);
  }
}

void ScanWifiPage::dismountPage() {
  freeDynamicContents();
  freeContents();
}

void ScanWifiPage::contentSetup() {
  // free memory
  freeContents();
  // declare contents size and memory allocation
  contentSize = staticContentSize + dynamicContentSize;
  contents = new PageContent*[contentSize];
  isAllocateContents = true;
  // assign pointer address
  for (int i = 0; i < staticContentSize; i++)
    contents[i] = &staticContents[i];

  for (int i = staticContentSize; i < dynamicContentSize + staticContentSize; i++)
    contents[i] = dynamicContents[i - staticContentSize];
  // modification
  contentRow = dynamicContentSize + 2; // dynamicContentSize + (scan wifi) + (join other) + (...) - 1 for index
  contents[ContentIndex::JoinOther]->updatePos(PageLayoutPosition(2, contentRow - 1));
  contents[ContentIndex::ReturnInput]->updatePos(PageLayoutPosition(2, contentRow));
  contents[ContentIndex::Header]->updatePos(PageLayoutPosition(2, 0));
  contents[ContentIndex::Arrow]->updatePos(PageLayoutPosition(0, 0));
  contents[ContentIndex::Loading]->updatePos(PageLayoutPosition(15, 0));

  scroll.setCoverArea(PageLayoutRange(0, contentRow));
  scroll.setCursor(&staticContents[ContentIndex::Arrow], 0);

  // reset loading
  loadingSpinner.spin(false);
  loadingSpinner.clear();
}

void ScanWifiPage::getDynamicContents() {
  // free the pointer array
  freeDynamicContents();
  dynamicContentSize = WifiController::getNetworkCount();
  dynamicContents = new PageContent*[dynamicContentSize];
  char str[40];
  int length = 0;
  for (int i = 0 ; i < dynamicContentSize; i++) {
    WifiController::getNetwork(str, &length, i, 40);
    length -= 1; // Ignore null character
    dynamicContents[i] = new PageContent(length, PageLayoutPosition(2, i + 1));
    dynamicContents[i]->updateContent(str, length);
  }
  isCreatedDynamicContent = true;
}

void ScanWifiPage::freeDynamicContents() {
  if (dynamicContentSize > 0) {
    for (int i = 0; i < dynamicContentSize; i++)
      delete dynamicContents[i];
    delete [] dynamicContents;
  }
  dynamicContentSize = 0;
}

void ScanWifiPage::freeContents() {
  if (contentSize > 0)
    delete [] contents;
  contentSize = 0;
}