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
#include "../Sensors/Sensors.h"
#include "RotaryEncoder.h"
// -----------------------------------------------------

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

    PageControl(LcdDisplayUI *display);
    ~PageControl();

    /** Parse in all the object pointer that you need to use to call in page object
     * @param sensors Sensors Class Object for reading all the sensors data 
     */
    void init(Sensors *sensors);

    /** Parse in the object pointer that you need to use to call in page object
     * @param RotaryEncoder RotaryEncoder Class Object for reading all the input data 
     */
    void initInput(RotaryEncoder *rotaryEncoder);

    void mainLoop();

  private:
    static Page *pages[TotalPage];
    static uint8_t currentPageKey;
    static uint8_t newPageKey;

    LcdDisplayUI *display;
    RotaryEncoder *rotaryEncoder;

    unsigned long lastUpdate;

    // Main loop function for controlling all the page
    void handleUI();
    void handleUpdateContents();

    static void rotateInputCallback(int counter);
    static void pressInputCallback();
    static void nextPageCallback(uint8_t pageKey);
};

#endif
