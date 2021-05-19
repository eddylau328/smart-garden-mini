#include "LocalSettingManager.h"


void LocalSettingManager::init() {
    // initialize clock
    clock.begin();
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
}

void LocalSettingManager::setUserName(const char *username) {
    int length = Helper::getStringLength(username);
    Helper::copyString(this->username, username, length);
}