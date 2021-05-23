#include "HumidityModeSetting.h"


HumidityModeSetting::HumidityModeSetting() {}

HumidityModeSetting::HumidityModeSetting(uint8_t targetHumidity, uint8_t minHumidity, uint8_t maxHumidity) {
    setMinHumidity(minHumidity);
    setMaxHumidity(maxHumidity);
    setTargetHumidity(targetHumidity);
}

void HumidityModeSetting::setMinHumidity(uint8_t minHumidity) {
    if (isValidHumidityLevel(minHumidity))
        this->minHumidity = minHumidity;
}

void HumidityModeSetting::setMaxHumidity(uint8_t maxHumidity) {
    if (isValidHumidityLevel(maxHumidity))
        this->maxHumidity = maxHumidity;
}

void HumidityModeSetting::setTargetHumidity(uint8_t targetHumidity) {
    bool isWithinMinMax = Helper::isInRange(targetHumidity, this->minHumidity, this->maxHumidity);
    if (isValidHumidityLevel(targetHumidity) && isWithinMinMax)
        this->targetHumidity = targetHumidity;
}

uint8_t HumidityModeSetting::getTargetHumidity() {
    return this->targetHumidity;
}

uint8_t HumidityModeSetting::getMinHumidity() {
    return this->minHumidity;
}

uint8_t HumidityModeSetting::getMaxHumidity() {
    return this->maxHumidity;
}

void HumidityModeSetting::operator = (const HumidityModeSetting &setting ) { 
    this->targetHumidity = setting.targetHumidity;
    this->minHumidity = setting.minHumidity;
    this->maxHumidity = setting.maxHumidity;
}

bool HumidityModeSetting::isValidHumidityLevel(uint8_t humidityLevel) {
    return Helper::isInRange(humidityLevel, 0, 100);
}
