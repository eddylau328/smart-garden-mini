#ifndef LocalSettingManager_h
#define LocalSettingManager_h

#include <RTClib.h>
#include "../SettingManager.h"

class LocalSettingManager : public SettingManager {

    public:
        void init();
        void restoreDefault();        

        DateTime getDeviceDateTime(); // No need to use variable to store
        void setDeviceDateTime(DateTime date);

        bool getIsUsernameSet();

        const char* getUsername();
        void setUsername(char *username);
        void setUsername(const char *username);

        bool getIsClockRunning();

    private:
        bool isUsernameSet;
        char username[USERNAME_LENGTH];
        RTC_DS1307 clock;

        // methods
        void storeUsername();
        void retrieveUsername();

        void storeIsUsernameSet();
        void retrieveIsUsernameSet();
};

#endif