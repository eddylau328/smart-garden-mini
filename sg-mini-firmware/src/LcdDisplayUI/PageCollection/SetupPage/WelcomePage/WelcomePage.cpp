#include "WelcomePage.h"

WelcomePage::WelcomePage() {
  scroll.init(LCDScreenWidth, LCDScreenHeight);
  scroll.setCoverArea(PageLayoutRange(0, 7));
}

void WelcomePage::mountPage() {
  Page::allocateStaticContents(staticContents, 9);
}

void WelcomePage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(contents, contentSize, counter);
  Page::interactiveUpdate(counter, isPress);
}