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

void Helper::convertNumToStr(int num, char result[], int strlen){
  itoa(num, result, 10);
  for (int i = 0; i < strlen; i++) {
    if (*(result+i) == 0 || *(result+i) == 254)
      *(result+i) = ' ';
  }
}

void Helper::convertNumToStr(float num, char result[], int strlen, int decimalPoints){
  dtostrf(num, strlen, decimalPoints, result); // Leave room for too large numbers!
}

void Helper::clearString(char *target, int length) {
  for (int i = 0; i < length; i++)
    *(target + i) = '\0';
}

void Helper::copyString(char *target, char *copy, int length) {
    for (int i = 0; i < length; i++)
        *(target + i) = *(copy + i);
}

void Helper::copyString(char *target, const char *copy, int length) {
    for (int i = 0; i < length; i++)
        *(target + i) = *(copy + i);
}

bool Helper::compareString(char *target, char *compare, int targetLength) {
  for (int i = 0; i < targetLength; i++)
    if (*(target + i) != *(compare + i))
      return false;
  return true;
}

bool Helper::compareString(char *target, const char *compare, int targetLength) {
  for (int i = 0; i < targetLength; i++)
    if (*(target + i) != *(compare + i))
      return false;
  return true;
}

void Helper::convertStrToNum(char *target, int8_t &number) {
  number = atoi(target);
}

void Helper::convertStrToNum(char *target, int &number) {
  number = atoi(target);
}

void Helper::convertStrToNum(char *target, float &number) {
  number = atof(target);
}

bool Helper::int8_tInRange(int8_t target, int8_t min, int8_t max) {
  return (target >= min && target <= max);
}

bool Helper::intInRange(int target, int min, int max) {
    return (target >= min && target <= max);
}

void Helper::assignStrValue(char *target, char value, int strlen) {
  for (int i = 0; i < strlen; i++)
    *(target+i) = value;
}

bool Helper::isValidDate(int year, int month, int day) {
    // If year, month and day  
    // are not in given range 
    if (!Helper::intInRange(year, MIN_VALID_YR, MAX_VALID_YR)) 
      return false; 
    if (!Helper::intInRange(month, 1, 12)) 
      return false; 
    if (!Helper::intInRange(day, 1, 31)) 
      return false; 
  
    // Handle February month  
    // with leap year 
    if (month == 2) { 
      if (isLeapYear(year)) 
        return (day <= 29); 
      else
        return (day <= 28); 
    } 
  
    // Months of April, June,  
    // Sept and Nov must have  
    // number of days less than 
    // or equal to 30. 
    if (month == 4 || month == 6 || month == 9 || month == 11) 
        return (day <= 30); 
  
    return true; 
} 

bool Helper::isLeapYear(int year) { 
  // Return true if year  
  // is a multiple pf 4 and 
  // not multiple of 100. 
  // OR year is multiple of 400. 
  return (((year % 4 == 0) &&  
          (year % 100 != 0)) || 
          (year % 400 == 0)); 
} 