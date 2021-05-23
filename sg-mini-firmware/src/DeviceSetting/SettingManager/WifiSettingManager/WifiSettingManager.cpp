#include "WifiSettingManager.h"


void WifiSettingManager::init() {
    retrieveIsWifiOn();
    retrieveAccessPointSetting();
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

void WifiSettingManager::storeIsWifiOn() {
    BooleanData data(
        this->isWifiOn,
        StorageLocation(
            WIFI_ENABLED_LENGTH,
            WIFI_ENABLED_STORE_INDEX
        )
    );
    Storage::set(data);
}

void WifiSettingManager::retrieveIsWifiOn() {
    BooleanData data(StorageLocation(
        WIFI_ENABLED_LENGTH,
        WIFI_ENABLED_STORE_INDEX
    ));
    Storage::get(data);
    this->isWifiOn = data.getData();
}

void WifiSettingManager::storeAccessPointSetting() {
    CharArrayData wifiNameData(
        this->accessPointSetting.getAccessPointName(),
        StorageLocation(
            WIFI_NAME_LENGTH,
            WIFI_NAME_STORE_INDEX
        )
    );
    Storage::set(wifiNameData);

    CharArrayData wifiPasswordData(
        this->accessPointSetting.getAccessPointPassword(),
        StorageLocation(
            WIFI_PASSWORD_LENGTH,
            WIFI_PASSWORD_STORE_INDEX
        )
    );
    Storage::set(wifiPasswordData);
}

void WifiSettingManager::retrieveAccessPointSetting() {
    CharArrayData wifiNameData(StorageLocation(
        WIFI_NAME_LENGTH,
        WIFI_NAME_STORE_INDEX
    ));
    Storage::get(wifiNameData);

    CharArrayData wifiPasswordData(StorageLocation(
        WIFI_PASSWORD_LENGTH,
        WIFI_PASSWORD_STORE_INDEX
    ));
    Storage::get(wifiPasswordData);

    setAccessPointSetting(AccessPointSetting(
        wifiNameData.getData(), 
        wifiPasswordData.getData()
    ));
}