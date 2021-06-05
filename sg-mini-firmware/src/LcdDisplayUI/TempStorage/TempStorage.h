#ifndef TempStorage_h
#define TempStorage_h

#include <Arduino.h>
#include <RTClib.h>
#include "../../Helper/Helper.h"
#include "../../DeviceSetting/SettingManager/WifiSettingManager/AccessPointSetting/AccessPointSetting.h"

class TempStorage {
    public:
        static void init();
        static AccessPointSetting getAccessPointSetting();
        static DateTime getDateTime();
        static void setAccessPointSetting(AccessPointSetting newAccessPointSetting);
        static void setDateTime(DateTime dateTime);

    private:
        static AccessPointSetting accessPointSetting;
        static DateTime dateTime;

};

#endif