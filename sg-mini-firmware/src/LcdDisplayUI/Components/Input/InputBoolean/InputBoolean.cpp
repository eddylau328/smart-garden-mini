#include "InputBoolean.h"

void InputBoolean::set(bool defaultValue) {
  inputBool = defaultValue;
  connectContent->updateContent(inputBool? "ON " : "OFF", 3);
}

bool InputBoolean::interactiveUpdate(int counter, bool isPress) {
  if (isPress)
    return true;

  if (!connectContent)
    return true;

  if ((int)ceil(abs(counter)/2.0) % 2) {
    inputBool = !inputBool;
    connectContent->updateContent(inputBool? "ON " : "OFF", 3);
  }

  return false;
}

bool InputBoolean::getInputValue() {
  return inputBool;
}