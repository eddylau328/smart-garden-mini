#ifndef DeviceSetting_h
#define DeviceSetting_h

#include <Arduino.h>
#include "DS1307.h"
#include "../Helper/Helper.h"
#include "../Storage/Storage.h"
#include "../Storage/StorageConstant.h"
class DeviceSetting {

  public:
    static void init ();
    static void getUserName(char **userName, int *length);
    static void setUserName(char *newUserName, int length);
    static void getDate(int *year, int *month, int *day, int *dayOfWeek);
    static void setDate(int year, int month, int day, int dayOfWeek);
    static void getTime(int *hour, int *minute, int *second);
    static void setTime(int hour, int minute, int second);
    static void mainLoop();

  private:
    static DS1307 clock;
    static char userName[UserNameLength];
    static unsigned long lastTimeRecord;
    static uint8_t time[3];
    static uint8_t date[4];
};

#endif