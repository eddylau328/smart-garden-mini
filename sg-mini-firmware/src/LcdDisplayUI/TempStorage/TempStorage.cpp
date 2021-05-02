#include "TempStorage.h"

AccessPointSetting TempStorage::accessPointSetting;

void TempStorage::init() {

}

void TempStorage::setAccessPointSetting(AccessPointSetting newAccessPointSetting) {
    accessPointSetting = newAccessPointSetting;
}

AccessPointSetting TempStorage::getAccessPointSetting() {
    return accessPointSetting;
}