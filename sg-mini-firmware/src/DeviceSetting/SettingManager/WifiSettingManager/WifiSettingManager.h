#ifndef WifiSettingManager_h
#define WifiSettingManager_h

#include "AccessPointSetting/AccessPointSetting.h"
#include "../SettingManager.h"
#include "../../../Storage/StorageData/BooleanData/BooleanData.h"
#include "../../../Storage/StorageData/CharArrayData/CharArrayData.h"

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

        void storeIsWifiOn();
        void retrieveIsWifiOn();

        void storeAccessPointSetting();
        void retrieveAccessPointSetting();
};

#endif