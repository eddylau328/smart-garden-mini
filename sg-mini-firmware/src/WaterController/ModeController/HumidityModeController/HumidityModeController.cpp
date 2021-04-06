#include "HumidityModeController.h"

void HumidityModeController::mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting) {

    // HumidityModeSetting setting = modeSetting.getHumidityModeSetting();
    HumidityModeSetting setting = HumidityModeSetting(54.0, 45.0, 65.0);

    // target humidity level is the level you always want to keep your plant at
    uint8_t targetHumidityLevel = 54;
    // min, max are the acceptable value for not turn on the water valve
    uint8_t minHumidityLevel = 45;
    uint8_t maxHumidityLevel = 65;
   // uint8_t number = 1.1 * maxHumidityLevel;
    unsigned long duration = 5000;
    
    float currentHumidityLevel;
    Sensors::getSensorData(SensorCollection::SensorDataType::SoilHum, currentHumidityLevel);

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

    if (currentHumidityLevel < minHumidityLevel && waterPump.getIsWaterPumpOn() == false) {
        waterPump.waterOn(duration);
    }
    else if (currentHumidityLevel > maxHumidityLevel && waterPump.getIsWaterPumpOn() == true) {
        waterPump.waterOff();
    }

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
    Phase 2 currentHumidity > 1.1max
    consdier difussing time & evaporating time 
*/