#include "LcdDisplayUI.h"

LcdDisplayUI::LcdDisplayUI(int8_t colSize, int8_t rowSize) {
  this->rowSize = rowSize;
  this->colSize = colSize;
  this->strBuffer = new char[colSize];

  lcd = new LiquidCrystal_I2C(0x27, colSize, rowSize);
}

LcdDisplayUI::~LcdDisplayUI() {
  delete lcd;
  delete strBuffer;
}

void LcdDisplayUI::init() {
  lcd->init();
  lcd->backlight();
  createCustomCharacter();
}

void LcdDisplayUI::update(Page *page) {
  this->renderPage = page;
  this->isUpdatePage = true;
}

void LcdDisplayUI::render() {
  if (millis() - lastRender > 100) {
    if (renderPage) {
      // Retrieve page contents array
      PageContent **contents;
      int length;
      bool isClearAll;
      renderPage->getContents(&contents, &length, &isClearAll);
      // render the page
      if (isUpdatePage || isClearAll) {
        lcd->clear();
        for (int i = 0; i < length; i++) {
          printContent(contents[i]);
          // tell that content is updated
          contents[i]->confirmUpdate();
        }
        isUpdatePage = false;
      }
      else {
        for (int i = 0; i < length; i++) {
          if (contents[i]->getIsUpdate()) {
            clearContent(contents[i]);
          }
        }
        for (int i = 0; i < length; i++) {
          if (contents[i]->getIsUpdate()) {
            printContent(contents[i]);
            // tell that content is updated
            contents[i]->confirmUpdate();
          }
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
    int8_t endIndex = (int8_t)content->getContentLength();

    if (pos.col >= 0) {
      lcd->setCursor(pos.col, pos.row);
      if (pos.col + endIndex > colSize)
        endIndex = colSize - pos.col;
    }
    else {
      lcd->setCursor(0, pos.row);
      startIndex = abs(pos.col);
      if (endIndex - startIndex > colSize)
        endIndex = colSize;
    }
    for (int8_t i = startIndex ; i < endIndex; i++)
      lcd->print(" ");
  }
}

void LcdDisplayUI::printContent(PageContent *content) {
  PageLayoutPosition pos;
  pos = content->getNewPos();
  strncpy(strBuffer, content->getContent(), content->getContentLength());
  if (Helper::int8_tInRange(pos.row, 0, rowSize-1) && pos.col < colSize) {
    int8_t startIndex = 0;
    int8_t endIndex = (int8_t)content->getContentLength();

    if (pos.col >= 0 ) {
      lcd->setCursor(pos.col, pos.row);
      if (pos.col + endIndex > colSize)
        endIndex = colSize - pos.col;
    }
    else {
      lcd->setCursor(0, pos.row);
      startIndex = abs(pos.col);
      if (endIndex - startIndex > colSize)
        endIndex = colSize;
    }
    for (int8_t i = startIndex ; i < endIndex; i++)
      if (content->getIsCustomCharacter(i))
        lcd->write(content->getCustomCharacterIndex());
      else
        lcd->print(*(strBuffer+i));
  }   
}

void LcdDisplayUI::createCustomCharacter() {
  lcd->createChar(CUSTOM_BACKSLASH, CustomCharacter::BACKSLASH);
  lcd->createChar(CUSTOM_ENTER, CustomCharacter::ENTER);
  lcd->createChar(CUSTOM_BACKSPACE, CustomCharacter::BACKSPACE);
}