#include "ManualModeController.h"

void ManualModeController::mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) {
    ManualModeSetting setting = modeSetting.getManualModeSetting();
    if (waterPump.getIsWaterPumpOn() == false && 
        setting.getIsTurnOnWaterPump()) {
        setting.setIsTurnOnWaterPump(false);
        waterPump.waterOn(((unsigned long) setting.getTurnOnDuration()) * 1000);
    }
}