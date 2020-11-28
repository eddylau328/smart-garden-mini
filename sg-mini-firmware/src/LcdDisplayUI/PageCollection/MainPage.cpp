#include "MainPage.h"

MainPage::MainPage() {

}

MainPage::~MainPage() {

}

void MainPage::getContents(PageContent *contents, uint8_t *length){
  contents = this->contents;
  *length = 2;
}