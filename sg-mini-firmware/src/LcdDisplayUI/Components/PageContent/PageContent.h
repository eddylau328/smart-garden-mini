#ifndef PageContent_h
#define PageContent_h

#include "../../../Helper/Helper.h"
#include "../PageLayoutPosition/PageLayoutPosition.h"
#include <Arduino.h>
#include <DebugLog.h>

/**
 * @brief provides attributes and methods for storing and updating the content of the Page
 * 
 * (Noted: it is the only object accept by the LcdDisplayUI for rendering)
 */
class PageContent {

  public:
    /**
     * @brief Construct a new Page Content object
     * 
     * @param content - the constant character pointer of the content want to display, e.g. "Hello World"
     * @param length - the length of the content (Noted: null character is excluded)
     * @param pos - the PageLayoutPosition Object that contains the position of the content
     */
    PageContent(const char* content, int length, PageLayoutPosition pos);

    /**
     * @brief Construct a new Page Content object without pre-assigning the content, for case such as variable or condition rendering
     * 
     * @param length - the length of the content (Noted: null character is excluded)
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

    /**
     * @brief Get the Custom Character Index
     * 
     * @return int8_t - the index of the corresponding custom character
     */
    int8_t getCustomCharacterIndex();
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
     * @param startIndex - the index for accessing the character array, normally it start from 0, for case you want to use substring of the character array, it will be useful
     */
    void updateContent(char *data, int length, int startIndex=0);

    /**
     * @brief Update the content with constant character pointer data
     * 
     * @param data - constant character pointer contains the update strings you want to show
     * @param length - the length of the update string (Noted: if your new string length is shorter than the assigned string length, the left out will be automatically assigned a whitespace ' ')
     */
    void updateContent(const char *data, int length);

    /**
     * @brief Set the Custom Character index
     * 
     * @param customCharacterIndex 
     */
    void setCustomCharacterIndex(int8_t customCharacterIndex, bool isSet=true, int8_t customCharacterContentIndex=0);

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

    /**
     * @brief Get the Is Custom Character object
     * 
     * @param contentIndex the index of the custom character in the char array of the content
     * 
     * @return true - the page content character has set a custom character
     * @return false - the page content character has not set a custom character 
     */
    bool getIsCustomCharacter(int8_t contentIndex);

  private:
    char *content;
    static char buffer[20];
    uint8_t contentLength;
    PageLayoutPosition pos;
    PageLayoutPosition newPos;

    bool isUpdate = true;
    bool isSetCustomCharacter = false;
    int8_t customCharacterIndex;
    int8_t customCharacterContentIndex;
};

#endif