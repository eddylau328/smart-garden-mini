#include "DeviceManager.h"


WifiSettingManager DeviceManager::wifiSettingManager;
WaterSettingManager DeviceManager::waterSettingManager;

WifiSettingManager DeviceManager::getWifiSettingManager() {
    return wifiSettingManager;
}

WaterSettingManager DeviceManager::getWaterSettingManager() {
    return waterSettingManager;
}