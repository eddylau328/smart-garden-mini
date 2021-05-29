#ifndef WaterPumpController_h
#define WaterPumpController_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../../Config/Config.h"

class WaterPumpController {
    public:
        void waterOn(unsigned long turnOnDuration, bool isOveride=false);
        void waterOff();
        bool getIsWaterPumpOn();

        void init();
        void mainLoop();

    private:
        enum ControlState {
            TurnOn = 1,
            TurnOff = 0,
            Working = 2,
            Idle = 3,
        };

        bool isTurnOn = false;
        unsigned long startTime;
        unsigned long turnOnDuration = 0;
        ControlState controlState = ControlState::Idle;

        bool validateTurnOnDuration(unsigned long turnOnDuration);
        bool isFinishWatering();
        void waterPumpOnAction();
        void waterPumpOffAction();
        void waterPumpWorkingAction();
        void setWaterPumpOnOff(bool isTurnOnOff);
};

#endif