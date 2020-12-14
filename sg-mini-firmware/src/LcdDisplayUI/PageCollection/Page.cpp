#include "Page.h"

void Page::mountPage() {}
void Page::updateContents() {}
void Page::interactiveUpdate(int counter, bool isPress) {
  if (isPress)
    nextPageCallback(pageKey);
}
void Page::dismountPage() {}
void Page::setNextPageCallback(uint8_t key, void (*callback)(uint8_t)) {
  pageKey = key;
  nextPageCallback = callback;
}