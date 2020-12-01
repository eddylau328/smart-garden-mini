#ifndef PageControl_h
#define PageControl_h

#include <Arduino.h>
#include "LcdDisplayUI.h"

// Page Collection -------------------------------------
#define TotalPage 2 // Modify it if you want to add page
#include "PageCollection/Page.h"
#include "PageCollection/MainPage/MainPage.h"
#include "PageCollection/SensorPage/SensorPage.h"
// -----------------------------------------------------

// Class you need to display data / information --------
#include "../Sensors/Sensors.h"
// -----------------------------------------------------

class PageControl {

  // Add PageKey if you add a new page
  enum PageKey {
    MainPageKey,
    SensorPageKey
  };

  public:
    PageControl(LcdDisplayUI *display);
    ~PageControl();

    /** Parse in all the object pointer that you need to use to call in page object
     * @param sensors Sensors Class Object for reading all the sensors data 
     */
    void init(Sensors *sensors);

    void mainLoop();

  private:
    Page *pages[TotalPage];
    uint8_t currentPageKey = PageKey::SensorPageKey;

    LcdDisplayUI *display;

    unsigned long lastUpdate;

    // Main loop function for controlling all the page
    void handleUI();
    void handleUpdateContents();
};

#endif
