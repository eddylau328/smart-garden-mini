#ifndef InputBoolean_h
#define InputBoolean_h

#include "../InputTool.h"

class InputBoolean : public InputTool {

  public:
    void set(bool defaultValue);
    bool interactiveUpdate(int counter, bool isPress);
  
};

#endif