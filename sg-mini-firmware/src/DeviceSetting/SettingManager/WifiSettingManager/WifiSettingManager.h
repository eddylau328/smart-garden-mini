#ifndef WifiSettingManager_h
#define WifiSettingManager_h

#include "AccessPointSetting/AccessPointSetting.h"

class WifiSettingManager {
    public:
        void setIsWifiOn(bool isWifiOn);
        bool getIsWifiOn();

        void setAccessPointSetting(AccessPointSetting accessPointSetting);
        AccessPointSetting getAccessPointSetting();
    
    private:
        AccessPointSetting accessPointSetting;
        bool isWifiOn;
};

#endif