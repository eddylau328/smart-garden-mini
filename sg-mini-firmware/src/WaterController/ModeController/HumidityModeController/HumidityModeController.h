#ifndef HumidityModeController_h
#define HumidityModeController_h

#include "millisDelay.h"
#include "../ModeController.h"
#include "../../../Sensors/Sensors.h"


class HumidityModeController : public ModeController {
    public:
        void mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting);
    
    private:
        millisDelay diffuseDelay;
};

#endif