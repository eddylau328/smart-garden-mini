#include "PageContent.h"

char PageContent::buffer[20];

PageContent::PageContent(const char* content, int length, PageLayoutPosition pos) {
    this->content = new char[length];
    for (int i = 0 ; i < length; i++)
        *(this->content+i) = *(content+i);
    this->contentLength = length;
    this->pos = pos;
    this->newPos = pos;
}

PageContent::PageContent(int length, PageLayoutPosition pos) {
    this->content = new char[length];
    Helper::assignStrValue(this->content, ' ', length);
    this->contentLength = length;
    this->pos = pos;
    this->newPos = pos;
}

PageContent::PageContent() {
    this->contentLength = 0;
    this->pos = PageLayoutPosition(0,0);
    this->newPos = pos;
}

PageContent::~PageContent() {
    delete[] content;
}

int PageContent::getContentLength(){
    return (int) this->contentLength;
}

char* PageContent::getContent(){
    return this->content;
}

PageLayoutPosition PageContent::getPos() {
    return this->pos;
}

PageLayoutPosition PageContent::getNewPos() {
    return this->newPos;
}

int8_t PageContent::getCustomCharacterIndex() {
    return customCharacterIndex;
}

void PageContent::updatePos(PageLayoutPosition pos) {
    this->newPos = pos;
    isUpdate = true;
}

void PageContent::updateContent(int data, bool keptZero){
    Helper::assignStrValue(buffer, ' ', contentLength);
    Helper::convertNumToStr(data, buffer, contentLength, keptZero);
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            Helper::copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
    setCustomCharacterIndex(0, 0, false);
}

void PageContent::updateContent(float data, int decimalPoints){
    Helper::assignStrValue(buffer, ' ', contentLength);
    Helper::convertNumToStr(data, buffer, contentLength, decimalPoints);
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            Helper::copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
    setCustomCharacterIndex(0, 0, false);
}

void PageContent::updateContent(char *data, int length, int startIndex){
    Helper::assignStrValue(buffer, ' ', contentLength);
    for (int i = 0; i < length; i++){
        if (i < contentLength)
            *(buffer+i) = *(data+startIndex+i);
    }
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            Helper::copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
    setCustomCharacterIndex(0, 0, false);
}

void PageContent::updateContent(const char *data, int length){
    Helper::assignStrValue(buffer, ' ', contentLength);
    for (int i = 0; i < length; i++){
        if (i < contentLength)
            *(buffer+i) = *(data+i);
    }
    for (int i = 0; i < contentLength; i++) {
        if (*(buffer+i) != *(content+i)) {
            Helper::copyString(content, buffer, contentLength);
            isUpdate = true;
            break;
        }
    }
    setCustomCharacterIndex(0, 0, false);
}

void PageContent::setCustomCharacterIndex(int8_t customCharacterIndex, int8_t customCharacterContentIndex, bool isSet){
    this->isSetCustomCharacter = isSet;
    if (isSet) {
        this->customCharacterIndex = customCharacterIndex;
        this->customCharacterContentIndex = customCharacterContentIndex;
        this->isUpdate = isSet;
    }
}

void PageContent::confirmUpdate() {
  this->isUpdate = false;
  this->pos = this->newPos;
}

bool PageContent::getIsUpdate() {
  return this->isUpdate;
}

bool PageContent::getIsCustomCharacter(int8_t contentIndex) {
    return this->isSetCustomCharacter && contentIndex == customCharacterContentIndex;
}