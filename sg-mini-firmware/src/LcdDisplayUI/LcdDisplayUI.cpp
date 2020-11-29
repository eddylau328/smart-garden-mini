#include "LcdDisplayUI.h"

LcdDisplayUI::LcdDisplayUI(uint8_t rowSize, uint8_t colSize) {
  this->rowSize = rowSize;
  this->colSize = colSize;
  this->strBuffer = new char[colSize];

  lcd = new LiquidCrystal_I2C(0x27,colSize, rowSize);
}

LcdDisplayUI::~LcdDisplayUI() {
  delete lcd;
  delete strBuffer;
}

void LcdDisplayUI::init() {
  lcd->init();
  lcd->backlight();
}

void LcdDisplayUI::render(Page *page) {
  // Retrieve page contents array
  PageContent *contents;
  int length;
  page->getContents(&contents, &length);
  // render the page
  
  for (int i = 0; i < length; i++) {
    if ((contents+i)->getIsUpdate()) {
      LOG_WARNING("Update Content:", (contents+i)->getContent(), "|", "id:", (contents+i)->getId());
      clearContent(contents+i);
      printContent(contents+i);
      // tell that content is updated
      (contents+i)->confirmUpdate();
    }
  }
}

void LcdDisplayUI::clearContent(PageContent *content) {
  PageLayoutPosition pos;
  pos = content->getPos();
  lcd->setCursor(pos.col, pos.row);
  for (int i = 0 ; i < content->getContentLength(); i++)
    lcd->print(" ");
}

void LcdDisplayUI::printContent(PageContent *content) {
  PageLayoutPosition pos;
  pos = content->getPos();
  strncpy(strBuffer, content->getContent(), content->getContentLength());
  lcd->setCursor(pos.col, pos.row);
  lcd->printstr(strBuffer);
}