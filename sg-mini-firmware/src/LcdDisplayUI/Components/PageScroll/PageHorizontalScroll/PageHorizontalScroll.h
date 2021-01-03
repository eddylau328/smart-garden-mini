#ifndef PageHorizontalScroll_h
#define PageHorizontalScroll_h

#include "../PageScroll.h"
#include "../../PageLayoutPosition/PageLayoutPosition.h"

/**
 * @brief provides a horizontal scroll ultility function for Page object to use
 * 
 */
class PageHorizontalScroll : public PageScroll {

  public:

    /**
     * @brief Set the Cover Area object (Deprecated: assigning the whole page instead of part of the page)
     * 
     * @param colRange the PageLayoutRange object that is used to indicate how many cols will be affected by the scroll effects
     * @param rowRange the PageLayoutRange object that is used to indicate how many rows will be affected by the scroll effects
     */
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