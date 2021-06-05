#ifndef SetupSettingManager_h
#define SetupSettingManager_h

#include "../SettingManager.h"


class SetupSettingManager : public SettingManager {

    public:
        void init();
        void restoreDefault();

        bool getIsInitialSetup();
        void resetSystem();

        bool getIsBeginSystemReset();
        void finishSystemReset();
    
    private:
        void retrieveIsInitialSetup();
        void storeIsInitialSetup();

        void retrieveIsBeginSystemReset();
        void storeIsBeginSystemReset();

        bool isInitialSetup;
        bool isBeginSystemReset;

};

#endif