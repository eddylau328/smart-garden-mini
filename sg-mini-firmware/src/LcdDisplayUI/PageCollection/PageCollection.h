#ifndef PageCollection_h
#define PageCollection_h

#include <Arduino.h>

class Page {

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
};

#endif