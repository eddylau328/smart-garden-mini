#ifndef LcdDisplayUI_h
#define LcdDisplayUI_h

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "PageCollection/Page.h"
#include "UI/Components/PageContent/PageContent.h"
#include "UI/Components/PageLayoutPosition/PageLayoutPosition.h"

class LcdDisplayUI {

  public:
    /**
     * @param rowSize the number of character LCD can show in one row
     * @param colSize the number of character LCD can show in one column
    */
    LcdDisplayUI(uint8_t rowSize, uint8_t colSize);
    ~LcdDisplayUI();

    void init();
    void render(Page *page);

  private:
    // LCD size 
    uint8_t rowSize, colSize;
    LiquidCrystal_I2C *lcd;

    char *strBuffer;
};

#endif