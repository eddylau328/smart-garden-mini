#include "TempStorage.h"

AccessPointSetting TempStorage::accessPointSetting;
DateTime TempStorage::dateTime;

void TempStorage::init() {

}

void TempStorage::setAccessPointSetting(AccessPointSetting newAccessPointSetting) {
    accessPointSetting = newAccessPointSetting;
}

AccessPointSetting TempStorage::getAccessPointSetting() {
    return accessPointSetting;
}

DateTime TempStorage::getDateTime() {
    return dateTime;
}

void TempStorage::setDateTime(DateTime newDateTime) {
    dateTime = newDateTime;
}