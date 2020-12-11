#include "InputBoolean.h"

void InputBoolean::set(bool defaultValue) {
  inputValue = new char[3];
  Helper::copyString(inputValue, defaultValue? "ON " : "OFF", 3);
  connectContent->updateContent(inputValue, 3);
}

void InputBoolean::interactiveUpdate(int counter, bool isPress) {
  if (!connectContent)
    return;

  if ((int)ceil(abs(counter)/2.0) % 2) {
    Helper::copyString(inputValue, Helper::compareString(inputValue, "ON ", 3) ? "OFF" : "ON ", 3);
    connectContent->updateContent(inputValue, 3);
  }
}