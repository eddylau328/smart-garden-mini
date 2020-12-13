#ifndef PageVerticalScroll_h
#define PageVerticalScroll_h

#include "../PageScroll.h"

class PageVerticalScroll : public PageScroll {

  public:
    void setCoverArea(PageLayoutRange rowRange);
    void resetScroll(PageContent *contents, int length);
    void updateScroll(PageContent *contents, int length, int counter);

  private:
    int8_t upScrollMax;
    int8_t downScrollMax;
    PageLayoutRange rowRange;
};

#endif