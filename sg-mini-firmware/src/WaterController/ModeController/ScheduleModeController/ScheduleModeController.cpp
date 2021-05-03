#include "ScheduleModeController.h"
#include <Arduino.h>

void ScheduleModeController::mainLoop(WaterPumpController &waterPump, WaterModeSetting &modeSetting) {
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

    ScheduleModeSetting setting = ScheduleModeSetting(86400, 50.0);

    currentTime = RTC_DS1307::now();
    TimeSpan timeInterval (setting.getScheduleDuration());
    TimeSpan recheckInterval (900); // 15mins to recheck humidity
    float humidityLevel = 100.0;
    Sensors::getSensorData(SensorCollection::SoilHum,humidityLevel);

    if (currentTime >= nextWaterTime && !waterPump.getIsWaterPumpOn() && recheck == false) {       
        if (setting.getTargetHumidity() <= humidityLevel && firstcheck == true)
        {
            nextWaterTime = currentTime + timeInterval;
            Serial.println(String("The next watering time is : " + nextWaterTime.timestamp()));
            firstcheck = false;
        }
        else if (setting.getTargetHumidity() > humidityLevel && millis() - lastWatering >= wateringBreak )
        {      
            waterPump.waterOn(waterDuration);
            Serial.println(String("Water is on by time : "+ currentTime.timestamp()));
            lastWatering = millis();
            firstcheck = true;
            }
        else 
        {
            recheck = true;
            nextWaterTime = currentTime + recheckInterval;
            Serial.println(String("The humidity is above set level, recheck will run at 15minute later on "+ nextWaterTime.timestamp()));
        }
        }
    if (recheck == true && currentTime >= nextWaterTime && !waterPump.getIsWaterPumpOn()) {
        if (setting.getTargetHumidity() <= humidityLevel){
            nextWaterTime = currentTime - recheckInterval + timeInterval;
            Serial.println(String("The next watering time is : " + nextWaterTime.timestamp()));
            recheck = firstcheck = false;
        }
        else if (setting.getTargetHumidity() > humidityLevel && millis() - lastWatering >= wateringBreak){
            waterPump.waterOn(waterDuration);
            Serial.println(String("Water is on by time : "+ currentTime.timestamp()));
            lastWatering = millis();
        }       
    }
}

void ScheduleModeController::setwaterDuration(unsigned long Duration){
    waterDuration = Duration;
}
