#include "MainPage.h"

MainPage::MainPage() {
  input.setLinkage(&(contents[1]));
  input.set("abc", 3);
}

MainPage::~MainPage() {

}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {}

void MainPage::interactiveUpdate(int counter, bool isPress) {
  input.interactiveUpdate(counter, isPress);
};