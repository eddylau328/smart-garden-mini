#include "RestoreDefaultPage.h"

RestoreDefaultPage::RestoreDefaultPage() {
    scroll.init(LCDScreenWidth, LCDScreenHeight);
    scroll.setCoverArea(PageLayoutRange(0, 1));
    scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void RestoreDefaultPage::mountPage() {
    Page::allocateStaticContents(staticContents, 5);
    scroll.resetScroll(contents, contentSize);
}

void RestoreDefaultPage::interactiveUpdate(int counter, bool isPress) {
    if (isPress)
        proceedNextPage(counter, isPress);
    else
        scroll.updateScroll(contents, contentSize, counter);
}

// private

void RestoreDefaultPage::proceedNextPage(int counter, bool isPress) {
	if (shouldResetSystem()) {
        SetupSettingManager *manager = DeviceManager::getSetupSettingManager();
        manager->resetSystem();
        Page::nextPageCallback(PageCollection::PageKey::ConfirmRestorePageKey);
	}
    else
        Page::interactiveUpdate(counter, isPress);
}

bool RestoreDefaultPage::shouldResetSystem() {
    int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
    return row == 0;
}