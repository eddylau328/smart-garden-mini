#include "WifiSettingManager.h"


void WifiSettingManager::setIsWifiOn(bool isWifiOn) {
    this->isWifiOn = isWifiOn;
}

bool WifiSettingManager::getIsWifiOn() {
    return this->isWifiOn;
}

void WifiSettingManager::setAccessPointSetting(AccessPointSetting accessPointSetting) {
    this->accessPointSetting = accessPointSetting;
}

AccessPointSetting WifiSettingManager::getAccessPointSetting() {
    return this->accessPointSetting;
}