#ifndef Controller_h
#define Controller_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../Config/Config.h"
#include "../DeviceSetting/DeviceSetting.h"

/**
 * @brief provides functions for the smart-garden-mini kit control actions, e.g. watering the plants
 * 
 */
class Controller {

  public:
    Controller();
    ~Controller();

    void init();
    void mainLoop();
  
  private:
    void initInterval();
    void scheduleTask();

    void AutomodeTask();
    void ScheduleModeTask();
    void ManualModeTask();

    enum State{
      Wateron =1,
      Automoderunning,
      ScheduleModerunning,
      ManuelModerunnung,
    };

    static void onTimer();

    hw_timer_t *timer = NULL;
    static volatile int interruptCounter;
    static portMUX_TYPE timerMux;
};

#endif