#include "AutoSettingPage.h"

AutoSettingPage::AutoSettingPage(){
   input.setLinkage(&contents[InputIndex::Humidity]);
   input.setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

AutoSettingPage::~AutoSettingPage(){}

void AutoSettingPage::mountPage() {
  int humidity;
  input.set((int8_t)humidity, 0, 99, true);
  
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Humidity;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
  
}

void AutoSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
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
        
      }
      Page::interactiveUpdate(counter, isPress);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input.interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        contents[InputIndex::Arrow].updateContent(">", 1);
      else {
        input.startBlink();
      }
     
    }
  }

}

void AutoSettingPage::dismountPage() {}