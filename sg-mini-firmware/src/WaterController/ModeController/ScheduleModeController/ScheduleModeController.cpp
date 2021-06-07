#include "ScheduleModeController.h"
#include <Arduino.h>

void ScheduleModeController::mainLoop(WaterPumpController &waterPump, WaterSettingManager &modeSetting) {
    // reach the next water time
    // DateTime currentTime = DateTime(2021, 3, 28, 22, 30, 0);
    // DateTime nextWaterTime = DateTime(2021, 3, 28, 22, 30, 0);

    // the duration between each watering event
    // unsigned long scheduleDuration = 86400;

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

    /**
     *  tasks you need to do:
     *  1. check whether the currentTime reach the nextWaterTime
     *     - tip: you can directly use ==, <, > to do the comparison between the DateTime objects
     *  2. if the currentTime reach the nextWaterTime, water the plant
     *     - tip: nextWaterTime = currentTime + TimeSpan(scheduleDuration)
     *  3. if not, do nothing, go back to 1
     *  4. after finish water the plant, calculate the next watering time, then go back to 1
     *  5. Log the nextWaterTime after calculate it, using Serial.println()
     *     - tip: nextWaterTime.timestamp()
     */

    /* write your code below here */
    // ScheduleModeSetting setting = modeSetting.getScheduleModeSetting();

    LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
    DateTime currentTime = localSettingManager->getDeviceDateTime();

    ScheduleModeSetting setting = modeSetting.getScheduleModeSetting();
    float targetHumidity = (float) setting.getTargetHumidity();
    float humidityLevel;
    Sensors::getSensorData(SensorCollection::SoilHum, humidityLevel);

    bool isWaterTimeReached = currentTime >= nextWaterTime;
    bool isWaterPumpOn = waterPump.getIsWaterPumpOn();
    bool isReachHumidity = humidityLevel >= targetHumidity;

    // handle the first water action
    if ((isWaterTimeReached || !isReachHumidity) && !isWaterPumpOn && isDiffuseFinish) {
        waterPump.waterOn(WATER_ON_DURATION);
        modeSetting.setLastWaterTime(currentTime);
        diffuseDelay.start(WATER_ON_DURATION + DIFFUSE_DURATION);
        updateNextWaterTime(modeSetting);
    }
    else {
        updateDiffuseDelay();
    }
}

void ScheduleModeController::updateNextWaterTime(WaterSettingManager &manager) {
    ScheduleModeSetting setting = manager.getScheduleModeSetting();
    TimeSpan timeInterval(setting.getScheduleDuration());

    DateTime lastWaterTime = manager.getLastWaterTime();

    // initialized
    if (lastWaterTime == DateTime()) {
        LocalSettingManager *localSettingManager = DeviceManager::getLocalSettingManager();
        DateTime currentTime = localSettingManager->getDeviceDateTime();
        nextWaterTime = currentTime + timeInterval;
    }
    else {
        nextWaterTime = lastWaterTime + timeInterval;
    }
}

void ScheduleModeController::updateDiffuseDelay() {
    if (diffuseDelay.isRunning())
        isDiffuseFinish = diffuseDelay.justFinished();
}