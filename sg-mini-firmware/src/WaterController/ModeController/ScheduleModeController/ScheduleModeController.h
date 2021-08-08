#ifndef ScheduleModeController_h
#define ScheduleModeController_h

#include "../ModeController.h"

#include <millisDelay.h>
#include <RTClib.h>
#include "../../../DeviceSetting/DeviceManager.h"
#include "../../../Sensors/Sensors.h"



class ScheduleModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting);

    private:
        DateTime nextWaterTime;
        millisDelay diffuseDelay;

        const unsigned long WATER_ON_DURATION = 5000;
        const unsigned long DIFFUSE_DURATION = 10000;
        bool isDiffuseFinish = true;
        void updateNextWaterTime(WaterSettingManager &modeSetting);
        void updateDiffuseDelay();
};

#endif