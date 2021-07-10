#ifndef SettingManager_h
#define SettingManager_h

#include <Arduino.h>

#include "../../Storage/StorageData/CharArrayData/CharArrayData.h"
#include "../../Storage/StorageData/UCharArrayData/UCharArrayData.h"
#include "../../Storage/StorageData/UInt8Data/UInt8Data.h"
#include "../../Storage/StorageData/UInt16Data/UInt16Data.h"
#include "../../Storage/StorageData/UInt32Data/UInt32Data.h"
#include "../../Storage/StorageData/BooleanData/BooleanData.h"
#include "../../Storage/StorageData/StorageLocation.h"
#include "../../Storage/StorageConstant.h"
#include "../../Storage/Storage.h"
#include "../../Helper/Helper.h"


class SettingManager {
    public:
        virtual void init() = 0;
        virtual void restoreDefault() = 0;
};

#endif