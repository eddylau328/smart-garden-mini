#include "ManualModeSetting.h"

ManualModeSetting::ManualModeSetting() {
    this->isTurnOnWaterPump = false;
    this->turnOnDuration = 0;
}

ManualModeSetting::ManualModeSetting(uint8_t duration) {
    this->isTurnOnWaterPump = false;
    this->turnOnDuration = duration;
}

void ManualModeSetting::setIsTurnOnWaterPump(bool isTurnOn) {
    this->isTurnOnWaterPump = isTurnOn;
}

bool ManualModeSetting::getIsTurnOnWaterPump() {
    return this->isTurnOnWaterPump;
}

void ManualModeSetting::setTurnOnDuration(uint8_t duration) {
    this->turnOnDuration = duration;
}

uint8_t ManualModeSetting::getTurnOnDuration() {
    return this->turnOnDuration;
}

void ManualModeSetting::operator = (const ManualModeSetting &setting ) { 
    this->isTurnOnWaterPump = setting.isTurnOnWaterPump;
    this->turnOnDuration = setting.turnOnDuration;
}