#ifndef WaterSettingManager_h
#define WaterSettingManager_h

#include "ModeSetting/ScheduleModeSetting/ScheduleModeSetting.h"
#include "ModeSetting/HumidityModeSetting/HumidityModeSetting.h"
#include "../SettingManager.h"

class WaterSettingManager : public SettingManager {
    public:
        void init();
        void setScheduleModeSetting(ScheduleModeSetting setting);
        void setHumidityModeSetting(HumidityModeSetting setting);

        ScheduleModeSetting getScheduleModeSetting();
        HumidityModeSetting getHumidityModeSetting();

    private:
        ScheduleModeSetting scheduleModeSetting;
        HumidityModeSetting humidityModeSetting;
};

#endif