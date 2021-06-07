#ifndef PageControl_h
#define PageControl_h

#include <Arduino.h>
#include "LcdDisplayUI.h"

// Page Collection -------------------------------------
#include "PageCollection/PageCollection.h"
#include "PageCollection/Page.h"
#include "PageCollection/MainPage/MainPage.h"
#include "PageCollection/SensorPage/SensorPage.h"
#include "PageCollection/SettingPage/SettingPage.h"
#include "PageCollection/SettingPage/TimeSettingPage/TimeSettingPage.h"
#include "PageCollection/SettingPage/DateSettingPage/DateSettingPage.h"
#include "PageCollection/SettingPage/UsernameSettingPage/UsernameSettingPage.h"
#include "PageCollection/SettingPage/RestoreDefaultPage/RestoreDefaultPage.h"
#include "PageCollection/ControlPage/ControlPage.h"
#include "PageCollection/ControlPage/Mode/ModeSettingPage.h"
#include "PageCollection/ControlPage/Mode/HumiditySettingPage/HumiditySettingPage.h"
#include "PageCollection/ControlPage/Mode/ScheduleSettingPage.h"
#include "PageCollection/ControlPage/Mode/ManualSettingPage.h"
#include "PageCollection/WifiSettingPage/WifiSettingPage.h"
#include "PageCollection/WifiSettingPage/ScanWifiPage/ScanWifiPage.h"
#include "PageCollection/WifiSettingPage/JoinWifiPage/WifiNamePage/WifiNamePage.h"
#include "PageCollection/WifiSettingPage/JoinWifiPage/WifiPasswordPage/WifiPasswordPage.h"
#include "PageCollection/WifiSettingPage/JoinWifiPage/WifiConnectPage/WifiConnectPage.h"
#include "PageCollection/WifiSettingPage/JoinWifiPage/SetDefaultWifi/SetDefaultWifiPage.h"
#include "PageCollection/SetupPage/WelcomePage/WelcomePage.h"
#include "PageCollection/SetupPage/SetupFinishPage/SetupFinishPage.h"
#include "PageCollection/SetupPage/ConfirmRestorePage/ConfirmRestorePage.h"
// -----------------------------------------------------

// Class you need to display data / information --------
#include "RotaryEncoder.h"
#include "../DeviceSetting/DeviceManager.h"
// -----------------------------------------------------

/**
 * @brief provides the control logic of the page and initialize all the pages that will show to the display
 * 
 */
class PageControl {

  public:
    // Add PageKey if you add a new page

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
    static uint8_t nextPageKey;

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
     * @brief It creates all the pages that will show to the screen
     * 
     */
    void pageInit();

    /**
     * @brief It set the current page to the correct current page when setup
     * 
     */
    void retrieveCurrentPage();

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
