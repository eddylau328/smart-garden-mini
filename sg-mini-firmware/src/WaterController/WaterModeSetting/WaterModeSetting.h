#ifndef WaterModeSetting_h
#define WaterModeSetting_h

#include "../../Helper/Helper.h"
#include "ModeSetting/ScheduleModeSetting/ScheduleModeSetting.h"
#include "ModeSetting/HumidityModeSetting/HumidityModeSetting.h"

class WaterModeSetting {
    public:

        void setScheduleModeSetting(ScheduleModeSetting setting);
        void setHumidityModeSetting(HumidityModeSetting setting);

        ScheduleModeSetting getScheduleModeSetting();
        HumidityModeSetting getHumidityModeSetting();

    private:
        ScheduleModeSetting scheduleModeSetting;
        HumidityModeSetting humidityModeSetting;
};

#endif