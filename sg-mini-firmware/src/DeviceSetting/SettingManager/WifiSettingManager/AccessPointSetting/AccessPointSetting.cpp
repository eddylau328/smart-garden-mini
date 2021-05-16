#include "AccessPointSetting.h"


AccessPointSetting::AccessPointSetting() {}

AccessPointSetting::AccessPointSetting(char *accessPointName, char *accessPointPassword) {
    setAccessPointName(accessPointName, Helper::getStringLength(accessPointName));
    setAccessPointPassword(accessPointPassword, Helper::getStringLength(accessPointPassword));
}

AccessPointSetting::AccessPointSetting(const char* accessPointName, const char* accessPointPassword) {
    setAccessPointName(accessPointName, Helper::getStringLength(accessPointName));
    setAccessPointPassword(accessPointPassword, Helper::getStringLength(accessPointPassword));
}

char* AccessPointSetting::getAccessPointName() {
    return this->accessPointName;
}

char* AccessPointSetting::getAccessPointPassword() {
    return this->accessPointPassword;
}

void AccessPointSetting::setAccessPointName(const char *accessPointName, size_t bufferSize) {
   Helper::copyString(this->accessPointName, 
                      accessPointName, 
                      bufferSize > ACCESS_POINT_NAME_BUFFER_SIZE ? 
                      ACCESS_POINT_NAME_BUFFER_SIZE : bufferSize);
}

void AccessPointSetting::setAccessPointName(char *accessPointName, size_t bufferSize) {
   Helper::copyString(this->accessPointName, 
                      accessPointName, 
                      bufferSize > ACCESS_POINT_NAME_BUFFER_SIZE ? 
                      ACCESS_POINT_NAME_BUFFER_SIZE : bufferSize);
}

void AccessPointSetting::setAccessPointPassword(const char *accessPointPassword, size_t bufferSize) {
   Helper::copyString(this->accessPointPassword, 
                      accessPointPassword, 
                      bufferSize > ACCESS_POINT_PASSWORD_BUFFER_SIZE ? 
                      ACCESS_POINT_PASSWORD_BUFFER_SIZE : bufferSize);
}

void AccessPointSetting::setAccessPointPassword(char *accessPointPassword, size_t bufferSize) {
   Helper::copyString(this->accessPointPassword, 
                      accessPointPassword, 
                      bufferSize > ACCESS_POINT_PASSWORD_BUFFER_SIZE ? 
                      ACCESS_POINT_PASSWORD_BUFFER_SIZE : bufferSize);
}

AccessPointSetting& AccessPointSetting::operator=(const AccessPointSetting& target) {
    setAccessPointName(target.accessPointName, 
                       Helper::getStringLength(target.accessPointName));
    setAccessPointPassword(target.accessPointPassword,
                           Helper::getStringLength(target.accessPointPassword));
}