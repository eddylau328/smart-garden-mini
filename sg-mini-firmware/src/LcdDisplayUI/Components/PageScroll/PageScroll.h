#ifndef PageScroll_h
#define PageScroll_h

#include <Arduino.h>
#include "../../../Helper/Helper.h"
#include "../PageContent/PageContent.h"
#include "../PageLayoutPosition/PageLayoutPosition.h"
#include "../PageLayoutRange/PageLayoutRange.h"

#define PageScrollMaxSize 10

class PageScroll {

  public:
    void init(int8_t screenWidth, int8_t screenHeight);
    virtual void resetScroll(PageContent *contents, int length) = 0;
    virtual void updateScroll(PageContent *contents, int length, int counter) = 0;

  protected:
    int8_t screenWidth = 0;
    int8_t screenHeight = 0;
    int8_t currentOrigin = 0;

};

#endif