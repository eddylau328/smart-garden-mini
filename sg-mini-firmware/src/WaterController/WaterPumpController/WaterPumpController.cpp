#include "WaterPumpController.h"

void WaterPumpController::init() {
    pinMode(WATER_PUMP_PIN, OUTPUT);
    waterPumpOffAction();
}

void WaterPumpController::waterOn(unsigned long turnOnDuration, bool isOverideControl) {
    if (isOverideControl || !isTurnOn) {
        this->turnOnDuration = turnOnDuration;
        this->controlState = ControlState::TurnOn;
    }
}

void WaterPumpController::waterOff() {
    this->controlState = ControlState::TurnOff;
}

bool WaterPumpController::getIsWaterPumpOn() {
    return this->isTurnOn;
}

void WaterPumpController::mainLoop() {
    switch(controlState) {
        case ControlState::TurnOff:
            waterPumpOffAction();
            break;
        case ControlState::TurnOn:
            waterPumpOnAction();
            break;
        case ControlState::Working:
            waterPumpWorkingAction();
            break;
        case ControlState::Idle:
            break;
        default:
            break;
    }
}

bool WaterPumpController::validateTurnOnDuration(unsigned long turnOnDuration) {
    return 0 <= turnOnDuration && turnOnDuration <= MAX_WATER_PUMP_ON_TIME;
}

bool WaterPumpController::isFinishWatering() {
    return millis() - startTime > this->turnOnDuration;
}

void WaterPumpController::waterPumpOnAction() {
    setWaterPumpOnOff(true);
    controlState = ControlState::Working;
    startTime = millis();
}

void WaterPumpController::waterPumpOffAction() {
    setWaterPumpOnOff(false);
    controlState = ControlState::Idle;
}

void WaterPumpController::waterPumpWorkingAction() {
    if (isFinishWatering())
        controlState = ControlState::TurnOff;
}

void WaterPumpController::setWaterPumpOnOff(bool isTurnOn) {
    this->isTurnOn = isTurnOn;
    if (isTurnOn)
        LOG_WARNING("Water Pump is On");
    else
        LOG_WARNING("Water Pump is Off");
    digitalWrite(WATER_PUMP_PIN, isTurnOn? WATER_PUMP_ON : WATER_PUMP_OFF);
}