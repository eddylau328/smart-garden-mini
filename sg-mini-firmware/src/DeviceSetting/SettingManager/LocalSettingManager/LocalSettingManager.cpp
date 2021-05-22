#include "LocalSettingManager.h"


void LocalSettingManager::init() {
    // initialize clock
    // clock.begin();
    // retrieve storage data
    retrieveUsername();
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

const char* LocalSettingManager::getUserName() {
    return this->username;
}

void LocalSettingManager::setUserName(char *username) {
    int length = Helper::getStringLength(username);
    Helper::copyString(this->username, username, length);
    this->storeUsername();
}

void LocalSettingManager::setUserName(const char *username) {
    int length = Helper::getStringLength(username);
    Helper::copyString(this->username, username, length);
    this->storeUsername();
}

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