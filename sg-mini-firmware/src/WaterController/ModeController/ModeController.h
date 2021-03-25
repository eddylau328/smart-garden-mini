#ifndef ModeController_h
#define ModeController_h

#include "../WaterPumpController/WaterPumpController.h"

class ModeController {

    public:
        virtual void mainLoop(WaterPumpController &waterPump) = 0;
        bool getIsIdle();
    
    protected:
        void setIsIdle(bool isIdle);
    
    private:
        bool isIdle = true;
};

#endif