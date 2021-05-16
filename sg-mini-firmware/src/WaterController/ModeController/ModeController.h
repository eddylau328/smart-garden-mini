#ifndef ModeController_h
#define ModeController_h

#include "../WaterPumpController/WaterPumpController.h"
#include "../../DeviceSetting/SettingManager/WaterSettingManager/WaterSettingManager.h"
#include "../../DeviceSetting/SettingManager/WaterSettingManager/ModeSetting/ScheduleModeSetting/ScheduleModeSetting.h"
#include "../../DeviceSetting/SettingManager/WaterSettingManager/ModeSetting/HumidityModeSetting/HumidityModeSetting.h"


class ModeController {

    public:
        virtual void mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) = 0;
        bool getIsIdle();
    
    protected:
        void setIsIdle(bool isIdle);
    
    private:
        bool isIdle = true;
};

#endif