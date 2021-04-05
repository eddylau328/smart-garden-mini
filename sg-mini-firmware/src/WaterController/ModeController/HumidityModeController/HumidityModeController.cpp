#include "HumidityModeController.h"

void HumidityModeController::mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting) {
}

/*
    minimum humidity level = 50%
    current humidity level = 49%
    49% < 50 % -> turn on the water valve
    ... waiting the water valve to turn off
    after the water valve turn off
    current humidity level = 54%
    if you stop it here
    then maybe 10 minutes, it drop to 49%
    but if you do not stop it here
    continue water the plant again
    it will go to 70%
    last longer, maybe 2hours later
*/