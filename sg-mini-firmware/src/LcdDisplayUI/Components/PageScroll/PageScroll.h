#ifndef PageScroll_h
#define PageScroll_h

#include <Arduino.h>
#include "../../../Helper/Helper.h"
#include "../PageContent/PageContent.h"
#include "../PageLayoutPosition/PageLayoutPosition.h"
#include "../PageLayoutRange/PageLayoutRange.h"

#define PageScrollMaxSize 10

/**
 * @brief provides the attributes and methods of a scroll ultility component
 * 
 */
class PageScroll {

  public:

    /**
     * @brief Set the Lcd Screen Width and Height
     * 
     * @param screenWidth - the number of character the LCD can show in one row
     * @param screenHeight - the number of character the LCD can show in one column
     */
    void init(int8_t screenWidth, int8_t screenHeight);

    /**
     * @brief Reset the position of all the PageContent objects in your PageContent Array according to your tracking origin, and reset the tracking origin 
     * 
     * @param contents - the first PageContent object pointer in your PageContent array which you will show to the display 
     * @param length - the PageContent array length
     */
    virtual void resetScroll(PageContent *contents, int length) = 0;

    /**
     * @brief Update the position of all the PageContent objects in your PageContent Array and update the tracking origin according to the rotate step count
     * 
     * @param contents - the first PageContent object pointer in your PageContent array which you will show to the display 
     * @param length - the PageContent array length
     * @param counter - the clockwise/anti-clockwise step count 
     */
    virtual void updateScroll(PageContent *contents, int length, int counter) = 0;

  protected:
    int8_t screenWidth = 0;
    int8_t screenHeight = 0;
    int8_t currentOrigin = 0;

};

#endif