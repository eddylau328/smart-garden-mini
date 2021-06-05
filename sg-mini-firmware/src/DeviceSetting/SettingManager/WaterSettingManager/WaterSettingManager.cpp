#include "WaterSettingManager.h"


void WaterSettingManager::init() {
    retrieveWaterMode();
    retrieveScheduleModeSetting();
    retrieveHumidityModeSetting();
    retrieveManualModeSetting();
}

void WaterSettingManager::restoreDefault() {
    setWaterMode(WaterControllerConstant::WaterMode::ManualMode);
    setScheduleModeSetting(ScheduleModeSetting(3600000, 50));
    setHumidityModeSetting(HumidityModeSetting(50, 40, 60));
    setManualModeSetting(ManualModeSetting(5));
}


void WaterSettingManager::setWaterMode(WaterControllerConstant::WaterMode mode) {
    this->waterMode = mode;    
    storeWaterMode();
}

void WaterSettingManager::setScheduleModeSetting(ScheduleModeSetting setting) {
    this->scheduleModeSetting = setting;
    storeScheduleModeSetting();
}

void WaterSettingManager::setHumidityModeSetting(HumidityModeSetting setting) {
    this->humidityModeSetting = setting;
    storeHumidityModeSetting();
}

void WaterSettingManager::setManualModeSetting(ManualModeSetting setting) {
    this->manualModeSetting = setting;
    storeManualModeSetting();
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

ManualModeSetting WaterSettingManager::getManualModeSetting() {
    return this->manualModeSetting;
}

// private methods
void WaterSettingManager::storeWaterMode() {
    UInt8Data waterModeData(
        (uint8_t) this->waterMode, 
        StorageLocation(
            WATER_CONTROLLER_MODE_LENGTH, 
            WATER_CONTROLLER_MODE_STORE_INDEX
        )
    );
    Storage::set(waterModeData);
}

void WaterSettingManager::retrieveWaterMode() {
    StorageLocation storageLocation(
        WATER_CONTROLLER_MODE_LENGTH,
        WATER_CONTROLLER_MODE_STORE_INDEX
    );
    UInt8Data data(storageLocation);
    Storage::get(data);
    this->waterMode = static_cast<WaterControllerConstant::WaterMode>(data.getData());
}

void WaterSettingManager::storeHumidityModeSetting() {
    UInt8Data minHumidityData(
        this->humidityModeSetting.getMinHumidity(),
        StorageLocation(
            HUMIDITY_MODE_MIN_HUMIDITY_LENGTH,
            HUMIDITY_MODE_MIN_HUMIDITY_STORE_INDEX
        )
    );
    Storage::set(minHumidityData);

    UInt8Data maxHumidityData(
        this->humidityModeSetting.getMaxHumidity(),
        StorageLocation(
            HUMIDITY_MODE_MAX_HUMIDITY_LENGTH,
            HUMIDITY_MODE_MAX_HUMIDITY_STORE_INDEX
        )
    );
    Storage::set(maxHumidityData);

    UInt8Data targetHumidityData(
        this->humidityModeSetting.getTargetHumidity(),
        StorageLocation(
            HUMIDITY_MODE_TARGET_HUMIDITY_LENGTH,
            HUMIDITY_MODE_TARGET_HUMIDITY_STORE_INDEX
        )
    );
    Storage::set(targetHumidityData);
}

void WaterSettingManager::retrieveHumidityModeSetting() {
    UInt8Data minHumidityData = UInt8Data(StorageLocation(
        HUMIDITY_MODE_MIN_HUMIDITY_LENGTH,
        HUMIDITY_MODE_MIN_HUMIDITY_STORE_INDEX
    ));
    Storage::get(minHumidityData);
    this->humidityModeSetting.setMinHumidity(minHumidityData.getData());

    UInt8Data maxHumidityData = UInt8Data(StorageLocation(
        HUMIDITY_MODE_MAX_HUMIDITY_LENGTH,
        HUMIDITY_MODE_MAX_HUMIDITY_STORE_INDEX
    ));
    Storage::get(maxHumidityData);
    this->humidityModeSetting.setMaxHumidity(maxHumidityData.getData());

    UInt8Data targetHumidityData = UInt8Data(StorageLocation(
        HUMIDITY_MODE_TARGET_HUMIDITY_LENGTH,
        HUMIDITY_MODE_TARGET_HUMIDITY_STORE_INDEX
    ));
    Storage::get(targetHumidityData);
    this->humidityModeSetting.setTargetHumidity(targetHumidityData.getData());
}

void WaterSettingManager::storeScheduleModeSetting() {
    UInt8Data targetHumidityData(
        this->scheduleModeSetting.getTargetHumidity(),
        StorageLocation(
            SCHEDULE_MODE_TARGET_HUMIDITY_LENGTH,
            SCHEDULE_MODE_TARGET_HUMIDITY_STORE_INDEX
        )
    );
    Storage::set(targetHumidityData);

    UInt64Data scheduleDurationData(
        this->scheduleModeSetting.getScheduleDuration(),
        StorageLocation(
            SCHEDULE_MODE_DURATION_LENGTH,
            SCHEDULE_MODE_DURATION_STORE_INDEX
        )
    );
    Storage::set(scheduleDurationData);
}

void WaterSettingManager::retrieveScheduleModeSetting() {
    UInt8Data targetHumidityData(StorageLocation(
        SCHEDULE_MODE_TARGET_HUMIDITY_LENGTH,
        SCHEDULE_MODE_TARGET_HUMIDITY_STORE_INDEX
    ));
    Storage::get(targetHumidityData);
    this->scheduleModeSetting.setTargetHumidity(targetHumidityData.getData());

    UInt64Data durationData(StorageLocation(
        SCHEDULE_MODE_DURATION_LENGTH,
        SCHEDULE_MODE_DURATION_STORE_INDEX
    ));
    Storage::get(durationData);
    this->scheduleModeSetting.setScheduleDuration(durationData.getData());
}

void WaterSettingManager::storeManualModeSetting() {
    StorageLocation location = StorageLocation(
        MANUAL_MODE_TURN_ON_DURATION_LENGTH,
        MANUAL_MODE_TURN_ON_DURATION_STORE_INDEX
    );
    UInt8Data turnOnDurationData(
        this->manualModeSetting.getTurnOnDuration(), 
        location
    );
    Storage::set(turnOnDurationData);
}

void WaterSettingManager::retrieveManualModeSetting() {
    StorageLocation location = StorageLocation(
        MANUAL_MODE_TURN_ON_DURATION_LENGTH,
        MANUAL_MODE_TURN_ON_DURATION_STORE_INDEX
    );
    UInt8Data turnOnDurationData(location);
    Storage::get(turnOnDurationData);
    this->manualModeSetting.setTurnOnDuration(turnOnDurationData.getData());
}
