#include "DeviceManager.h"


SetupSettingManager *DeviceManager::setupSettingManager;
WifiSettingManager *DeviceManager::wifiSettingManager;
WaterSettingManager *DeviceManager::waterSettingManager;
LocalSettingManager *DeviceManager::localSettingManager;


void DeviceManager::init() {
    setupSettingManager = new SetupSettingManager();
    localSettingManager = new LocalSettingManager();
    wifiSettingManager = new WifiSettingManager();
    waterSettingManager = new WaterSettingManager();

    setupSettingManager->init();
    if (setupSettingManager->getIsInitialSetup()) {
        Storage::clearAll();
        localSettingManager->restoreDefault();
        waterSettingManager->restoreDefault();
        wifiSettingManager->restoreDefault();
        setupSettingManager->restoreDefault();
    }

    setupSettingManager->init();
    localSettingManager->init();
    waterSettingManager->init();
    wifiSettingManager->init();
}

SetupSettingManager* DeviceManager::getSetupSettingManager() {
    return setupSettingManager;
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