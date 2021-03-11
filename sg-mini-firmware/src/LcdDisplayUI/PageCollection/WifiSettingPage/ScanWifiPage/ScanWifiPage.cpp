#include "ScanWifiPage.h"


ScanWifiPage::ScanWifiPage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
}

void ScanWifiPage::mountPage() {
  scroll.setCoverArea(PageLayoutRange(0, 2));
  scroll.setCursor(&staticContents[ContentIndex::Arrow], 0);
  isCreatedDynamicContent = false;
  contentSetup();
  WifiController::startScanNetwork(5);
}

void ScanWifiPage::updateContents() {
  if (!WifiController::isScanningNetwork() && !isCreatedDynamicContent) {
    getDynamicContents();
    contentSetup();
  }
  else if (WifiController::isScanningNetwork())
    updateLoadingSign();
}

void ScanWifiPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  if (isPress) {
    int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
    if (index > 0 && index < contentRow - 1) {

    }
    else if (index == contentRow - 1) {
      // JOIN OTHER
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

  scroll.setCoverArea(PageLayoutRange(0, contentRow));
  scroll.resetScroll(contents, contentSize);

  // reset loading
  contents[ContentIndex::Loading]->updateContent(" ", 1);
}

void ScanWifiPage::getDynamicContents() {
  // free the pointer array
  freeDynamicContents();
  dynamicContentSize = WifiController::getNetworkCount();
  dynamicContents = new PageContent*[dynamicContentSize];
  char *str = new char[20];
  int length = 0;
  for (int i = 0 ; i < dynamicContentSize; i++) {
    WifiController::getNetwork(&str, &length, i);
    dynamicContents[i] = new PageContent(length, PageLayoutPosition(2, i + 1));
    dynamicContents[i]->updateContent(str, length);
  }
  isCreatedDynamicContent = true;
  delete str;
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

void ScanWifiPage::updateLoadingSign() {
  if (millis() - lastLoadingUpdate > 500) {
    switch(loadingIndex) {
      case 0:
        contents[ContentIndex::Loading]->updateContent("-", 1);
        break;
      case 1:
        contents[ContentIndex::Loading]->setCustomCharacterIndex(CUSTOM_BACKSLASH);
        break;
      case 2:
        contents[ContentIndex::Loading]->updateContent("|", 1);
        break;
      case 3:
        contents[ContentIndex::Loading]->updateContent("/", 1);
        break;
    }
    loadingIndex = (loadingIndex + 1) % 4;
  }
}