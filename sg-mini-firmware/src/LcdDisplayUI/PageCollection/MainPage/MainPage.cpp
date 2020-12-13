#include "MainPage.h"

MainPage::MainPage() {
  scroll.init(16, 2);
  scroll.setCoverArea(PageLayoutRange(0, 25), PageLayoutRange(0, 1));
}

MainPage::~MainPage() {

}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {}

void MainPage::interactiveUpdate(int counter, bool isPress) {
  scroll.updateScroll(this->contents, 4, counter);
}