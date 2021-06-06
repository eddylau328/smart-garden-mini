#include "WaterController.h"


hw_timer_t *WaterController::timer = NULL;
portMUX_TYPE WaterController::timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile int WaterController::interruptCounter = 0;

WaterPumpController WaterController::waterPumpController;
ModeController **WaterController::modeControllers = new ModeController *[TOTAL_WATER_MODE];
WaterControllerConstant::WaterMode WaterController::currentMode = WaterControllerConstant::WaterMode::ManualMode;

WaterController::WaterController() {}

WaterController::~WaterController() {}

void WaterController::init() {
    waterPumpController.init();
    initInterval();
    setupModeControllers();
}

void WaterController::mainLoop() {
    if (isTimerUpdated()) {
        WaterSettingManager *setting = DeviceManager::getWaterSettingManager();
        waterPumpController.mainLoop(); 
        modeControllers[currentMode]->mainLoop(waterPumpController, *setting);
    }
}

bool WaterController::setMode(WaterControllerConstant::WaterMode mode) {
    if (currentMode != mode && modeControllers[currentMode]->getIsIdle()) {
        currentMode = mode;
        return true;
    }
    return currentMode == mode;
}

WaterControllerConstant::WaterMode WaterController::getMode() {
    return currentMode;
}

bool WaterController::getIsWaterPumpOn() {
    return waterPumpController.getIsWaterPumpOn();
}

// private

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
    timerAlarmWrite(timer, WATER_CONTROLLER_INTERVAL, true);
    timerAlarmEnable(timer);
}

void WaterController::setupModeControllers() {
    modeControllers[WaterControllerConstant::WaterMode::ManualMode] = new ManualModeController();
    modeControllers[WaterControllerConstant::WaterMode::ScheduleMode] = new ScheduleModeController();
    modeControllers[WaterControllerConstant::WaterMode::HumidityMode] = new HumidityModeController();
}