#include "WifiSettingPage.h"

WifiSettingPage::WifiSettingPage() {
  input.setLinkage(&staticContents[ContentIndex::WifiModeInput]);
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCursor(&staticContents[ContentIndex::Arrow], 0);
}

void WifiSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 5);

  // in order to hide contents, overwrite the content size value
  this->contentSize = 4;
  inputIndex = ContentIndex::Arrow;
  wifiMode = DeviceSetting::getWifiMode();
  input.set(wifiMode);
  processPageContent();
  scroll.resetScroll(contents, contentSize);
}

void WifiSettingPage::updateContents() {
  if (wifiMode != DeviceSetting::getWifiMode()) {
    wifiMode = DeviceSetting::getWifiMode();
    processPageContent();
  }
}

void WifiSettingPage::interactiveUpdate(int counter, bool isPress) {
  switch(inputIndex){
    case ContentIndex::Arrow:
      scroll.updateScroll(contents, contentSize, counter);
      if (isPress) {
        int8_t index = scroll.getCurrentArrowRow(contents, contentSize);
        if (index == 0) {
          LOG_ERROR("Enter Wifi Mode Setting");
          inputIndex = ContentIndex::WifiModeInput;
          staticContents[ContentIndex::Arrow].updateContent("~", 1);
        }
        else if (index == 1 && wifiMode) {
            LOG_ERROR("Enter Scan Wifi");
            Page::nextPageCallback(PageCollection::PageKey::ScanWifiPageKey);
        }
        else {
          LOG_ERROR("Return");
          Page::nextPageCallback(Page::defaultPageKey);
        }
      }
      break;
    case ContentIndex::WifiModeInput:
      bool isFinish = input.interactiveUpdate(counter, isPress);
      if (isFinish) {
        DeviceSetting::setWifiMode(input.getInputValue());
        inputIndex = ContentIndex::Arrow;
        staticContents[ContentIndex::Arrow].updateContent(">", 1);
      }
      break;
  }
}

void WifiSettingPage::processPageContent() {
  if (wifiMode) {
    staticContents[ContentIndex::ReturnInput].updatePos(PageLayoutPosition(2, 2));
    staticContents[ContentIndex::ScanWifiInput].updatePos(PageLayoutPosition(2, 1));
    contentSize = 5;
    scroll.setCoverArea(PageLayoutRange(0, 2));
  }
  else {
    staticContents[ContentIndex::ReturnInput].updatePos(PageLayoutPosition(2, 1));
    contentSize = 4;
    scroll.setCoverArea(PageLayoutRange(0, 1));
  }
}

/* Design

> Wifi Mode  OFF|
                |

~ Wifi Mode  OFF|
                |

> Wifi Mode   ON|
  Scan Wifi     |

~ Wifi Mode   ON|
  Scan Wifi     |

*/