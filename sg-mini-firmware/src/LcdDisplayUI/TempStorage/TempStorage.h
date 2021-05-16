#ifndef TempStorage_h
#define TempStorage_h

#include <Arduino.h>
#include "../../Helper/Helper.h"
#include "../../DeviceSetting/SettingManager/WifiSettingManager/AccessPointSetting/AccessPointSetting.h"

class TempStorage {
    public:
        static void init();
        static AccessPointSetting getAccessPointSetting();
        static void setAccessPointSetting(AccessPointSetting newAccessPointSetting);

    private:
        static AccessPointSetting accessPointSetting;

};

#endif