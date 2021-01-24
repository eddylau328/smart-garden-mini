#include "ManualSettingPage.h"

ManualSettingPage::ManualSettingPage(){
   input.setLinkage(&contents[InputIndex::Second]);
   input.setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

ManualSettingPage::~ManualSettingPage(){}

void ManualSettingPage::mountPage() {
  int second;
  input.set((int8_t)second, 0, 20, true);
  
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Second;
  input.startBlink();
  scroll.resetScroll(contents, contentSize);
  
}

void ManualSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void ManualSettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input.blinkUpdate();
}

void ManualSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int second;
        second = input.getInputValue();
    
      Page::interactiveUpdate(counter, isPress);
      }
      else
      {
        Page::nextPageCallback(PageCollection::PageKey::ControlPagePageKey);
      }
      
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

