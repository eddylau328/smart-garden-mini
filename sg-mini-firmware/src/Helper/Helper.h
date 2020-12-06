#ifndef Helper_h
#define Helper_h

#include "Wire.h"

class Helper {
  public:
    static void handleWireBegin();
    static uint8_t modifyBit(uint8_t target, uint8_t bitNo, uint8_t bitValue);
};

#endif