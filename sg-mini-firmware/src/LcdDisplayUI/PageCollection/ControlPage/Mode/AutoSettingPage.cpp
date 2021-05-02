#include "AutoSettingPage.h"

AutoSettingPage::AutoSettingPage(){
   input.setLinkage(&staticContents[InputIndex::Humidity]);
   input.setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&staticContents[InputIndex::Arrow], 1);
}

void AutoSettingPage::mountPage() {
  Page::allocateStaticContents(staticContents, 6);

  int humidity;
  input.set((int8_t)humidity, 0, 99, true);
  
  staticContents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Humidity;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
  
}

void AutoSettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void AutoSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int humidity;
        humidity = input.getInputValue();
        Page::interactiveUpdate(counter, isPress);  
      }
      else
        Page::nextPageCallback(PageCollection::PageKey::ModeSettingPageKey);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input.interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        staticContents[InputIndex::Arrow].updateContent(">", 1);
      else
        input.startBlink();
    }
  }
}