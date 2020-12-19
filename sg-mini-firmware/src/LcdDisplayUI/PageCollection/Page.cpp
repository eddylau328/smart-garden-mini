#include "Page.h"

void Page::mountPage() {}
void Page::updateContents() {}
void Page::interactiveUpdate(int counter, bool isPress) {
  if (isPress)
    nextPageCallback(defaultPageKey);
}
void Page::dismountPage() {}
void Page::setNextPageCallback(uint8_t defaultPageKey, void (*callback)(uint8_t)) {
  this->defaultPageKey = defaultPageKey;
  nextPageCallback = callback;
}