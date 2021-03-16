#include "InputCharacter.h"

InputCharacter::~InputCharacter() {
  destroy();
}

void InputCharacter::init(int8_t displayRange, int8_t bufferSize) {
  destroy();
  this->bufferSize = bufferSize;
  buffer = new char[bufferSize + 1];
  valueIndex = 0;
  showIndex = 0;
  this->displayRange = displayRange;
  for (int i = 0 ; i < bufferSize; i++)
    *(buffer + i) = ' ';
  *(buffer + bufferSize) = '\0';
  connectContent->updateContent(buffer, displayRange, showIndex); 
}

void InputCharacter::destroy() {
  if (buffer != NULL) {
    delete[] buffer;
    buffer = NULL;
  }
}

void InputCharacter::set(const char* defaultValue, int8_t stringLength) {
  // copy the default to the buffer
  Helper::copyString(buffer, defaultValue, stringLength);
  for (int i = 0 ; i < stringLength ; i++)
    if (!(Helper::intInRange((int) *(buffer+i), 32, 126)))
      *(buffer + i) = ' ';
  connectContent->updateContent(buffer, stringLength, showIndex);
}

void InputCharacter::blinkUpdate() {
  if (isBlink && connectContent && millis() - lastInputTrigger > 500) {
    if (isBlinking) {
      Helper::copyString(copyBuffer, connectContent->getContent(), displayRange);
        *(copyBuffer + valueIndex - showIndex) = '_';
      connectContent->updateContent(copyBuffer, displayRange);
    }
    else
      connectContent->updateContent(buffer, displayRange, showIndex);
    isBlinking = !isBlinking;
    lastInputTrigger = millis();
  }
}

bool InputCharacter::interactiveUpdate(int counter, bool isPress) {
  if (isPress) {
    valueIndex++;
    if (valueIndex < bufferSize) {
      showIndex = valueIndex - displayRange < 0 ? 0 : valueIndex - displayRange + 1;
      connectContent->updateContent(buffer, displayRange, showIndex);
    }
    else {
      valueIndex = 0;
      this->isBlink = false;
      this->isBlinking = false;
      return true;
    }
    return false;
  }

  if (!connectContent)
    return true;

  
  char value = *(buffer + valueIndex) + counter;
  if (isCircleLoop) {
    if (value < 32)
      value = 127 - (32 - value);
    else if (value > 126)
      value = 31 + (value - 126);
  }
  else {
    if (value < 32)
      value = 32;
    else if (value > 126)
      value = 126;
  }
  *(buffer + valueIndex) = value;
  connectContent->updateContent(buffer, displayRange, showIndex);
  lastInputTrigger = millis();
  return false;
}

void InputCharacter::getInputValue(char **ptr, int *length) {
  for (int i = bufferSize - 1; i > 0; i--)
    if (*(buffer + i) != ' ') {
      *(buffer + i + 1) = '\0';
      *length = i + 1;
      break;
    }
  *ptr = buffer;
}