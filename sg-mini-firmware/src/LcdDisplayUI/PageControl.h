#ifndef PageControl_h
#define PageControl_h

#include <Arduino.h>
#include "LcdDisplayUI.h"

// Page Collection -------------------------------------
#define TotalPage 6 // Modify it if you want to add page
#include "PageCollection/Page.h"
#include "PageCollection/MainPage/MainPage.h"
#include "PageCollection/SensorPage/SensorPage.h"
#include "PageCollection/SettingPage/SettingPage.h"
#include "PageCollection/SettingPage/TimeSettingPage/TimeSettingPage.h"
#include "PageCollection/SettingPage/DateSettingPage/DateSettingPage.h"
#include "PageCollection/SettingPage/UsernameSettingPage/UsernameSettingPage.h"
// -----------------------------------------------------

// Class you need to display data / information --------
#include "RotaryEncoder.h"
// -----------------------------------------------------

/**
 * @brief provides the control logic of the page and initialize all the pages that will show to the display
 * 
 */
class PageControl {

  public:
    // Add PageKey if you add a new page
    enum PageKey {
      MainPageKey = 0,
      SensorPageKey = 1,
      SettingPageKey = 2,
      TimeSettingPageKey= 3,
      DateSettingPageKey = 4,
      UsernameSettingPageKey = 5,
    };

    /**
     * @brief Construct a new Page Control object
     * 
     * @param display - the LcdDisplayUI Object for accessing the update()
     */
    PageControl(LcdDisplayUI *display);
    ~PageControl();

    /** Parse in all the object pointer that you need to use to call in page object
     * @param sensors Sensors Class Object for reading all the sensors data 
     */

    /**
     * @brief It creates the Page object array and assign the default page
     * - Add new Page derived class in here for displaying new page 
     */
    void init();

    /**
     * @brief It saves a reference pointer to the RotaryEncoder object for accessing the object methods
     * 
     * @param rotaryEncoder - RotaryEncoder Class Object for reading all the input data 
     */
    void initInput(RotaryEncoder *rotaryEncoder);

    /**
     * @brief It allows the PageControl to update the page content in a designed period of time and update the Page by user input
     * 
     */
    void mainLoop();

  private:
    static Page *pages[TotalPage];
    static uint8_t currentPageKey;
    static uint8_t newPageKey;

    LcdDisplayUI *display;
    RotaryEncoder *rotaryEncoder;

    unsigned long lastUpdate;

    /**
     * @brief It helps to assign the page which is going to display to the LCD Monitor
     * 
     */
    void handleUI();

    /**
     * @brief It helps to invoke the Page updateContents() in a designed period of time
     * 
     */
    void handleUpdateContents();

    /**
     * @brief This is a callback function which will invoke when the rotary encoder has rotate interrupt event.
     * 
     * @param counter - the counter is the rotary encoder detect how many clockwise/anti-clockwise steps the rotary encoder has been triggered
     */
    static void rotateInputCallback(int counter);

    /**
     * @brief This is a callback function which will invoke when the rotary encoder receive a press down interrupt event.
     * 
     */
    static void pressInputCallback();

    /**
     * @brief This is a callback function for Page object to tell the PageControl object to swap to different page
     * 
     * @param pageKey - the page index that you want to swap to after certain trigger or events 
     */
    static void nextPageCallback(uint8_t pageKey);
};

#endif
