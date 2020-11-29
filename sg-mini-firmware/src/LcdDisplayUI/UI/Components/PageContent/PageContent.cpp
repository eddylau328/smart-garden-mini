#include "PageContent.h"

PageContent::PageContent(const char* content, int length, ContentType type, PageLayoutPosition pos) {
  this->content = new char[length+1];
  if (strcmp(content, "") != 0)
  {
      for (int i = 0 ; i < length + 1; i++)
          *(this->content+i) = *(content+i);
  }
  this->contentLength = length + 1;
  this->contentType = type;
  this->pos.set(pos);
  this->id = createId();
}

PageContent::~PageContent() {
    delete content;
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

PageContent::ContentType PageContent::getContentType(){
    return this->contentType;
}

void PageContent::updateContent(int data){
    if (contentType == ContentType::Variable)
    {
        convertNumToStr(data, content, contentLength-1);
        isUpdate = true;
    }
}

void PageContent::updateContent(float data, int decimalPoints){
    if (contentType == ContentType::Variable)
    {
        convertNumToStr(data, content, contentLength-1, decimalPoints);
        isUpdate = true;
    }
}

void PageContent::updateContent(char *data, int length){
    if (contentType == ContentType::Variable)
    {
        for (int i = 0; i < length; i++){
            if (i < contentLength-1)
                *(content+i) = *(data+i);
            else
            {
                *(content+i) = '\0';
                break;
            }
        }
        isUpdate = true;
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

uint8_t PageContent::createId() {
  static uint8_t id = 0;
  return id++;
}
