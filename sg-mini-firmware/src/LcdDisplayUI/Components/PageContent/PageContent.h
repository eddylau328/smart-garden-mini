#ifndef PageContent_h
#define PageContent_h

#include "../../../Helper/Helper.h"
#include "../PageLayoutPosition/PageLayoutPosition.h"
#include <Arduino.h>
#include <DebugLog.h>

class PageContent {

  public:
    /**
     * @brief Construct a new Page Content object
     * 
     * @param content - the constant character pointer of the content want to display, e.g. "Hello World"
     * @param length - the length of the content
     * @param pos - the PageLayoutPosition Object that contains the position of the content
     */
    PageContent(const char* content, int length, PageLayoutPosition pos);

    /**
     * @brief Construct a new Page Content object without pre-assigning the content, for case such as variable or condition rendering
     * 
     * @param length - the length of the content
     * @param pos - the PageLayoutPosition Object that contains the position of the content 
     */
    PageContent(int length, PageLayoutPosition pos);

    /**
     * @brief Construct a new empty Page Content object (only use this for fulfilling the PageContent Array default assign situation)
     * 
     */
    PageContent();
    ~PageContent();

    // getter function  --------------------------------
    /**
     * @brief Get the Id object (Deprecated)
     * 
     * @return uint8_t - the id of the object
     */
    uint8_t getId();

    /**
     * @brief Get the Content Length object
     * 
     * @return int - the length of the content
     */
    int getContentLength();

    /**
     * @brief Get the Content object
     * 
     * @return char* - the character pointer of the content
     */
    char* getContent();

    /**
     * @brief Get the PageLayoutPosition object for the current rendering position
     * 
     * @return PageLayoutPosition - the PageLayoutPosition Object that contains the position of the content that are rendering
     */
    PageLayoutPosition getPos();

    /**
     * @brief Get the PageLayoutPosition object for the next rendering position
     * 
     * @return PageLayoutPosition - the PageLayoutPosition Object that contains the next position of the content that will be rendered
     */
    PageLayoutPosition getNewPos();
    // -------------------------------------------------

    /**
     * @brief Set the next position of the content will be rendered
     * 
     * @param pos - the PageLayoutPosition Object that contains the next position of the content that will be rendered
     */
    void updatePos(PageLayoutPosition pos);

    /**
     * @brief Update the content with integer data
     * 
     * @param data - integer type data
     * @param keptZero - whether displaying the zero if the assign integer data has a shorter length than the assigned content length
     */
    void updateContent(int data, bool keptZero=false);

    /**
     * @brief Update the content with floating point data
     * 
     * @param data - floating point type data
     * @param decimalPoints - the decimal points that you want to show (Noted: the content length needs to be allow for displaying the required decimal points including the dot character '.')
     */
    void updateContent(float data, int decimalPoints);

    /**
     * @brief Update the content with character pointer data
     * 
     * @param data - character pointer contains the update strings you want to show
     * @param length - the length of the update string (Noted: if your new string length is shorter than the assigned string length, the left out will be automatically assigned a whitespace ' ')
     */
    void updateContent(char *data, int length);

    /**
     * @brief Update the content with constant character pointer data
     * 
     * @param data - constant character pointer contains the update strings you want to show
     * @param length - the length of the update string (Noted: if your new string length is shorter than the assigned string length, the left out will be automatically assigned a whitespace ' ')
     */
    void updateContent(const char *data, int length);

    /**
     * @brief Set isUpdate to true to indicate the PageContent does not need to re-render again
     * 
     */
    void confirmUpdate();

    /**
     * @brief Get whether the PageContent has been updated the content or position 
     * 
     * @return true - it does require a re-render process
     * @return false - it does not require a re-render process
     */
    bool getIsUpdate();

  private:
    char *content;
    static char buffer[20];
    uint8_t contentLength;
    uint8_t id;
    PageLayoutPosition pos;
    PageLayoutPosition newPos;

    bool isUpdate = true;

    /**
     * @brief Create an id for every PageContent Object (Deprecated)
     * 
     * @return uint8_t - an unique unsigned 8-bit integer id
     */
    static uint8_t createId();

};

#endif