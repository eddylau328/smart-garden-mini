#include "WaterModeSetting.h"

void WaterModeSetting::setScheduleModeSetting(ScheduleModeSetting setting) {
    this->scheduleModeSetting = setting;
}

void WaterModeSetting::setHumidityModeSetting(HumidityModeSetting setting) {
    this->humidityModeSetting = setting;
}

ScheduleModeSetting WaterModeSetting::getScheduleModeSetting() {
    return this->scheduleModeSetting;
}

HumidityModeSetting WaterModeSetting::getHumidityModeSetting() {
    return this->humidityModeSetting;
}