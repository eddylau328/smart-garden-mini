#ifndef PageVerticalScroll_h
#define PageVerticalScroll_h

#include "../PageScroll.h"

/**
 * @brief provides a vertical scroll ultility function for Page object to use
 * 
 */
class PageVerticalScroll : public PageScroll {

  public:
    /**
     * @brief Set the Cursor object
     * 
     * @param content - the PageContent object pointer that you will use to show the cursor
     * @param defaultRow - the row position for the cursor to show, e.g. row size is 2 then the row pos is [0, 1]
     */
    void setCursor(PageContent *content, int defaultRow );

    /**
     * @brief Set the Cover Area object
     * 
     * @param rowRange - the PageLayoutRange object that is used to indicate how many rows will be affected by the scroll effects
     */
    void setCoverArea(PageLayoutRange rowRange);

    void resetScroll(PageContent **contents, int length);
    void updateScroll(PageContent **contents, int length, int counter);

    /**
     * @brief Get the Current Arrow Row object
     * 
     * @param contents - the first PageContent object pointer in your PageContent array which you will show to the display 
     * @param length - the PageContent array length
     * @return int8_t - the row position that the cursor is currently at
     */
    int8_t getCurrentArrowRow(PageContent **contents, int length);

  private:
    int8_t upScrollMax;
    int8_t downScrollMax;
    PageLayoutRange rowRange;
    PageContent *cursor=NULL;
    int8_t cursorRow;
    int8_t cursorDefaultRow;
};

#endif