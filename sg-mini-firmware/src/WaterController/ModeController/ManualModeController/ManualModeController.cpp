#include "ManualModeController.h"

void ManualModeController::mainLoop(WaterPumpController &waterPump) {
    if (waterPump.getIsWaterPumpOn() == false) {
        waterPump.waterOn(2000);
    }
}