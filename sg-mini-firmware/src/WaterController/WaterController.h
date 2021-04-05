#ifndef WaterController_h
#define WaterController_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../Config/Config.h"
#include "../DeviceSetting/DeviceSetting.h"
#include "WaterPumpController/WaterPumpController.h"

// all the mode controllers
#include "ModeController/ModeController.h"
#include "ModeController/ManualModeController/ManualModeController.h"
#include "ModeController/ScheduleModeController/ScheduleModeController.h"
#include "ModeController/HumidityModeController/HumidityModeController.h"
#include "WaterModeSetting/WaterModeSetting.h"

/**
 * @brief provides functions for the smart-garden-mini kit control actions, e.g. watering the plants
 * 
 */

#define TOTAL_WATER_MODE 3

class WaterController {

  public:
    enum WaterMode {
      ManualMode = 0,
      ScheduleMode = 1,
      HumidityMode = 2,
    };

    WaterController();
    ~WaterController();

    static void init();
    static void mainLoop();
    static bool setMode(WaterController::WaterMode mode);
    static WaterController::WaterMode getMode();

    static void setWaterModeSetting(ScheduleModeSetting scheduleModeSetting);
    static void setWaterModeSetting(HumidityModeSetting HumidityModeSetting);
    static WaterModeSetting getWaterModeSetting();
  
  private:
    static void initInterval();
    static void setupModeControllers();

    static void onTimer();
    static bool isTimerUpdated();

    static hw_timer_t *timer;
    static volatile int interruptCounter;
    static portMUX_TYPE timerMux;

    static WaterPumpController waterPumpController;
    static ModeController **modeControllers;
    static WaterMode currentMode;
    static WaterModeSetting modeSetting;
};

#endif