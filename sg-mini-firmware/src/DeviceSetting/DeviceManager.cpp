#include "DeviceManager.h"


WifiSettingManager *DeviceManager::wifiSettingManager;
WaterSettingManager *DeviceManager::waterSettingManager;
LocalSettingManager *DeviceManager::localSettingManager;


void DeviceManager::init() {
    localSettingManager = new LocalSettingManager();
    wifiSettingManager = new WifiSettingManager();
    waterSettingManager = new WaterSettingManager();
    localSettingManager->init();
    // waterSettingManager->init();
    // wifiSettingManager->init();
}


WifiSettingManager* DeviceManager::getWifiSettingManager() {
    return wifiSettingManager;
}

WaterSettingManager* DeviceManager::getWaterSettingManager() {
    return waterSettingManager;
}

LocalSettingManager* DeviceManager::getLocalSettingManager() {
    return localSettingManager;
}