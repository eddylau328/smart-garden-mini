#include "HumidityModeSetting.h"


HumidityModeSetting::HumidityModeSetting() {}

HumidityModeSetting::HumidityModeSetting(float targetHumidity, float minHumidity, float maxHumidity) {
    setMinHumidity(minHumidity);
    setMaxHumidity(maxHumidity);
    setTargetHumidity(targetHumidity);
}

void HumidityModeSetting::setMinHumidity(float minHumidity) {
    if (isValidHumidityLevel(minHumidity))
        this->minHumidity = minHumidity;
}

void HumidityModeSetting::setMaxHumidity(float maxHumidity) {
    if (isValidHumidityLevel(maxHumidity))
        this->maxHumidity = maxHumidity;
}

void HumidityModeSetting::setTargetHumidity(float targetHumidity) {
    bool isWithinMinMax = Helper::isInRange(targetHumidity, this->minHumidity, this->maxHumidity);
    if (isValidHumidityLevel(targetHumidity) && isWithinMinMax)
        this->targetHumidity = targetHumidity;
}

float HumidityModeSetting::getTargetHumidity() {
    return this->targetHumidity;
}

float HumidityModeSetting::getMinHumidity() {
    return this->minHumidity;
}

float HumidityModeSetting::getMaxHumidity() {
    return this->maxHumidity;
}

void HumidityModeSetting::operator = (const HumidityModeSetting &setting ) { 
    this->targetHumidity = setting.targetHumidity;
    this->minHumidity = setting.minHumidity;
    this->maxHumidity = setting.maxHumidity;
}

bool HumidityModeSetting::isValidHumidityLevel(float humidityLevel) {
    return Helper::isInRange(humidityLevel, 0.0, 100.0);
}
