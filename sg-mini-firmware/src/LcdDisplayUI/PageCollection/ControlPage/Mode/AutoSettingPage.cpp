#include "AutoSettingPage.h"

AutoSettingPage::AutoSettingPage(){
   input[InputIndex::Humidity].setLinkage(&contents[InputIndex::Humidity]);
   input[InputIndex::Humidity].setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

AutoSettingPage::~AutoSettingPage(){}

void AutoSettingPage::mountPage() {
  int humidity;
  input[InputIndex::Humidity].set((int8_t)humidity, 0, 99, true);
  
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Humidity;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  
}

void AutoSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void AutoSettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void AutoSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int humidity;
        humidity = input[InputIndex::Humidity].getInputValue();
        
      }
      Page::interactiveUpdate(counter, isPress);
    }
    else
      scroll.updateScroll(contents, contentSize, counter);
  }
  else {
    bool isFinish = input[inputIndex].interactiveUpdate(counter, isPress);
    if (isFinish) {
      inputIndex++;
      if (inputIndex == InputIndex::Arrow)
        contents[InputIndex::Arrow].updateContent(">", 1);
      else {
        input[inputIndex].startBlink();
      }
     
    }
  }

}

void AutoSettingPage::dismountPage() {}