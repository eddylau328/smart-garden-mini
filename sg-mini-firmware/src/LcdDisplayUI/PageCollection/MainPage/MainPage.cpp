#include "MainPage.h"

MainPage::MainPage() {
  inputTool.setLinkage(&(contents[1]));
  inputTool.setNumber(8, -10, 10, false);
}

MainPage::~MainPage() {

}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {}

void MainPage::interactiveUpdate(int counter, bool isPress) {
  inputTool.interactiveUpdate(counter);
};