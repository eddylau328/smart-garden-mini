/*
  Helper - collections of static function for doing perform multiple tasks
*/

#include "Helper.h"

void Helper::getDecimalValue(float value, uint8_t &decimal) {
  // uint8_t can show 2 digits
  decimal = (uint8_t) round( ( value - floor(value) ) * 100 );
}

void Helper::getDecimalValue(float value, uint16_t &decimal) {
  // uint16_t can show 4 digits
  decimal = (uint8_t) round( ( value - floor(value) ) * 10000 );
}

void Helper::getIntegerValue(float value, uint8_t &integer) {
  // uint8_t can show 2 digits, max = 255
  integer = (uint8_t) floor(value);
}

void Helper::getIntegerValue(float value, uint16_t &integer) {
  // uint16_t can show 4 digits, max = 65535
  integer = (uint8_t) floor(value);
}

