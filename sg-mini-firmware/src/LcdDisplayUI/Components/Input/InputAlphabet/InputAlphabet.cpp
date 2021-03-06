#include "InputAlphabet.h"

InputAlphabet::~InputAlphabet() {
  delete inputValue;
}

void InputAlphabet::blinkUpdate() {
  if (isBlink && connectContent && inputTriggerDelay.justFinished()) {
    if (isBlinking) {
      Helper::copyString(copyBuffer, connectContent->getContent(), stringLength);
      *(copyBuffer + valueIndex) = '_';
      connectContent->updateContent(copyBuffer, stringLength);
    }
    else
      connectContent->updateContent(inputValue, stringLength);
    isBlinking = !isBlinking;
    inputTriggerDelay.repeat();
  }
}

void InputAlphabet::set(const char* defaultValue, int8_t stringLength) {
  valueIndex = 0;
  inputValue = new char[stringLength];
  this->stringLength = stringLength;
  Helper::copyString(inputValue, defaultValue, stringLength);
  for (int i = 0 ; i < stringLength ; i++)
    if ( !(Helper::isInRange((int) *(inputValue+i), 65, 90)) && !(Helper::isInRange((int) *(inputValue+i), 97, 122)) )
      *(inputValue + i) = ' ';
  connectContent->updateContent(inputValue, stringLength);
}

bool InputAlphabet::interactiveUpdate(int counter, bool isPress) {
  if (isPress) {
    valueIndex++;
    connectContent->updateContent(inputValue, stringLength);
    if (valueIndex >= stringLength) {
      valueIndex = 0;
      this->isBlink = false;
      this->isBlinking = false;
      return true;
    }
    return false;
  }

  if (!connectContent)
    return true;

  char temp = *(inputValue + valueIndex) == ' ' ? 123 : *(inputValue + valueIndex);
  char value = temp + counter;
  if (isCircleLoop) {
    if (isUpperCase(value)) {
      if (isLowerCase(temp))  // if before is lower case, which means it cross 91 - 96
        value -= 7;
    }
    else if (isLowerCase(value)) {
      if (isUpperCase(temp))
        value += 7;
    }
    else if (Helper::isInRange((int)value, 91, 96)) {
      if (counter > 0)
        value += 7;
      else
        value -= 7;
    }
    else if (value < 65)
      value = 124 - (65 - value);   // 123 => space, define space as 123
    else if (value > 123) 
      value = 65 + (value - 124);
  }
  else {
    if (isUpperCase(value)) {
      if (isLowerCase(*(inputValue + valueIndex)))  // if before is lower case, which means it cross 91 - 96
        value -= 7;
    }
    else if (isLowerCase(value)) {
      if (isUpperCase(*(inputValue + valueIndex)))
        value += 7;
    }
    else if (Helper::isInRange((int)value, 91, 96)) {
      if (counter > 0)
        value += 7;
      else
        value -= 7;
    }
    else if (value < 65)
      value = 65;
    else
      value = 123;
  }
  // when value == 123 it is space
  value = value == 123 ? ' ' : value;
  *(inputValue + valueIndex) = value;
  connectContent->updateContent(inputValue, stringLength);
  inputTriggerDelay.repeat();
  return false;
}

bool InputAlphabet::isUpperCase(char value){
  return Helper::isInRange((int)value, 65, 90);
}

bool InputAlphabet::isLowerCase(char value){
  return Helper::isInRange((int)value, 97, 122);
}

char* InputAlphabet::getInputValue() {
  return inputValue;
}