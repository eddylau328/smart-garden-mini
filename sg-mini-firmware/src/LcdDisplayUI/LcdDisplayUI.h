#ifndef LcdDisplayUI_h
#define LcdDisplayUI_h

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>

class LcdDisplayUI {

  public:
    /**
     * @param rowSize the number of character LCD can show in one row
     * @param colSize the number of character LCD can show in one column
    */
    LcdDisplayUI(uint8_t rowSize, uint8_t colSize);
    ~LcdDisplayUI();

    void init();

  private:
    // LCD size 
    uint8_t rowSize, colSize;
    LiquidCrystal_I2C *lcd;
};

#endif