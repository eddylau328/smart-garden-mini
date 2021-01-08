#include "TemplatePage.h"

void TemplatePage::mountPage() {}

void TemplatePage::getContents(PageContent **contents, int *length) {
  *contents = this->contents;
  *length = contentSize;
}

void TemplatePage::updateContents() {}

void TemplatePage::interactiveUpdate(int counter, bool isPress) {}

void TemplatePage::dismountPage() {}