#ifndef DeviceSetting_h
#define DeviceSetting_h

#include <Arduino.h>
#include "../Storage/Storage.h"

class DeviceSetting {

  public:
    static void init ();
    static void getUserName(char **userName, int *length);
    static void setUserName(char *newUserName, int length);

  private:
    static char userName[UserNameLength];
};

#endif