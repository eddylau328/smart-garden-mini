#ifndef PageContent_h
#define PageContent_h

#include "../PageLayoutPosition/PageLayoutPosition.h"
#include <Arduino.h>

class PageContent {

  public:
    enum ContentType {
        Constant, Variable
    };

    PageContent(const char* content, int length, ContentType type, PageLayoutPosition pos);
    ~PageContent();

    // getter function  --------------------------------
    uint8_t getId();
    int getContentLength();
    char* getContent();
    PageLayoutPosition getPos();
    PageContent::ContentType getContentType();
    // -------------------------------------------------

    void updateContent(int data);
    void updateContent(float data, int decimalPoints);
    void updateContent(char *data, int length);

    void confirmUpdate();
    bool getIsUpdate();

  private:
    char *content;
    uint8_t contentLength;
    uint8_t id;
    PageLayoutPosition pos;
    ContentType contentType;

    bool isUpdate = true;

    static void convertNumToStr(int num, char result[], int strlen);
    static void convertNumToStr(float num, char result[], int strlen, int decimalPoints);
    static uint8_t createId();
};

#endif