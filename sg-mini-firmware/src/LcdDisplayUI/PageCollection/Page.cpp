#include "Page.h"

void Page::getContents(PageContent ***contents, int *length, bool *isAllocateContents) {
  *contents = this->contents;
  *length = this->contentSize;
  *isAllocateContents = this->isAllocateContents;
  if (this->isAllocateContents)
    this->isAllocateContents = false;
}
void Page::updateContents() {}
void Page::interactiveUpdate(int counter, bool isPress) {
  if (isPress)
    nextPageCallback(defaultPageKey);
}
void Page::dismountPage() {
  if (contentSize > 0)
    delete [] contents;
  contentSize = 0;
}
void Page::setNextPageCallback(uint8_t defaultPageKey, void (*callback)(uint8_t)) {
  this->defaultPageKey = defaultPageKey;
  nextPageCallback = callback;
}
void Page::allocateStaticContents(PageContent *staticContents, int8_t contentSize, bool isAllocateContents) {
  this->contentSize = contentSize;
  contents = new PageContent*[contentSize];
  for (int i = 0 ; i < contentSize; i++)
    contents[i] = &staticContents[i];
  this->isAllocateContents = isAllocateContents;
}