#ifndef LcdDisplayUI_h
#define LcdDisplayUI_h

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"
#include "PageCollection/Page.h"
#include "Components/PageContent/PageContent.h"
#include "Components/PageLayoutPosition/PageLayoutPosition.h"

class LcdDisplayUI {

  public:

    /**
     * @brief Construct a new Lcd Display U I object
     * 
     * @param colSize - the number of character the LCD can show in one row
     * @param rowSize - the number of character the LCD can show in one column
     */
    LcdDisplayUI(int8_t colSize, int8_t rowSize);
    ~LcdDisplayUI();

    /**
     * @brief It invokes the communication between the LCD display and set the backlight of the screen to turn on.
     * 
     */
    void init();

    /**
     * @brief It updates the LCD display by changing the PageContent source from a Page object.
     * 
     * @param page - pointer of a Page object that you want to show
     */
    void update(Page *page);

    /**
     * @brief It provides a rendering function that keeps checking whether anything display on the screen is updated or not.
     * 
     */
    void render();

  private:
    // LCD size 
    int8_t rowSize, colSize;
    LiquidCrystal_I2C *lcd;
    Page *renderPage;
    bool isUpdatePage = true;
    unsigned long lastRender;
    
    char *strBuffer;
    void clearContent(PageContent *content);
    void printContent(PageContent *content);
};

#endif