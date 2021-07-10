#include "DeviceManager.h"


SetupSettingManager *DeviceManager::setupSettingManager;
WifiSettingManager *DeviceManager::wifiSettingManager;
WaterSettingManager *DeviceManager::waterSettingManager;
LocalSettingManager *DeviceManager::localSettingManager;
DataTransmitManager *DeviceManager::dataTransmitManager;


void DeviceManager::init() {
    setupSettingManager = new SetupSettingManager();
    localSettingManager = new LocalSettingManager();
    wifiSettingManager = new WifiSettingManager();
    waterSettingManager = new WaterSettingManager();
    dataTransmitManager = new DataTransmitManager();

    setupSettingManager->init();
    if (setupSettingManager->getIsInitialSetup()) {
        Storage::clearAll();
        localSettingManager->restoreDefault();
        waterSettingManager->restoreDefault();
        wifiSettingManager->restoreDefault();
        setupSettingManager->restoreDefault();
        dataTransmitManager->restoreDefault();
    }

    setupSettingManager->init();
    localSettingManager->init();
    waterSettingManager->init();
    wifiSettingManager->init();
    dataTransmitManager->init();
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

DataTransmitManager* DeviceManager::getDataTransmitManager() {
    return dataTransmitManager;
}