#include "SetupFinishPage.h"

void SetupFinishPage::mountPage() {
  Page::allocateStaticContents(staticContents, 2);
}

void SetupFinishPage::interactiveUpdate(int counter, bool isPress) {
  Page::interactiveUpdate(counter, isPress);
}