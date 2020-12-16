#ifndef InputAscii_h
#define InputAscii_h

#include "../InputTool.h"

class InputAscii : public InputTool {

  public:
    void set(const char* defaultValue, int8_t stringLength);
    bool interactiveUpdate(int counter, bool isPress);

  private:
    int8_t valueIndex;
    
};

#endif