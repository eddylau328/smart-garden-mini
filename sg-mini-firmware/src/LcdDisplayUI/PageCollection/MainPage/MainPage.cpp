#include "MainPage.h"


MainPage::MainPage() {}
MainPage::~MainPage() {

}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {}