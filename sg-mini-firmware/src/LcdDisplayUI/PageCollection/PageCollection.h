#ifndef PageCollection_h
#define PageCollection_h

#define TotalPage 21 // Modify it if you want to add page

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
      ControlPageKey = 6,
      ModeSettingPageKey = 7,
      ManualSettingPageKey = 8,
      HumiditySettingPageKey = 9,
      ScheduleSettingPageKey = 10,
      WifiSettingPageKey = 11,
      ScanWifiPageKey = 12,
      WifiNamePageKey = 13,
      WifiPasswordPageKey = 14,
      WifiConnectPageKey = 15,
      SetDefaultWifiPageKey = 16,
      WelcomePageKey = 17,
      SetupFinishPageKey = 18,
      RestoreDefaultPageKey = 19,
      ConfirmRestorePageKey = 20,
    };
};

#endif