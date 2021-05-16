#ifndef AccessPointSetting_h
#define AccessPointSetting_h

#include "../../../../Helper/Helper.h"
#include "../../../../Config/Config.h"

class AccessPointSetting {
    public:
        AccessPointSetting();
        AccessPointSetting(char *accessPointName, char *accessPointPassword);
        AccessPointSetting(const char *accessPointName, const char *accessPointPassword);

        char* getAccessPointName();
        char* getAccessPointPassword();
        void setAccessPointName(const char *accessPointName, size_t bufferSize);
        void setAccessPointName(char *accessPointName, size_t bufferSize);
        void setAccessPointPassword(const char *accessPointName, size_t bufferSize);
        void setAccessPointPassword(char *accessPointName, size_t bufferSize);
        AccessPointSetting& operator=(const AccessPointSetting &target);
    
    private:
        char accessPointName[ACCESS_POINT_NAME_BUFFER_SIZE];
        char accessPointPassword[ACCESS_POINT_PASSWORD_BUFFER_SIZE];
};

#endif
