#include "ManualModeController.h"

void ManualModeController::mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) {
    ManualModeSetting setting = modeSetting.getManualModeSetting();
    if (waterPump.getIsWaterPumpOn() == false && 
        setting.getIsTurnOnWaterPump()) {
        waterPump.waterOn(((unsigned long) setting.getTurnOnDuration()) * 1000);

        setting.setIsTurnOnWaterPump(false);
        modeSetting.setManualModeSetting(setting);
    }
}