#ifndef HumidityModeController_h
#define HumidityModeController_h

#include "millisDelay.h"
#include "../ModeController.h"
#include "../../../Sensors/Sensors.h"


class HumidityModeController : public ModeController {
    public:
        void init();

        void mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting);

        void setDiffuseDelay(millisDelay diffuseDelay);
        
        millisDelay getDiffuseDelay();

    private:
        millisDelay diffuseDelay;
};

#endif