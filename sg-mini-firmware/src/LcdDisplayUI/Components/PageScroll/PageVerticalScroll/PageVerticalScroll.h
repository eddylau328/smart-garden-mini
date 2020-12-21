#ifndef PageVerticalScroll_h
#define PageVerticalScroll_h

#include "../PageScroll.h"

class PageVerticalScroll : public PageScroll {

  public:
    void setCursor(PageContent *content, int defaultRow );
    void setCoverArea(PageLayoutRange rowRange);
    void resetScroll(PageContent *contents, int length);
    void updateScroll(PageContent *contents, int length, int counter);
    int8_t getCurrentArrowRow(PageContent *contents, int length);

  private:
    int8_t upScrollMax;
    int8_t downScrollMax;
    PageLayoutRange rowRange;
    PageContent *cursor=NULL;
    int8_t cursorRow;
    int8_t cursorDefaultRow;
};

#endif