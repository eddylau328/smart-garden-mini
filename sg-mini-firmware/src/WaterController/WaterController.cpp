#include "WaterController.h"


hw_timer_t *WaterController::timer = NULL;
portMUX_TYPE WaterController::timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile int WaterController::interruptCounter = 0;

WaterPumpController WaterController::waterPumpController;
ModeController **WaterController::modeControllers = new ModeController *[TOTAL_WATER_MODE];
WaterController::WaterMode WaterController::currentMode;

WaterController::WaterController() {}

WaterController::~WaterController() {}

void WaterController::init() {
    waterPumpController.init();
    initInterval();
    setupModeControllers();
}

void WaterController::mainLoop() {
    if (isTimerUpdated()) {
        waterPumpController.mainLoop(); 
        modeControllers[currentMode]->mainLoop(waterPumpController);
    }
}

bool WaterController::setMode(WaterController::WaterMode mode) {
    if (currentMode != mode && modeControllers[currentMode]->getIsIdle()) {
        currentMode = mode;
        return true;
    }
    return currentMode == mode;
}

WaterController::WaterMode WaterController::getMode() {
    return currentMode;
}

bool WaterController::isTimerUpdated() {
    if (interruptCounter > 0) {
        portENTER_CRITICAL(&timerMux);
        interruptCounter--;
        portEXIT_CRITICAL(&timerMux);
        return true;
    }
    return false;
}

void WaterController::onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    interruptCounter++;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void WaterController::initInterval() {
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, ReadingInterval, true);
    timerAlarmEnable(timer);
}

void WaterController::setupModeControllers() {
    modeControllers[WaterMode::ManualMode] = new ManualModeController();
    modeControllers[WaterMode::ScheduleMode] = new ScheduleModeController();
    modeControllers[WaterMode::HumidityMode] = new HumidityModeController();
}