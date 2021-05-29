#ifndef WaterSettingManager_h
#define WaterSettingManager_h

#include "ModeSetting/ScheduleModeSetting/ScheduleModeSetting.h"
#include "ModeSetting/HumidityModeSetting/HumidityModeSetting.h"
#include "../SettingManager.h"
#include "../../../WaterController/WaterControllerConstant.h"


class WaterSettingManager : public SettingManager {
    public:
        void init();
        void restoreDefault();

        void setWaterMode(WaterControllerConstant::WaterMode mode);
        void setScheduleModeSetting(ScheduleModeSetting setting);
        void setHumidityModeSetting(HumidityModeSetting setting);

        ScheduleModeSetting getScheduleModeSetting();
        HumidityModeSetting getHumidityModeSetting();
        WaterControllerConstant::WaterMode getWaterMode();

    private:
        WaterControllerConstant::WaterMode waterMode;
        ScheduleModeSetting scheduleModeSetting;
        HumidityModeSetting humidityModeSetting;
        
        // methods 

        void storeWaterMode();
        void retrieveWaterMode();

        void storeScheduleModeSetting();
        void retrieveScheduleModeSetting();

        void storeHumidityModeSetting();
        void retrieveHumidityModeSetting();
};

#endif