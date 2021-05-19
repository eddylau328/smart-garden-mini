#include "WifiSettingManager.h"


void WifiSettingManager::init() {

}

void WifiSettingManager::setIsWifiOn(bool isWifiOn) {
    this->isWifiOn = isWifiOn;
}

void WifiSettingManager::setAccessPointSetting(AccessPointSetting accessPointSetting) {
    this->accessPointSetting = accessPointSetting;
}
bool WifiSettingManager::getIsWifiOn() {
    return this->isWifiOn;
}

AccessPointSetting WifiSettingManager::getAccessPointSetting() {
    return this->accessPointSetting;
}