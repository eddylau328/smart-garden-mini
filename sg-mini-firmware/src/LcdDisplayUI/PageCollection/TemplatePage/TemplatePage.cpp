#include "TemplatePage.h"

void TemplatePage::mountPage() {
  Page::allocateStaticContents(staticContents, 2);
}

void TemplatePage::updateContents() {}

void TemplatePage::interactiveUpdate(int counter, bool isPress) {}

void TemplatePage::dismountPage() {
  Page::dismountPage(); // for dellocate contents memory, remove this line if dellocate in derived class
}