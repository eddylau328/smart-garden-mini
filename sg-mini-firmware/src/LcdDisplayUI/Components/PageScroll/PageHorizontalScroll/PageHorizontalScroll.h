#ifndef PageHorizontalScroll_h
#define PageHorizontalScroll_h

#include "../PageScroll.h"
#include "../../PageLayoutPosition/PageLayoutPosition.h"

class PageHorizontalScroll : public PageScroll {

  public:
    void setCoverArea(PageLayoutRange colRange, PageLayoutRange rowRange);
    void resetScroll(PageContent *contents, int length);
    void updateScroll(PageContent *contents, int length, int counter);

  private:
    int8_t leftScrollMax;
    int8_t rightScrollMax;
    PageLayoutRange colRange;
    PageLayoutRange rowRange;
};

#endif