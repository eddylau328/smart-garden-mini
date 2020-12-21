#include "MainPage.h"


MainPage::MainPage() {
  char *userName;
  int length;
  DeviceSetting::getUserName(&userName, &length);
  contents[1] = PageContent(length, PageLayoutPosition(0, 1));
}

MainPage::~MainPage() {}

void MainPage::mountPage() {
  char *userName;
  int length;
  DeviceSetting::getUserName(&userName, &length);
  contents[1].updateContent(userName, length);
}

void MainPage::getContents(PageContent **contents, int *length){
  *contents = this->contents;
  *length = *(&(this->contents) + 1) - this->contents;
}

void MainPage::updateContents() {}