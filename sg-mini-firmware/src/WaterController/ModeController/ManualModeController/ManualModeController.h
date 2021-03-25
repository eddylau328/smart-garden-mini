#ifndef ManualModeController_h
#define ManualModeController_h

#include "../ModeController.h"

class ManualModeController : public ModeController {

    public:
        void mainLoop(WaterPumpController &waterPump);
};

#endif