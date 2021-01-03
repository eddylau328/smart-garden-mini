#ifndef Page_h
#define Page_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../../Config/Config.h"
#include "../Components/PageContent/PageContent.h"
#include "../Components/PageLayoutPosition/PageLayoutPosition.h"

/**
 * @brief provides the base structure for creating a Page
 * 
 */
class Page {
  public:

    /**
     * @brief This function will be called once when the page is assigned to display through PageControl object
     * 
     */
    virtual void mountPage();

    /**
     * @brief Get the Contents object for the LcdDisplayUI to render the Page
     * 
     * @param contents - PageContent Array that contains all the information you want to display
     * @param length - PageContent Array Length (Noted: it is important to provide exact array length)
     */
    virtual void getContents(PageContent **contents, int *length) = 0;

    /**
     * @brief This function will be called in a designed period of time as long as the page is assigned to display through PageControl Object
     * 
     */
    virtual void updateContents();

    /**
     * @brief This function will be called whenever there is an interrupt from the user as long as the page is assigned to display through PageControl Object
     * 
     * @param counter - Integer of the clockwise/anti-clockwise step count from the RotaryEncoder
     * @param isPress - Boolean of the press state from the RotaryEncoder, (true = Press down, false = Nothing happen) 
     */
    virtual void interactiveUpdate(int counter, bool isPress);

    /**
     * @brief This function will be called once when the another page is assigned to display through PageControl object
     * 
     */
    virtual void dismountPage();

    /**
     * @brief Set the Next Page Callback object
     * 
     * @param defaultPageKey - the default page index for assigning the page you want to display
     * @param callback - the callback function from the PageControl object that allows you to assign the page index
     */
    void setNextPageCallback(uint8_t defaultPageKey, void (*callback)(uint8_t));

  protected:
    uint8_t defaultPageKey;
    void (*nextPageCallback)(uint8_t);
  
};

#endif