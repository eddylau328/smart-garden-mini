#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"

/**
 * @brief provides interrupt function setup and callback function when rotate and press event trigger by Rotary Encoder Hardware
 * 
 */
class RotaryEncoder {

  public:
    /**
     * @brief Construct a new Rotary Encoder object
     * 
     * @param dtPin - the Data Pin of the board
     * @param clkPin - the Clock Pin of the board
     * @param swPin - the Switch Pin of the board you assigned
     * @param recordPeriod - the recording period (micro-sec) of the rotary encoder to measure the rotate counter
     */
    RotaryEncoder(uint8_t dtPin, uint8_t clkPin, uint8_t swPin, uint8_t recordPeriod);
    ~RotaryEncoder();

    /**
     * @brief It attaches the interrupt event of the rotate event and press event, and it saves the callback function pointer for class that will need to use that. (Noted: The design for this class is not ready for multiple RotaryEncoder Object to assign callback functions.)
     * 
     * @param _pressCallback - the callback function when press action is triggered, nothing will parse to this callback function
     * @param _rotateCallback - the callback function when rotate action is triggered, the step count will parse to this callback function
     */
    void init(void (*_pressCallback)(), void (*_rotateCallback)(int));

    /**
     * @brief It checks whether any interrupt has happened and call the correspond callback function
     * 
     */
    void eventLoop();

  private:
    static uint8_t rotateRecordPeriod;
    static uint8_t eventTrigger;
    static unsigned long lastEventCallback;

    static uint8_t dtPin;
    static uint8_t clkPin;
    static uint8_t swPin;

    static int8_t buffer;
    static int8_t counterRecord;
    static int counter;
    static unsigned long lastRotate;
    static unsigned long lastPress;

    void (*rotateCallback)(int);
    void (*pressCallback)();

    /**
     * @brief It validates the raw data from the rotary encoder and determines the final step count from the user rotate input
     * 
     */
    static void rotate();
    
    /**
     * @brief It determines whether the user press input has passed the minimum gap time, which prevent multiple inputs within a short period of time
     * 
     */
    static void press();
  
};

#endif