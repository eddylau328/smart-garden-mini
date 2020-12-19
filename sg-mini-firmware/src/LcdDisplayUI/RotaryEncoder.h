#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include <DebugLog.h>

#include "../Helper/Helper.h"

class RotaryEncoder {

  public:
    RotaryEncoder(uint8_t dtPin, uint8_t clkPin, uint8_t swPin, uint8_t recordPeriod);
    ~RotaryEncoder();

    void init(void (*_pressCallback)(), void (*_rotateCallback)(int));
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

    static void rotate();
    static void press();
  
};

#endif