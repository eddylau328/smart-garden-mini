#include "PageControl.h"

PageControl::PageControl() {
  
}

PageControl::~PageControl() {
  for (int i = 0; i < TotalPage; i++)
    delete *pages[i];
}