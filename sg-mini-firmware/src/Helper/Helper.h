/*
  Helper - collections of static function for doing perform multiple tasks
*/

#ifndef Helper_h
#define Helper_h

#include <Arduino.h>

class Helper {

  public:

    static void getDecimalValue(float value, uint8_t &decimal);
    static void getDecimalValue(float value, uint16_t &decimal);
    static void getIntegerValue(float value, uint8_t &integer);
    static void getIntegerValue(float value, uint16_t &integer);
};

#endif