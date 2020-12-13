#ifndef LcdDisplayUI_h
#define LcdDisplayUI_h

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"
#include "PageCollection/Page.h"
#include "UI/Components/PageContent/PageContent.h"
#include "UI/Components/PageLayoutPosition/PageLayoutPosition.h"

class LcdDisplayUI {

  public:
    /**
     * @param rowSize the number of character LCD can show in one row
     * @param colSize the number of character LCD can show in one column
    */
    LcdDisplayUI(int8_t colSize, int8_t rowSize);
    ~LcdDisplayUI();

    void init();
    void update(Page *page);
    void render();

  private:
    // LCD size 
    int8_t rowSize, colSize;
    LiquidCrystal_I2C *lcd;
    Page *renderPage;
    unsigned long lastRender;
    
    char *strBuffer;
    void clearContent(PageContent *content);
    void printContent(PageContent *content);
};

#endif