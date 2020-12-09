#ifndef Helper_h
#define Helper_h

#include "Wire.h"
#include <Arduino.h>

class Helper {
  public:
    static void handleWireBegin();
    static uint8_t modifyBit(uint8_t target, uint8_t bitNo, uint8_t bitValue);

    static void assignStrValue(char *target, char value, int strlen);
    static void convertNumToStr(int num, char result[], int strlen);
    static void convertNumToStr(float num, char result[], int strlen, int decimalPoints);
    static void clearString(char* target, int length);
    static void copyString(char *target, char *copy, int length);
    static void copyString(char *target, const char *copy, int length);
    static bool compareString(char *target, char *compare, int targetLength);
    static bool compareString(char *target, const char *compare, int targetLength);
    static void convertStrToNum(char *target, int8_t &number);
    static void convertStrToNum(char *target, int &number);
    static void convertStrToNum(char *target, float &number);
    static bool numInRange(int number, int min, int max);
};

#endif