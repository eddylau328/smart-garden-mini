#ifndef ScheduleModeController_h
#define ScheduleModeController_h

#include "../ModeController.h"


class ScheduleModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting);
};

#endif