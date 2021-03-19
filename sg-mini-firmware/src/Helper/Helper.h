#ifndef Helper_h
#define Helper_h

#include "Wire.h"
#include <Arduino.h>

#define MAX_VALID_YR 2100 
#define MIN_VALID_YR 2000 

/**
 * @brief provides different basic functions that are useful for different classes 
 * 
 */
class Helper {
  public:
    /**
     * @brief provides a centeralized function call of the Wire.begin()
     * as different Libraries object may need to call use the built-in library <Wire>, this function prevents multiple begin() call from the Wire Class
     */
    static void handleWireBegin();

    /**
     * @brief modify one bit inside an unsigned 8-bit variable 
     * 
     * @param target - the unsigned 8-bit variable you want to modify
     * @param bitNo - the bit number you want to modify, [0, 7]
     * @param bitValue - the bit value you want to modify, [0, 1]
     * @return uint8_t - the modified unsigned 8-bit variable
     */
    static uint8_t modifyBit(uint8_t target, uint8_t bitNo, uint8_t bitValue);

    /**
     * @brief assigns the character pointer with the same value
     * 
     * @param target - the character pointer that you used to store the string
     * @param value - the value you want to assign for all the character inside the string
     * @param strlen - the string length excluding the null character
     */
    static void assignStrValue(char *target, char value, int strlen);

    /**
     * @brief convert the integer number to string
     * 
     * @param num - integer number you want to convert
     * @param result - the character array that you used to store the number
     * @param strlen - the string length excluding the null character
     * @param keptZero - whether displaying the zero if the assign integer data has a shorter length than the assigned content length 
     */
    static void convertNumToStr(int num, char result[], int strlen, bool keptZero=false);

    /**
     * @brief convert the floating point number to string
     * 
     * @param num - floating point number you want to convert
     * @param result - the character array that you used to store the number
     * @param strlen - the string length excluding the null character
     * @param decimalPoints - the number of digits you want to correct to
     */
    static void convertNumToStr(float num, char result[], int strlen, int decimalPoints);

    /**
     * @brief assigns all the character inside an character array to null 
     * 
     * @param target - the character array that you want to assign
     * @param length - the length of teh character array 
     */
    static void clearString(char* target, int length);

    /**
     * @brief copy the character array (Noted: this function copies the character value-by-value)
     * 
     * @param target - the character array you store the result
     * @param copy - the character array you want to copy
     * @param length - the length of your target array
     */
    static void copyString(char *target, char *copy, int length);

    /**
     * @brief copy the const character array (Noted: this function copies the character value-by-value)
     * 
     * @param target  - the character array you store the result
     * @param copy - the constant character array you want to copy
     * @param length - the length of your target array
     */
    static void copyString(char *target, const char *copy, int length);

    /**
     * @brief copy the byte character array
     * 
     * @param target - the character array you store the result
     * @param copy - the byte array you want to copy
     * @param length - the length of your target array
     */
    static void copyString(char *target, byte *copy, int length);

    /**
     * @brief compare the character array value by value
     * 
     * @param target - the character array you want to test
     * @param compare - the character array you want to compare
     * @param targetLength - the length of the target array
     * @return true - the target array is same as the compare array for the given length the target has 
     * @return false - the target array is not the same as the compare array for the given length the target has 
     */
    static bool compareString(char *target, char *compare, int targetLength);

    /**
     * @brief compare the character array value by value
     * 
     * @param target - the character array you want to test
     * @param compare - the constant character array you want to compare
     * @param targetLength - the length of the target array
     * @return true - the target array is same as the constant compare array for the given length the target has 
     * @return false - the target array is not the same as the constant compare array for the given length the target has 
     */
    static bool compareString(char *target, const char *compare, int targetLength);

    /**
     * @brief convert the character array to 8-bit integer
     * 
     * @param target - the target character array that stores the number
     * @param number - the 8-bit integer variable you will store
     */
    static void convertStrToNum(char *target, int8_t &number);

    /**
     * @brief convert the character array to integer
     * 
     * @param target - the target character array that stores the number
     * @param number - the integer variable you will store
     */
    static void convertStrToNum(char *target, int &number);

    /**
     * @brief convert the character array to floating point
     * 
     * @param target - the target character array that stores the number
     * @param number - the floating point variable you will store
     */
    static void convertStrToNum(char *target, float &number);

    /**
     * @brief check whether the 8-bit integer is within the range
     * 
     * @param target - the 8-bit integer variable you want to check
     * @param min - the minimum of the target can have
     * @param max - the maximum of the target can have
     * @return true - the target is within the range
     * @return false - the target is out of range
     */
    static bool int8_tInRange(int8_t target, int8_t min, int8_t max);

    /**
     * @brief check whether the integer is within the range
     * 
     * @param number - the integer variable you want to check
     * @param min - the minimum of the target can have
     * @param max - the maximum of the target can have
     * @return true - the target is within the range
     * @return false - the target is out of range
     */
    static bool intInRange(int number, int min, int max);

    /**
     * @brief check whether the date is valid
     * 
     * @param year - the year of the date you want to validate
     * @param month - the month of the date you want to validate
     * @param day - the day of the date you want to validate
     * @return true - the date is valid
     * @return false - the date is invalid
     */
    static bool isValidDate(int year, int month, int day);

    /**
     * @brief check whether the year is a leap year or not
     * 
     * @param year - the year you want to check
     * @return true - the year is a leap year
     * @return false - the year is not a leap year
     */
    static bool isLeapYear(int year);

};

#endif