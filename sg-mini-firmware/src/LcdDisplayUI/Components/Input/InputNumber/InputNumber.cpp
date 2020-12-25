#include "InputNumber.h"

void InputNumber::set(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool keptZero) {
  inputNumber = defaultValue;
  this->minNumber = minNumber;
  this->maxNumber = maxNumber;
  connectContent->updateContent(inputNumber, keptZero);
  this->keptZero = keptZero;
}

void InputNumber::blinkUpdate() {
  if (isBlink && connectContent) {
    if (isBlinking)
      connectContent->updateContent(inputNumber, keptZero);
    else
      connectContent->updateContent("    ", 4);
    isBlinking = !isBlinking;
  }
}

bool InputNumber::interactiveUpdate(int counter, bool isPress){

  if (isPress) {
    this->isBlink = false;
    this->isBlinking = false;
    connectContent->updateContent(inputNumber, keptZero);
    return true;
  }
    
  if (!connectContent)
    return true;

  int8_t number = inputNumber;

  if (isCircleLoop) {
    number += counter;
    if (number > maxNumber)
      number = (number - maxNumber) + minNumber;
    else if (number < minNumber)
      number = maxNumber - (minNumber - number);
  }
  else {
    if (Helper::int8_tInRange(number, minNumber, maxNumber)) {
      if (Helper::int8_tInRange(number+counter, minNumber, maxNumber)) {
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
  inputNumber = number;
  connectContent->updateContent(inputNumber, keptZero);
  return false;
}
