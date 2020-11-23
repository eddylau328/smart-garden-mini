#include "Helper.h"

void Helper::handleWireBegin() {
  static bool isBegin = false;
  if (!isBegin) {
    Wire.begin();
    isBegin = true;
  }
}