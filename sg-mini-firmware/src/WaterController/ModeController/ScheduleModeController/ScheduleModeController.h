#ifndef ScheduleModeController_h
#define ScheduleModeController_h

#include "../ModeController.h"
#include <RTClib.h>
#include "../../../DeviceSetting/DeviceSetting.h"
#include "../../../Sensors/Sensors.h"



class ScheduleModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting);
        void setwaterDuration(unsigned long Duration);
        void updateSchedule(unsigned long schedule);

        DateTime currentTime = DateTime(2021, 3, 28, 12, 12, 12);
        DateTime nextWaterTime = DateTime(2021, 3, 28, 12, 12, 12);

    private:
        unsigned long waterDuration = 1000;
        unsigned long scheduleDuration = 86400;
        bool doneWater = false;
        unsigned int wateringBreak = 5000;
        unsigned long lastWatering;
};

#endif