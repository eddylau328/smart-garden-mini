#include "WaterSettingManager.h"


void WaterSettingManager::init() {

}

void WaterSettingManager::setWaterMode(WaterControllerConstant::WaterMode mode) {
    this->waterMode = mode;    
    storeWaterMode(mode);
}

void WaterSettingManager::setScheduleModeSetting(ScheduleModeSetting setting) {
    this->scheduleModeSetting = setting;
}

void WaterSettingManager::setHumidityModeSetting(HumidityModeSetting setting) {
    this->humidityModeSetting = setting;
}

WaterControllerConstant::WaterMode WaterSettingManager::getWaterMode() {
    return this->waterMode;
}

ScheduleModeSetting WaterSettingManager::getScheduleModeSetting() {
    return this->scheduleModeSetting;
}

HumidityModeSetting WaterSettingManager::getHumidityModeSetting() {
    return this->humidityModeSetting;
}

// private methods
void WaterSettingManager::storeWaterMode(WaterControllerConstant::WaterMode mode) {
    StorageLocation storageLocation(
        WATER_CONTROLLER_MODE_LENGTH, 
        WATER_CONTROLLER_MODE_STORE_INDEX
    );
    UInt8Data data((uint8_t) mode, storageLocation);
    Storage::set(data);
}