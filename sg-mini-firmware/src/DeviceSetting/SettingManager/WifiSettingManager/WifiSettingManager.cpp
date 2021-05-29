#include "WifiSettingManager.h"


void WifiSettingManager::init() {
    retrieveIsWifiOn();
    retrieveIsAccessPointSet();
    if (this->isAccessPointSet)
        retrieveAccessPointSetting();
}

void WifiSettingManager::restoreDefault() {
    this->isWifiOn = false;
    this->isAccessPointSet = false;
    this->accessPointSetting = AccessPointSetting();    
    storeIsWifiOn();
    storeIsAccessPointSet();
    storeAccessPointSetting();
}

void WifiSettingManager::setIsWifiOn(bool isWifiOn) {
    this->isWifiOn = isWifiOn;
    storeIsWifiOn();
}

void WifiSettingManager::setAccessPointSetting(AccessPointSetting accessPointSetting) {
    this->accessPointSetting = accessPointSetting;
    storeAccessPointSetting();
    storeIsAccessPointSet();
}

bool WifiSettingManager::getIsWifiOn() {
    return this->isWifiOn;
}

bool WifiSettingManager::getIsAccessPointSet() {
    return this->isAccessPointSet;
}

AccessPointSetting WifiSettingManager::getAccessPointSetting() {
    return this->accessPointSetting;
}

// private

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

void WifiSettingManager::storeIsAccessPointSet() {
    BooleanData isAccessPointSetData(
        this->isAccessPointSet,
        StorageLocation(
            IS_ACCESS_POINT_SET_LENGTH,
            IS_ACCESS_POINT_SET_STORE_INDEX
        )
    );
    Storage::set(isAccessPointSetData);
}

void WifiSettingManager::retrieveIsAccessPointSet() {
    BooleanData isAccessPointSetData(StorageLocation(
        IS_ACCESS_POINT_SET_LENGTH,
        IS_ACCESS_POINT_SET_STORE_INDEX
    ));
    Storage::get(isAccessPointSetData);
    this->isAccessPointSet = isAccessPointSetData.getData();
}