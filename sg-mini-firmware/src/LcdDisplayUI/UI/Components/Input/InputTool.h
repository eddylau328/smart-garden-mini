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
    
    /**
     * @param counter number of rotation
     * @param isPress whether the button is Pressed
     * @return whether the input is finish or not
     */
    virtual bool interactiveUpdate(int counter, bool isPress) = 0;

  protected:
    char *inputValue;
    bool isCircleLoop = true;
    int8_t stringLength = 0;
    PageContent *connectContent;
};

#endif