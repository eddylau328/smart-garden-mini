#ifndef LocalSettingManager_h
#define LocalSettingManager_h

#include <RTClib.h>
#include "../SettingManager.h"

class LocalSettingManager : public SettingManager {

    public:
        void init();
        DateTime getDeviceDateTime(); // No need to use variable to store
        void setDeviceDateTime(DateTime date);

        const char* getUserName();
        void setUserName(char *username);
        void setUserName(const char *username);

        bool getIsClockRunning();

    private:
        char username[USERNAME_LENGTH];
        RTC_DS1307 clock;
};

#endif