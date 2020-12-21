#include "InputAscii.h"

void InputAscii::set(const char* defaultValue, int8_t stringLength) {
  valueIndex = 0;
  inputValue = new char[stringLength];
  this->stringLength = stringLength;
  Helper::copyString(inputValue, defaultValue, stringLength);
  for (int i = 0 ; i < stringLength ; i++)
    if (!(Helper::intInRange((int) *(inputValue+i), 32, 126)))
      *(inputValue + i) = ' ';
  connectContent->updateContent(inputValue, stringLength);
}

bool InputAscii::interactiveUpdate(int counter, bool isPress) {
  if (isPress) {
    valueIndex++;
    if (valueIndex >= stringLength) {
      valueIndex = 0;
      return true;
    }
    return false;
  }

  if (!connectContent)
    return true;

  
  char value = *(inputValue + valueIndex) + counter;
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
  *(inputValue + valueIndex) = value;
  connectContent->updateContent(inputValue, stringLength);
  return false;
}