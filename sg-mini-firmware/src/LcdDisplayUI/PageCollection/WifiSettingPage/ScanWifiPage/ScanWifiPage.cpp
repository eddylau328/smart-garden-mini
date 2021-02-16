#include "ScanWifiPage.h"


ScanWifiPage::ScanWifiPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
}

void ScanWifiPage::mountPage() {
  isCreatedDynamicContent = false;
  contentSetup();
  WifiController::startScanNetwork(5);
}

void ScanWifiPage::getContents(PageContent **contents, int *length) {
  *contents = *this->contents;
  *length = contentSize;
}

void ScanWifiPage::updateContents() {
  if (!WifiController::isScanningNetwork() && !isCreatedDynamicContent) {
    getDynamicContents();
    contentSetup();
  }
}

void ScanWifiPage::interactiveUpdate(int counter, bool isPress) {
}

void ScanWifiPage::dismountPage() {
  for (int i = 0; i < dynamicContentSize; i++)
    delete dynamicContents[i];
  delete [] dynamicContents;
  delete [] contents;
}

void ScanWifiPage::contentSetup() {
  // free the pointer array memory only
  delete [] contents;
  // declare contents size and memory allocation
  contentSize = staticContentSize + dynamicContentSize;
  contents = new PageContent*[contentSize];
  // assign pointer address
  for (int i = 0; i < staticContentSize; i++)
    contents[i] = &staticContents[i];
  for (int i = staticContentSize; i < dynamicContentSize + staticContentSize; i++)
    contents[i] = dynamicContents[i];
  // modification
  contentRow = dynamicContentSize + 2;
  contents[ContentIndex::JoinOther]->updatePos(PageLayoutPosition(2, contentRow - 1));
  contents[ContentIndex::ReturnInput]->updatePos(PageLayoutPosition(2, contentRow));
}

void ScanWifiPage::getDynamicContents() {
  // free the pointer array
  for (int i = 0; i < dynamicContentSize; i++)
    delete dynamicContents[i];
  delete [] dynamicContents;
  dynamicContentSize = WifiController::getNetworkCount();
  dynamicContents = new PageContent*[dynamicContentSize];
  char *str = new char[20];
  int length = 0;
  for (int i = 0 ; i < dynamicContentSize; i++) {
    WifiController::getNetwork(&str, &length, i);
    dynamicContents[i] = new PageContent(length, PageLayoutPosition(2, contentRow - dynamicContentSize - 1));
    dynamicContents[i]->updateContent(str, length);
  }
  isCreatedDynamicContent = true;
  delete [] str;
}