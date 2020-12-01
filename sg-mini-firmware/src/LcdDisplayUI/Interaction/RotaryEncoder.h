#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>
#include <DebugLog.h>

class RotaryEncoder {

  public:
    RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin);

    void init(void (*pressCallBack)(), void (*rotateCallBack)(bool));

  private:
    uint8_t buttonPin;
    static uint8_t _pinA;
    static uint8_t _pinB;
    static unsigned long lastPressInterrupt;
    static unsigned long lastRotateInterrupt;
    static bool previousPair;
    static bool currentPair;

    static void (*_pressCallback)();
    static void (*_rotateCallback)(bool);
    static void press();
    static void rotate();
};

#endif