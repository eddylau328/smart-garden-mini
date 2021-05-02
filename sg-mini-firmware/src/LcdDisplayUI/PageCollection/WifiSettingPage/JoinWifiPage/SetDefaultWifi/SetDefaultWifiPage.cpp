#include "SetDefaultWifiPage.h"

SetDefaultWifiPage::SetDefaultWifiPage() {
    scroll.init(LCDScreenWidth, LCDScreenHeight);
    scroll.setCoverArea(PageLayoutRange(0, 1));
    scroll.setCursor(&staticContents[ContentIndex::Arrow], 1);
}

void SetDefaultWifiPage::mountPage() {
    Page::allocateStaticContents(staticContents, staticContentSize);
    scroll.resetScroll(contents, contentSize);
}

void SetDefaultWifiPage::interactiveUpdate(int counter, bool isPress) {
    if (isPress) {
        int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
        if (row == 1) {
            // SAVE AS DEFAULT WIFI
        }
        Page::interactiveUpdate(counter, isPress);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
}
