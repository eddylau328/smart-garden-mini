#include "DeviceManager.h"


WifiSettingManager DeviceManager::wifiSettingManager;

WifiSettingManager DeviceManager::getWifiSettingManager() {
    return wifiSettingManager;
}

void DeviceManager::setWifiSettingManager(WifiSettingManager manager) {
    wifiSettingManager = manager;
}