#include "WaterSettingManager.h"


void WaterSettingManager::init() {

}

void WaterSettingManager::setScheduleModeSetting(ScheduleModeSetting setting) {
    this->scheduleModeSetting = setting;
}

void WaterSettingManager::setHumidityModeSetting(HumidityModeSetting setting) {
    this->humidityModeSetting = setting;
}

ScheduleModeSetting WaterSettingManager::getScheduleModeSetting() {
    return this->scheduleModeSetting;
}

HumidityModeSetting WaterSettingManager::getHumidityModeSetting() {
    return this->humidityModeSetting;
}