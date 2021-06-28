#ifndef WifiSettingManager_h
#define WifiSettingManager_h

#include "AccessPointSetting/AccessPointSetting.h"
#include "../SettingManager.h"


class WifiSettingManager : public SettingManager {
    public:
        void init();
        void restoreDefault();
        void setIsWifiOn(bool isWifiOn);
        bool getIsWifiOn();

        bool getIsAccessPointSet();
        void setAccessPointSetting(AccessPointSetting accessPointSetting);
        AccessPointSetting getAccessPointSetting();
    
    private:
        AccessPointSetting accessPointSetting;
        bool isWifiOn;
        bool isAccessPointSet;

        void retrieveIsAccessPointSet();
        void storeIsAccessPointSet();

        void storeIsWifiOn();
        void retrieveIsWifiOn();

        void storeAccessPointSetting();
        void retrieveAccessPointSetting();
};

#endif