#include "Helper.h"

void Helper::handleWireBegin() {
  static bool isBegin = false;
  if (!isBegin) {
    Wire.begin();
    isBegin = true;
  }
}

uint8_t Helper::modifyBit(uint8_t target, uint8_t bitNo, uint8_t bitValue) {
  uint8_t mask = 1 << bitNo; 
	return (target & ~mask) | ((bitValue << bitNo) & mask); 
}