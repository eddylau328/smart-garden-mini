#include "InputTool.h"

InputTool::InputTool() {}

InputTool::~InputTool() {}

uint8_t InputTool::getId() {
  return this->connectContent->getId();
}

void InputTool::setLinkage(PageContent *pageContent) {
  this->connectContent = pageContent; 
}

void InputTool::setBool(bool defaultValue) {
  inputType = InputType::boolean;
  inputValue = new char[3];
  Helper::copyString(inputValue, defaultValue? "ON " : "OFF", 3);
  connectContent->updateContent(inputValue, 3);
}

void InputTool::setNumber(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool isCircleLoop=true) {
  inputType = InputType::number;
  inputValue = new char[4];
  Helper::assignStrValue(inputValue, ' ', 4);
  this->minNumber = minNumber;
  this->maxNumber = maxNumber;
  this->isCircleLoop = isCircleLoop;
  Helper::convertNumToStr((int) defaultValue, inputValue, 4);
  connectContent->updateContent(inputValue, 4);
}

void InputTool::setAlphabet(const char* defaultValue, int8_t stringLength) {
  inputType = InputType::alphabet;
  inputValue = new char[stringLength];
  this->stringLength = stringLength;
  Helper::copyString(inputValue, defaultValue, stringLength);
}

void InputTool::setAscii(const char* defaultValue, int8_t stringLength) {
  inputType = InputType::ascii;
  inputValue = new char[stringLength];
  this->stringLength = stringLength;
  Helper::copyString(inputValue, defaultValue, stringLength);
}

void InputTool::interactiveUpdate(int counter) {
  if (!connectContent && inputType != InputType::none)
    return;

  switch (inputType) {
    case InputType::boolean:
      handleBoolUpdate(counter);
      break;
    case InputType::number:
      handleNumberUpdate(counter);
      break;
    case InputType::alphabet:
      handleAlphabetUpdate(counter);
      break;
    case InputType::ascii:
      handleAsciiUpdate(counter);
      break;
    default:
      break;
  }
}

// private -----------------------------------------------------
void InputTool::handleBoolUpdate(int counter){
  if ((int)ceil(abs(counter)/2.0) % 2) {
    Helper::copyString(inputValue, Helper::compareString(inputValue, "ON ", 3) ? "OFF" : "ON ", 3);
    connectContent->updateContent(inputValue, 3);
  }
}

void InputTool::handleNumberUpdate(int counter){
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
}

void InputTool::handleAlphabetUpdate(int counter){

}

void InputTool::handleAsciiUpdate(int counter){

}
