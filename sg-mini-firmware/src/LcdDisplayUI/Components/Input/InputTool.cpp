#include "InputTool.h"

char InputTool::copyBuffer[20];
millisDelay InputTool::inputTriggerDelay;

InputTool::InputTool() {}

InputTool::~InputTool() {}

void InputTool::blinkUpdate() {}

void InputTool::setLinkage(PageContent *pageContent) {
  this->connectContent = pageContent; 
}

void InputTool::setCircleLoop(bool isCircleLoop) {
  this->isCircleLoop = isCircleLoop;
}

void InputTool::startBlink() {
  this->isBlink = true;
  inputTriggerDelay.start(500);
}