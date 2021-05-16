#include "HumidityModeController.h"

void HumidityModeController::setDiffuseDelay(millisDelay diffuseDelay) {
    this->diffuseDelay = diffuseDelay;
}

millisDelay HumidityModeController::getDiffuseDelay() {
    return this->diffuseDelay;
}

void HumidityModeController::mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) {

    // HumidityModeSetting setting = modeSetting.getHumidityModeSetting();
    HumidityModeSetting setting = HumidityModeSetting(54.0, 45.0, 65.0);

    // target humidity level is the level you always want to keep your plant at
    float targetHumidity = 54;
    // min, max are the acceptable value for not turn on the water valve
    float minHumidity = 45;
    float maxHumidity = 65;
    float overMaxHumidity = 1.1 * maxHumidity;
    float currentHumidity;

    unsigned long waterDuration = 5000;
    unsigned long delayDuration = 10000;

    bool executedMethod = false;

    Sensors::getSensorData(SensorCollection::SensorDataType::SoilHum, currentHumidity);
     
    /**
     *  waterPump - WaterPumpController object that allows you to control the water valve
     *  
     *  methods of from the WaterPumpController you may need to use:
     *  - waterOn(unsigned long duration) : turn the valve on with a duration
     *  - waterOff() : turn the valve off manually (normally you will not need to use it)
     *  - getIsWaterPumpOn() : get water pump state to check whether you need to waterOn
     * 
     *  e.g. use it like this
     *  waterPump.waterOn() 
     */

    /* write your code below here */

    if (diffuseDelay.justFinished() && currentHumidity < minHumidity && !waterPump.getIsWaterPumpOn()) {
        // conditions for checking 
        // 1. whether the waterPump has just turned off 
        // 2. whether the water has enough time to diffuse
        waterPump.waterOn(waterDuration);
        //only wateron once and wait the diffuseDelay
        executedMethod = true; 
    }

    if (currentHumidity > overMaxHumidity && waterPump.getIsWaterPumpOn()) {
        waterPump.waterOff();
    }

    if (currentHumidity < minHumidity && !waterPump.getIsWaterPumpOn()) {
        if(!diffuseDelay.isRunning() && !executedMethod) {
            diffuseDelay.start(delayDuration);
        }
    }
    else{
        //stop timer
        diffuseDelay.stop();
        //reset the executedMethod to run when condition is true again
        executedMethod = false;
    }

}

/*
    minimum humidity  = 50%
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
    Phase 2 currentHumidity > 1.1max
    consdier difussing time & evaporating time 
*/