#include "PageControl.h"

PageControl::PageControl() {
  pages[PageControl::MainPageKey] = new MainPage();

}

PageControl::~PageControl() {
  for (int i = 0; i < TotalPage; i++) {
    delete pages[i];
  }
}