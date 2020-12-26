#ifndef InputTool_h
#define InputTool_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../PageContent/PageContent.h"
#include "../../../Helper/Helper.h"

class InputTool {

  public:
    InputTool();
    ~InputTool();

    void setLinkage(PageContent *pageContent);
    void setCircleLoop(bool isCircleLoop);
    void startBlink();

    virtual void blinkUpdate();

    /**
     * @param counter number of rotation
     * @param isPress whether the button is Pressed
     * @return whether the input is finish or not
     */
    virtual bool interactiveUpdate(int counter, bool isPress) = 0;

  protected:
    bool isCircleLoop = true;
    int8_t stringLength = 0;
    PageContent *connectContent;
    bool isBlink = false;
    bool isBlinking = false;

    static char copyBuffer[20];
    static unsigned long lastInputTrigger;
};

#endif