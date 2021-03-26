#include "WaterControllerSetting.h"

uint8_t WaterControllerSetting::targetHumidityLevel;
uint8_t WaterControllerSetting::minHumidityLevel;
uint8_t WaterControllerSetting::maxHumidityLevel;

void WaterControllerSetting::setTargetHumidityLevel(uint8_t humidityLevel) {
    bool isValidValue = isValidHumidityLevel(humidityLevel);
    bool isWithinMinMax = Helper::uint8_tInRange(humidityLevel, minHumidityLevel, maxHumidityLevel);
    if (isValidValue && isWithinMinMax)
        targetHumidityLevel = humidityLevel;
}

void WaterControllerSetting::setMinHumidityLevel(uint8_t humidityLevel) {
    if (isValidHumidityLevel(humidityLevel) && humidityLevel <= maxHumidityLevel)
        minHumidityLevel = humidityLevel;
}

void WaterControllerSetting::setMaxHumidityLevel(uint8_t humidityLevel) {
    if (isValidHumidityLevel(humidityLevel) && humidityLevel >= minHumidityLevel)
        maxHumidityLevel = humidityLevel;
}

uint8_t WaterControllerSetting::getTargetHumidityLevel() {
    return targetHumidityLevel;
}

uint8_t WaterControllerSetting::getMinHumidityLevel() {
    return minHumidityLevel;
}

uint8_t WaterControllerSetting::getMaxHumidityLevel() {
    return maxHumidityLevel;
}

bool isValidHumidityLevel(uint8_t humidityLevel) {
    return Helper::uint8_tInRange(humidityLevel, 0, 100);
}
