#ifndef InputTool_h
#define InputTool_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../PageContent/PageContent.h"
#include "../../../Helper/Helper.h"

/**
 * @brief provides the base structure for an input tool to inherit with
 * 
 */
class InputTool {

  public:
    InputTool();
    ~InputTool();

    /**
     * @brief Set the Linkage between the PageContent object and the InputTool object
     * 
     * @param pageContent - PageContent object pointer for showing the input content
     */
    void setLinkage(PageContent *pageContent);

    /**
     * @brief Set whether the input value is circle loop, e.g. [0, 2] => 0 -> 1 -> 2 -> 0
     * 
     * @param isCircleLoop - indicate whether 
     */
    void setCircleLoop(bool isCircleLoop);

    /**
     * @brief set the input content to blink
     * 
     */
    void startBlink();

    /**
     * @brief Allow input content to blink (Noted: call this function in udpateContents() from Page Class)
     * 
     */
    virtual void blinkUpdate();

    /**
     * @brief update the input content according to the interactive action
     * 
     * @param counter - the clockwise/anti-clockwise step count
     * @param isPress - the press state of the button
     * @return true - indicates the input process is finished
     * @return false - indicates the input process is not finished
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