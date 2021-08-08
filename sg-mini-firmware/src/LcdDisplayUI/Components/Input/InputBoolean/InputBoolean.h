#ifndef InputBoolean_h
#define InputBoolean_h

#include "../InputTool.h"

/**
 * @brief InputTool for inputting boolean
 * 
 */
class InputBoolean : public InputTool {

  public:
    /**
     * @brief Set the default value of the InputBoolean
     * 
     * @param defaultValue - boolean type value, (true = "ON", false = "OFF")
     */
    void set(bool defaultValue);
    bool interactiveUpdate(int counter, bool isPress);

    /**
     * @brief Get the Input Value object
     * 
     * @return true - the input value is set to true
     * @return false - the input value is set to false
     */
    bool getInputValue();
  
  private:
    bool inputBool = false;
  
};

#endif