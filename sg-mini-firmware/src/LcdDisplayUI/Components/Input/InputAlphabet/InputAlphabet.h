#ifndef InputAlphabet_h
#define InputAlphabet_h

#include "../InputTool.h"

/**
 * @brief InputTool for inputting Alphabet only, [a - z], [A - Z], [' '] (Noted: white space is included for more flexible input)
 * 
 */
class InputAlphabet : public InputTool {

  public:
    ~InputAlphabet();

    /**
     * @brief Set the default string value of the input content
     * 
     * @param defaultValue - constant character pointer for the content you want to show 
     * @param stringLength - the exact length of the content (Noted: null character is excluded)
     */
    void set(const char* defaultValue, int8_t stringLength);
    bool interactiveUpdate(int counter, bool isPress);

    /**
    * @brief Get the Input Value
    * 
    * @return char* - the character pointer for the data
    */
    char* getInputValue();
    void blinkUpdate();

  private:
    int8_t valueIndex;
    char *inputValue;

    bool isUpperCase(char value);
    bool isLowerCase(char value);

};

#endif