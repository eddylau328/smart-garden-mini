#ifndef WaterController_h
#define WaterController_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../Config/Config.h"
#include "WaterPumpController/WaterPumpController.h"

#include "WaterControllerConstant.h"

// all the mode controllers
#include "ModeController/ModeController.h"
#include "ModeController/ManualModeController/ManualModeController.h"
#include "ModeController/ScheduleModeController/ScheduleModeController.h"
#include "ModeController/HumidityModeController/HumidityModeController.h"
#include "../DeviceSetting/DeviceManager.h"

/**
 * @brief provides functions for the smart-garden-mini kit control actions, e.g. watering the plants
 * 
 */


class WaterController {

  public:
    WaterController();
    ~WaterController();

    static void init();
    static void mainLoop();
    static bool setMode(WaterControllerConstant::WaterMode mode);
    static WaterControllerConstant::WaterMode getMode();
    static bool getIsWaterPumpOn();

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
    static WaterControllerConstant::WaterMode currentMode;

};

#endif