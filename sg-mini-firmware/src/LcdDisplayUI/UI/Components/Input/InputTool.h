#ifndef InputTool_h
#define InputTool_h

#include <Arduino.h>
#include "../PageContent/PageContent.h"
#include "../../../../Helper/Helper.h"

class InputTool {

  public:
    enum InputType {
      none, boolean, number, alphabet, ascii
    };

    InputTool();
    ~InputTool();

    uint8_t getId();
    void setLinkage(PageContent *pageContent);
    void setBool(bool defaultValue);
    void setNumber(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool isCircleLoop);
    void setAlphabet(const char* defaultValue, int8_t stringLength);
    void setAscii(const char* defaultValue, int8_t stringLength);
    void interactiveUpdate(int counter);

  private:
    char *inputValue;
    int8_t minNumber = 0;
    int8_t maxNumber = 9;
    bool isCircleLoop = true;
    int8_t stringLength = 1;
    PageContent *connectContent;
    InputType inputType = InputType::none;

    void handleBoolUpdate(int counter);
    void handleNumberUpdate(int counter);
    void handleAlphabetUpdate(int counter);
    void handleAsciiUpdate(int counter);
};

#endif