#ifndef InputTool_h
#define InputTool_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../PageContent/PageContent.h"
#include "../../../../Helper/Helper.h"

class InputTool {

  public:
    InputTool();
    ~InputTool();

    void setLinkage(PageContent *pageContent);
    void setCircleLoop(bool isCircleLoop);
    virtual void interactiveUpdate(int counter, bool isPress) = 0;
    
    
    // void setAscii(const char* defaultValue, int8_t stringLength);

  protected:
    char *inputValue;
    bool isCircleLoop = true;
    int8_t stringLength = 0;
    PageContent *connectContent;
};

#endif