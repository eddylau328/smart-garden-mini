#ifndef InputAlphabet_h
#define InputAlphabet_h

#include "../InputTool.h"

class InputAlphabet : public InputTool {

  public:
    void set(const char* defaultValue, int8_t stringLength);
    bool interactiveUpdate(int counter, bool isPress);

  private:
    int8_t valueIndex;

    bool isUpperCase(char value);
    bool isLowerCase(char value);

};

#endif