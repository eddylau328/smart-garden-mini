#ifndef InputAlphabet_h
#define InputAlphabet_h

#include "../InputTool.h"

class InputAlphabet : public InputTool {

  public:
    ~InputAlphabet();
    void set(const char* defaultValue, int8_t stringLength);
    bool interactiveUpdate(int counter, bool isPress);
    char* getInputValue();
    void blinkUpdate();

  private:
    int8_t valueIndex;
    char *inputValue;

    bool isUpperCase(char value);
    bool isLowerCase(char value);

};

#endif