#include "ManualModeController.h"

void ManualModeController::mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) {
    if (waterPump.getIsWaterPumpOn() == false && isTurnOn) {
        isTurnOn = false;
        waterPump.waterOn(2000);
    }
}