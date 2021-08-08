#ifndef InputNumber_h
#define InputNumber_h

#include "../InputTool.h"

/**
 * @brief InputTool for inputting integer
 * 
 */
class InputNumber : public InputTool {

  public:

    /**
     * @brief set the InputNumber attributes for rendering and logic handling
     * 
     * @param defaultValue - the default 8-bit integer value you want to show, [-128, 127]
     * @param minNumber - the minimum 8-bit integer it can input
     * @param maxNumber - the maximum 8-bit integer it can input
     * @param keptZero - whether displaying the zero if the assign integer data has a shorter length than the assigned content length
     */
    void set(int8_t defaultValue, int8_t minNumber, int8_t maxNumber, bool keptZero=false);
    bool interactiveUpdate(int counter, bool isPress);
    void blinkUpdate();

    /**
     * @brief Get the 8-bit integer from the InputNumber object 
     * 
     * @return int8_t - the value input from the user
     */
    int8_t getInputValue();

  private:
    int8_t minNumber = 0;
    int8_t maxNumber = 9;
    int8_t inputNumber;
    bool keptZero = false;
};

#endif