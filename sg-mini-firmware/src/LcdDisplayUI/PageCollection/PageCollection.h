#ifndef PageCollection_h
#define PageCollection_h

class PageCollection {

  public:
    // Add PageKey if you add a new page
    enum PageKey {
      MainPageKey = 0,
      SensorPageKey = 1,
      SettingPageKey = 2,
      TimeSettingPageKey= 3,
      DateSettingPageKey = 4,
      UsernameSettingPageKey = 5,
      ControlPagePageKey = 6,
      ModeSettingPageKey = 7,
      ManualSettingPageKey = 8,
      AutoSettingPageKey = 9,
      ScheduleSettingPageKey = 10,
      
    };
};

#endif