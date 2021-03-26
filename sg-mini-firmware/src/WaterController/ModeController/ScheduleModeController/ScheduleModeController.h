#ifndef ScheduleModeController_h
#define ScheduleModeController_h

#include "../ModeController.h"
#include <RTClib.h>

class ScheduleModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump);
};

#endif