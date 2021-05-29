#include "SetupSettingManager.h"


void SetupSettingManager::init() {
    retrieveIsInitialSetup();
    retrieveIsBeginSystemReset();
}

void SetupSettingManager::restoreDefault() {
    this->isInitialSetup = false;
    this->isBeginSystemReset = true;
    storeIsInitialSetup();
    storeIsBeginSystemReset();
}

bool SetupSettingManager::getIsInitialSetup() {
    return this->isInitialSetup;
}

void SetupSettingManager::resetInitialSetup() {
    this->isInitialSetup = true;
    storeIsInitialSetup();
}

bool SetupSettingManager::getIsBeginSystemReset() {
    return this->isBeginSystemReset;
}

void SetupSettingManager::finishSystemReset() {
    this->isBeginSystemReset = false;
    storeIsBeginSystemReset();
}

// private

void SetupSettingManager::storeIsInitialSetup() {
    char setupCode[SETUP_CODE_LENGTH];
    if (this->isInitialSetup) { 
        setupCode[0] = 0;
        setupCode[1] = 0;
        setupCode[2] = 0;
    }
    else {
        setupCode[0] = SETUP_CODE_0;
        setupCode[1] = SETUP_CODE_1;
        setupCode[2] = SETUP_CODE_2;
    }
    StorageLocation location(
        SETUP_CODE_LENGTH,
        SETUP_CODE_STORE_INDEX
    );
    CharArrayData data(setupCode, location);
    Storage::set(data);
}

void SetupSettingManager::retrieveIsInitialSetup() {
    StorageLocation location(
        SETUP_CODE_LENGTH,
        SETUP_CODE_STORE_INDEX
    );
    CharArrayData data(location);
    Storage::get(data);
    char *setupCode = data.getData();
    this->isInitialSetup = !(
        setupCode[0] == SETUP_CODE_0 &&
        setupCode[1] == SETUP_CODE_1 &&
        setupCode[2] == SETUP_CODE_2
    );
}

void SetupSettingManager::storeIsBeginSystemReset() {
    StorageLocation location(
        IS_BEGIN_SYSTEM_RESET_LENGTH,
        IS_BEGIN_SYSTEM_RESET_STORE_INDEX
    );
    BooleanData data(
        this->isBeginSystemReset,
        location
    );
    Storage::set(data);
}

void SetupSettingManager::retrieveIsBeginSystemReset() {
    StorageLocation location(
        IS_BEGIN_SYSTEM_RESET_LENGTH, 
        IS_BEGIN_SYSTEM_RESET_STORE_INDEX
    );
    BooleanData data(location);
    Storage::get(data);
    this->isBeginSystemReset = data.getData();
}