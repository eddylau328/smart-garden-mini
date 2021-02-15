#ifndef DeviceSetting_h
#define DeviceSetting_h

#include <Arduino.h>
#include "DS1307.h"
#include "../Helper/Helper.h"
#include "../Storage/Storage.h"
#include "../Storage/StorageConstant.h"

/**
 * @brief provides sets of functions for accessing the settings stored in the board or temporary stored in the device
 * this class serves as a cache storage for all the settings variable that will be accessed by different modules
 * 
 */
class DeviceSetting {

  public:
    /**
     * @brief initializes the cache storage by retrieving data from Storage Class or Hardware device
     * 
     */
    static void init ();

    /**
     * @brief get the user name 
     * 
     * @param userName - the character pointer reference for temporary storing the string 
     * @param length - the length of the character pointer
     */
    static void getUserName(char **userName, int *length);

    /**
     * @brief set the user name 
     * 
     * @param newUserName - the character pointer for temporary storing the string 
     * @param length - the length of the character pointer
     */
    static void setUserName(char *newUserName, int length);

    /**
     * @brief get the date
     * 
     * @param year - the integer reference for storing the year, [2000, 2100]
     * @param month - the integer reference for storing the month, [1 - 12]
     * @param day - the integer reference for storing the day, [depends on year & month]
     * @param dayOfWeek - the integer reference for storing the dayOfWeek, [Monday = 1, Sunday = 7]
     */
    static void getDate(int *year, int *month, int *day, int *dayOfWeek);

    /**
     * @brief set the date 
     * 
     * @param year - the integer of year for updating the clock device, [2000, 2100]
     * @param month - the integer of month for updating the clock device, [1 - 12]
     * @param day - the integer of day for updating the clock device, [depends on year & month]
     * @param dayOfWeek - the integer of dayOfWeek for updating the clock device, [Monday = 1, Sunday = 7]
     */
    static void setDate(int year, int month, int day, int dayOfWeek);

    /**
     * @brief get the time
     * 
     * @param hour - the integer reference for storing the hour, [0, 23]
     * @param minute - the integer reference for storing the minute, [0, 59]
     * @param second - the integer reference for storing the second, [0, 59]
     */
    static void getTime(int *hour, int *minute, int *second);

    /**
     * @brief set the time
     * 
     * @param hour - the integer of hour for updating the clock device, [0 23]
     * @param minute - the integer of minute for updating the clock device, [0, 59]
     * @param second - the integer of second for updating the clock device, [0, 59]
     */
    static void setTime(int hour, int minute, int second);

    /**
     * @brief Set the Wifi Mode 
     * 
     * @param isWifiMode - true if user want to use wifi, vice versa
     */
    static void setWifiMode(bool isWifiMode);

    /**
     * @brief Get whether the user is chose to use Wifi 
     * 
     * @return true - use wifi 
     * @return false - not use wifi 
     */
    static bool getWifiMode();

    /**
     * @brief performs functions that need to call in a period of time, e.g. getting the time 
     * 
     */
    static void mainLoop();

  private:
    static DS1307 clock;
    static char userName[UserNameLength];
    static unsigned long lastTimeRecord;
    static uint8_t time[3];
    static uint8_t date[4];
    static bool wifiMode;
};

#endif