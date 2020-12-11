#include "InputTool.h"

InputTool::InputTool() {}

InputTool::~InputTool() {
  delete inputValue;
}

void InputTool::setLinkage(PageContent *pageContent) {
  this->connectContent = pageContent; 
}

void InputTool::setCircleLoop(bool isCircleLoop) {
  this->isCircleLoop = isCircleLoop;
}


// void InputTool::setAscii(const char* defaultValue, int8_t stringLength) {
//   inputType = InputType::ascii;
//   inputValue = new char[stringLength];
//   this->stringLength = stringLength;
//   Helper::copyString(inputValue, defaultValue, stringLength);
// }

// void InputTool::handleAlphabetUpdate(int counter, bool isNext){

// }

// void InputTool::handleAsciiUpdate(int counter){

// }
