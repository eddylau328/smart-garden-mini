#ifndef InputCharacter_h
#define InputCharacter_h

#define INPUT_BUFFER_SIZE 25

#include "../InputTool.h"
#include <Arduino.h>

/**
 * @brief InputTool for inputting ASCII character
 * 
 */
class InputCharacter : public InputTool {

  public:
    ~InputCharacter();

    /**
     * @brief Initiate the buffer for storing the characters
     * 
     * @param displayRange - the length for showing the input content in the screen
     */
    void init(int8_t displayRange, int8_t bufferSize=INPUT_BUFFER_SIZE);

    /**
     * @brief to destory the buffer for storing the characters
     * 
     */
    void destroy();

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
     * @param char** - the character pointer for the data
     * @param int* - the length of the character array
     */
    void getInputValue(char **ptr, int *length);
    void blinkUpdate();

  private:
    int8_t valueIndex;
    int8_t showIndex;
    int8_t displayRange;
    int8_t bufferSize;
    char *buffer = NULL;
};

#endif