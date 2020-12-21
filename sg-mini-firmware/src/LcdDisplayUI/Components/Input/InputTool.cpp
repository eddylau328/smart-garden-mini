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