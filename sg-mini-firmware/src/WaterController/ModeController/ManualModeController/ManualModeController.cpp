#include "ManualModeController.h"

void ManualModeController::mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting) {
    if (waterPump.getIsWaterPumpOn() == false && isTurnOn) {
        isTurnOn = false;
        waterPump.waterOn(2000);
    }
}