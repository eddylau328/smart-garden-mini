#ifndef InputNumber_h
#define InputNumber_h

#include "../InputTool.h"

class InputNumber : public InputTool {

  public:
    void set(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool keptZero=false);
    bool interactiveUpdate(int counter, bool isPress);
    void blinkUpdate();

  private:
    int8_t minNumber = 0;
    int8_t maxNumber = 9;
    int8_t inputNumber;
    bool keptZero = false;
};

#endif