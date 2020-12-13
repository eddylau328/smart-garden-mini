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

void LcdDisplayUI::update(Page *page) {
  this->renderPage = page;
}

void LcdDisplayUI::render() {
  if (millis() - lastRender > 100) {
    if (renderPage) {
      // Retrieve page contents array
      PageContent *contents;
      int length;
      renderPage->getContents(&contents, &length);
      // render the page
      for (int i = 0; i < length; i++) {
        if ((contents+i)->getIsUpdate()) {
          LOG_WARNING("Update Content id:", (contents+i)->getId());
          clearContent(contents+i);
        }
      }
      for (int i = 0; i < length; i++) {
        if ((contents+i)->getIsUpdate()) {
          printContent(contents+i);
          // tell that content is updated
          (contents+i)->confirmUpdate();
        }
      }
    }
    lastRender = millis();
  }
}

void LcdDisplayUI::clearContent(PageContent *content) {
  PageLayoutPosition pos;
  pos = content->getPos();
  if (Helper::int8_tInRange(pos.row, 0, rowSize-1) && pos.col < colSize) {
    int8_t startIndex = 0;
    int8_t contentSize = (int8_t)content->getContentLength();
    if (pos.col >= 0)
      lcd->setCursor(pos.col, pos.row);
    else {
      lcd->setCursor(0, pos.row);
      startIndex = abs(pos.col);
    }
    for (int8_t i = startIndex ; i < contentSize; i++)
      if (pos.col + i < colSize)
        lcd->print(" ");
      else
        break;
  }
}

void LcdDisplayUI::printContent(PageContent *content) {
  PageLayoutPosition pos;
  pos = content->getNewPos();
  strncpy(strBuffer, content->getContent(), content->getContentLength());
  if (Helper::int8_tInRange(pos.row, 0, rowSize-1) && pos.col < colSize) {
    int8_t startIndex = 0;
    int8_t contentSize = (int8_t)content->getContentLength();
    if (pos.col >= 0 )
      lcd->setCursor(pos.col, pos.row);
    else {
      lcd->setCursor(0, pos.row);
      startIndex = abs(pos.col);
    }
    for (int8_t i = startIndex ; i < contentSize; i++)
      if (pos.col + i < colSize)
        lcd->print(*(strBuffer+i));
      else
        break;
  }   
}