#ifndef HumidityModeController_h
#define HumidityModeController_h

#include "../ModeController.h"
#include "../../../Sensors/Sensors.h"

class HumidityModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump);
};

#endif