#include "InputNumber.h"

void InputNumber::set(int8_t defaultValue, int8_t minNumber, int8_t maxNumber) {
  inputValue = new char[4];
  Helper::assignStrValue(inputValue, ' ', 4);
  this->minNumber = minNumber;
  this->maxNumber = maxNumber;
  Helper::convertNumToStr((int) defaultValue, inputValue, 4);
  connectContent->updateContent(inputValue, 4);
}


bool InputNumber::interactiveUpdate(int counter, bool isPress){

  if (isPress)
    return true;
    
  if (!connectContent)
    return true;

  int8_t number;
  Helper::convertStrToNum(inputValue, number);
  if (isCircleLoop) {
    number += counter;
    if (number > maxNumber)
      number = (number - maxNumber) + minNumber;
    else if (number < minNumber)
      number = maxNumber - (minNumber - number);
  }
  else {
    if (Helper::numInRange(number, minNumber, maxNumber)) {
      if (Helper::numInRange(number+counter, minNumber, maxNumber)) {
        number += counter;
      }
      else {
        if (counter > 0)
          number = maxNumber;
        else 
          number = minNumber;
      }
    }
  }
  Helper::convertNumToStr(number, inputValue, 4);
  connectContent->updateContent(inputValue, 4);
  return false;
}
