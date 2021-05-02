#ifndef InputAscii_h
#define InputAscii_h

#include "../InputTool.h"

/**
 * @brief InputTool for inputting ASCII character
 * 
 */
class InputAscii : public InputTool {

  public:
    ~InputAscii();

    /**
     * @brief Initiate the buffer for storing the character
     * 
     */
    void init();

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
    char *inputBuffer;
    
};

#endif