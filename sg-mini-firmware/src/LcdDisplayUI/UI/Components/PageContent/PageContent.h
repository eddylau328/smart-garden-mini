#ifndef PageContent_h
#define PageContent_h

#include "../PageLayoutPosition/PageLayoutPosition.h"
#include <Arduino.h>
#include <DebugLog.h>

class PageContent {

  public:
    PageContent(const char* content, int length, PageLayoutPosition pos);
    ~PageContent();

    // getter function  --------------------------------
    uint8_t getId();
    int getContentLength();
    char* getContent();
    PageLayoutPosition getPos();
    // -------------------------------------------------

    void updateContent(int data);
    void updateContent(float data, int decimalPoints);
    void updateContent(char *data, int length);

    void confirmUpdate();
    bool getIsUpdate();

  private:
    char *content;
    char *buffer;
    uint8_t contentLength;
    uint8_t id;
    PageLayoutPosition pos;

    bool isUpdate = true;

    static void convertNumToStr(int num, char result[], int strlen);
    static void convertNumToStr(float num, char result[], int strlen, int decimalPoints);
    static uint8_t createId();
    static void copyString(char *target, char *copy, int length);
};

#endif