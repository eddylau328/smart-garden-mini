#include "InputNumber.h"

void InputNumber::set(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool keptZero) {
  inputNumber = defaultValue;
  this->minNumber = minNumber;
  this->maxNumber = maxNumber;
  connectContent->updateContent(inputNumber, keptZero);
  this->keptZero = keptZero;
}

void InputNumber::blinkUpdate() {
  if (isBlink && connectContent && inputTriggerDelay.justFinished()) {
    if (isBlinking)
      connectContent->updateContent(inputNumber, keptZero);
    else
      connectContent->updateContent("    ", 4);
    isBlinking = !isBlinking;
    inputTriggerDelay.repeat();
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
    if (Helper::isInRange(number, minNumber, maxNumber)) {
      if (Helper::isInRange(number+counter, minNumber, maxNumber)) {
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
  inputTriggerDelay.repeat();
  return false;
}

int8_t InputNumber::getInputValue() {
  return inputNumber;
}