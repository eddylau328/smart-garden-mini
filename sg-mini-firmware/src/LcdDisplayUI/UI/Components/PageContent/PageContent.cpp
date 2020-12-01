#include "PageContent.h"

PageContent::PageContent(const char* content, int length, PageLayoutPosition pos) {
  this->content = new char[length+1];
  this->buffer = new char[length+1];
  if (strcmp(content, "") != 0)
  {
      for (int i = 0 ; i < length + 1; i++)
          *(this->content+i) = *(content+i);
  }
  this->contentLength = length + 1;
  this->pos.set(pos);
  this->id = createId();
}

PageContent::~PageContent() {
    delete content;
    delete buffer;
}

uint8_t PageContent::getId(){
    return this->id;
}

int PageContent::getContentLength(){
    return (int) this->contentLength;
}

char* PageContent::getContent(){
    return this->content;
}

PageLayoutPosition PageContent::getPos(){
    return this->pos;
}

void PageContent::updateContent(int data){
    convertNumToStr(data, buffer, contentLength-1);
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
}

void PageContent::updateContent(float data, int decimalPoints){
    convertNumToStr(data, buffer, contentLength-1, decimalPoints);
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
}

void PageContent::updateContent(char *data, int length){
    for (int i = 0; i < length; i++){
        if (i < contentLength-1)
            *(buffer+i) = *(data+i);
        else
        {
            *(buffer+i) = '\0';
            break;
        }
    }
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
}

void PageContent::confirmUpdate() {
  this->isUpdate = false;
}

bool PageContent::getIsUpdate() {
  return this->isUpdate;
}

// Private ----------------------------------------------------------------------------
void PageContent::convertNumToStr(int num, char result[], int strlen){
    dtostrf(num, strlen, 0, result);
}

void PageContent::convertNumToStr(float num, char result[], int strlen, int decimalPoints){
    dtostrf(num, strlen, decimalPoints, result); // Leave room for too large numbers!
}

void PageContent::copyString(char *target, char *copy, int length) {
    for (int i = 0; i < length; i++)
        *(target + i) = *(copy + i);
}

uint8_t PageContent::createId() {
  static uint8_t id = 0;
  return id++;
}
