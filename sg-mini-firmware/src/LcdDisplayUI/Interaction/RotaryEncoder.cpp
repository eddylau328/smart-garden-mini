#include "RotaryEncoder.h"

unsigned long RotaryEncoder::lastPressInterrupt = 0;
unsigned long RotaryEncoder::lastRotateInterrupt = 0;
uint8_t RotaryEncoder::_pinA;
uint8_t RotaryEncoder::_pinB;
bool RotaryEncoder::previousPair = false;
bool RotaryEncoder::currentPair = false;
void (*RotaryEncoder::_pressCallback)();
void (*RotaryEncoder::_rotateCallback)(bool);


RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin) {
  _pinA = pinA;  // DT
  _pinB = pinB;  // CLK
  this->buttonPin = buttonPin;  // SW
}

void RotaryEncoder::init(void (*pressCallback)(), void (*rotateCallback)(bool)) {
  pinMode(buttonPin, INPUT);       // Enable the switchPin as input
  pinMode(_pinA, INPUT);            // Set PinA as input
  pinMode(_pinB, INPUT);            // Set PinB as input

  // previousCLK = digitalRead(pinB);
  // previousData = digitalRead(pinA);

  // Atach a CHANGE interrupt to PinB and exectute the update function when this change occurs.
  attachInterrupt(digitalPinToInterrupt(_pinB), RotaryEncoder::rotate, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPin), RotaryEncoder::press, FALLING);

  _pressCallback = pressCallback;
  _rotateCallback = rotateCallback;
}

void RotaryEncoder::press() {
  Serial.println("test");
  // if(millis() - lastPressInterrupt > 500){ // we set a 10ms no-interrupts window 
  //   // LOG_WARNING("Button Press");
  //   // _pressCallback();
  //   lastPressInterrupt = millis();
  // }
}

void RotaryEncoder::rotate() {
    if ((millis() - lastRotateInterrupt) > 5)
    {
        currentPair = digitalRead(_pinA) && digitalRead(_pinB);
        
        lastRotateInterrupt = millis();
    }
}