#ifndef SettingManager_h
#define SettingManager_h

#include "../../Storage/Storage.h"
#include "../../Storage/StorageConstant.h"
#include "../../Helper/Helper.h"


class SettingManager {
    public:
        virtual void init() = 0;
};

#endif