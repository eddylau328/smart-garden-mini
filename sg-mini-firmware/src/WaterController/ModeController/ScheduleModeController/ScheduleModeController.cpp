#include "ScheduleModeController.h"


void ScheduleModeController::mainLoop(WaterPumpController &waterPump) {
    // reach the next water time
    //DateTime currentTime = DateTime(2021, 3, 28, 22, 30, 0);
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
    currentTime = RTC_DS1307::now();
    TimeSpan timeinterval (scheduleDuration);

    if (currentTime.operator>=(nextWaterTime) )
        {
          Serial.println(String("Water is on by time : "+ currentTime.timestamp()  ));
          waterPump.waterOn(waterDuration);
          nextWaterTime = currentTime + timeinterval;
          // Why i can't use waterPump.operator+(timeinterval); at upper line? it modify nothing
          Serial.println(String("The next watering time is : " + nextWaterTime.timestamp() ));
        }
}

void ScheduleModeController::setwaterDuration(unsigned long Duration){ // Maybe better call from devicesetting?
    waterDuration = Duration;
}

void ScheduleModeController::updateSchedule(unsigned long schedule){
    scheduleDuration = schedule;
};