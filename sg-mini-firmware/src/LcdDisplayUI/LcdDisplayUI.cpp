#include "LcdDisplayUI.h"

LcdDisplayUI::LcdDisplayUI(uint8_t rowSize, uint8_t colSize) {
  this->rowSize = rowSize;
  this->colSize = colSize;

  lcd = new LiquidCrystal_I2C(0x27,colSize, rowSize);
}

LcdDisplayUI::~LcdDisplayUI() {
  delete lcd;
}

void LcdDisplayUI::init() {
  lcd->init();
  lcd->backlight();
}