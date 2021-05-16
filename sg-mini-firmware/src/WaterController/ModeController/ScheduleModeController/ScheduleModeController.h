#ifndef ScheduleModeController_h
#define ScheduleModeController_h

#include "../ModeController.h"
#include <RTClib.h>
#include "../../../DeviceSetting/DeviceSetting.h"
#include "../../../Sensors/Sensors.h"



class ScheduleModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting);
        void setwaterDuration(unsigned long Duration);

        DateTime currentTime = DateTime(2021, 3, 28, 12, 12, 12);
        DateTime nextWaterTime = DateTime(2021, 3, 28, 12, 12, 12);

    private:
        unsigned long waterDuration = 1000;
        unsigned int wateringBreak = 5000;
        unsigned long lastWatering ;
        bool recheck = false;
        bool firstcheck = false;

};

#endif