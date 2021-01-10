#include "ManualSettingPage.h"

ManualSettingPage::ManualSettingPage(){
   input[InputIndex::Second].setLinkage(&contents[InputIndex::Second]);
   input[InputIndex::Second].setCircleLoop(true);

   scroll.init(LCDScreenWidth, LCDScreenHeight);
   scroll.setCoverArea(PageLayoutRange(0, 1));
   scroll.setCursor(&contents[InputIndex::Arrow], 1);
}

ManualSettingPage::~ManualSettingPage(){}

void ManualSettingPage::mountPage() {
  int second;
  input[InputIndex::Second].set((int8_t)second, 0, 20, true);
  
  contents[InputIndex::Arrow].updateContent(" ", 1);
  inputIndex = InputIndex::Second;
  input[inputIndex].startBlink();
  scroll.resetScroll(contents, contentSize);
  
}

void ManualSettingPage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void ManualSettingPage::updateContents() {
   if (inputIndex != InputIndex::Arrow)
    input[inputIndex].blinkUpdate();
}

void ManualSettingPage::interactiveUpdate(int counter, bool isPress) {
  if (inputIndex == InputIndex::Arrow) {
    if (isPress) {
      int8_t row = scroll.getCurrentArrowRow(contents, contentSize);
      if (row == 1) {
        int second;
        second = input[InputIndex::Second].getInputValue();
     
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

void ManualSettingPage::dismountPage() {}