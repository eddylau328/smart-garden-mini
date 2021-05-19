#ifndef WifiSettingManager_h
#define WifiSettingManager_h

#include "AccessPointSetting/AccessPointSetting.h"
#include "../SettingManager.h"

class WifiSettingManager : public SettingManager {
    public:
        void init();
        void setIsWifiOn(bool isWifiOn);
        bool getIsWifiOn();

        void setAccessPointSetting(AccessPointSetting accessPointSetting);
        AccessPointSetting getAccessPointSetting();
    
    private:
        AccessPointSetting accessPointSetting;
        bool isWifiOn;
};

#endif