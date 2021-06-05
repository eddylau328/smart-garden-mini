#include "LocalSettingManager.h"


void LocalSettingManager::init() {
    // initialize clock
    // clock.begin();
    // retrieve storage data
    retrieveIsUsernameSet();
    Serial.print("isUsernameSet ");
    Serial.println((int) isUsernameSet);
    if (this->isUsernameSet)
        retrieveUsername();
}

void LocalSettingManager::restoreDefault() {
    this->isUsernameSet = false;
    this->storeIsUsernameSet();
    this->storeUsername();
}

DateTime LocalSettingManager::getDeviceDateTime() {
    return clock.now();
}

void LocalSettingManager::setDeviceDateTime(DateTime dateTime) {
    clock.adjust(dateTime);
}

bool LocalSettingManager::getIsClockRunning() {
    return (bool) clock.isrunning();
}

bool LocalSettingManager::getIsUsernameSet() {
    return this->isUsernameSet;
}

const char* LocalSettingManager::getUsername() {
    return this->username;
}

void LocalSettingManager::setUsername(char *username) {
    int length = Helper::getStringLength(username);
    Helper::copyString(this->username, username, length);
    this->storeUsername();

    this->isUsernameSet = true;
    storeIsUsernameSet();
}

void LocalSettingManager::setUsername(const char *username) {
    int length = Helper::getStringLength(username);
    Helper::copyString(this->username, username, length);
    this->storeUsername();
    Serial.println("finish store username");
    this->isUsernameSet = true;
    storeIsUsernameSet();
    Serial.println("finish store isUsernameSet");
}

// private

void LocalSettingManager::storeUsername() {
    StorageLocation location(USERNAME_LENGTH, USERNAME_STORE_INDEX);
    CharArrayData data(this->username, location);
    Storage::set(data);
}

void LocalSettingManager::retrieveUsername() {
    StorageLocation location(USERNAME_LENGTH, USERNAME_STORE_INDEX);
    CharArrayData data(location);
    Storage::get(data);
    Helper::copyString(this->username, data.getData(), USERNAME_LENGTH);
}

void LocalSettingManager::storeIsUsernameSet() {
    StorageLocation location(IS_USERNAME_SET_LENGTH, IS_USERNAME_SET_STORE_INDEX);
    BooleanData isUsernameSetData = BooleanData(this->isUsernameSet, location);
    Storage::set(isUsernameSetData);
}

void LocalSettingManager::retrieveIsUsernameSet() {
    StorageLocation location = StorageLocation(
        IS_USERNAME_SET_LENGTH, 
        IS_USERNAME_SET_STORE_INDEX
    );
    BooleanData isUsernameSetData = BooleanData(location);
    Storage::get(isUsernameSetData);
    this->isUsernameSet = isUsernameSetData.getData();
}