#ifndef ModeController_h
#define ModeController_h

#include "../WaterPumpController/WaterPumpController.h"
#include "../WaterModeSetting/WaterModeSetting.h"
#include "../WaterModeSetting/ModeSetting/ScheduleModeSetting/ScheduleModeSetting.h"
#include "../WaterModeSetting/ModeSetting/HumidityModeSetting/HumidityModeSetting.h"


class ModeController {

    public:
        virtual void mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting) = 0;
        bool getIsIdle();
    
    protected:
        void setIsIdle(bool isIdle);
    
    private:
        bool isIdle = true;
};

#endif