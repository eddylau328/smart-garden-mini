#include "RotaryEncoder.h"

uint8_t RotaryEncoder::rotateRecordPeriod;
uint8_t RotaryEncoder::eventTrigger = 0x00;
uint8_t RotaryEncoder::dtPin;
uint8_t RotaryEncoder::clkPin;
uint8_t RotaryEncoder::swPin;
int8_t RotaryEncoder::buffer = 0x00;
int8_t RotaryEncoder::counterRecord = 0x00;
int RotaryEncoder::counter = 0;
unsigned long RotaryEncoder::lastRotate;
unsigned long RotaryEncoder::lastPress;
unsigned long RotaryEncoder::lastEventCallback;

RotaryEncoder::RotaryEncoder(uint8_t dtPin, uint8_t clkPin, uint8_t swPin, uint8_t rotateRecordPeriod) {
  this->dtPin = dtPin;
  this->clkPin = clkPin;
  this->swPin = swPin;
  this->rotateRecordPeriod = rotateRecordPeriod;
}

RotaryEncoder::~RotaryEncoder() {}

void RotaryEncoder::init(void (*_pressCallback)(), void (*_rotateCallback)(int)) {
  pinMode(dtPin,INPUT);
  pinMode(clkPin,INPUT);
  pinMode(swPin,INPUT);

  attachInterrupt(digitalPinToInterrupt(clkPin), RotaryEncoder::rotate, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(swPin),RotaryEncoder:: press, RISING);

  rotateCallback = _rotateCallback;
  pressCallback = _pressCallback;
}

void RotaryEncoder::eventLoop() {
  if (millis() - lastEventCallback > 400) {
    if (eventTrigger >> 4 & 1) {
      pressCallback();
      eventTrigger = Helper::modifyBit(eventTrigger, 4, 0);
    }
    if (eventTrigger & 1) {
      rotateCallback(counter);
      counter = 0;
      eventTrigger = Helper::modifyBit(eventTrigger, 0, 0);
    }
    lastEventCallback = millis();
  }
}

/**
 * AB -> CD 
 * 01 -> 10 CLK
 * 10 -> 00 CLK
 * 00 -> 10 ANTI
 * 11 -> 00 ANTI
 */ 

void RotaryEncoder::rotate() {
  if (micros() - lastRotate > rotateRecordPeriod) {
    buffer ^= digitalRead(clkPin);
    buffer ^= digitalRead(dtPin) << 1;
    if (buffer == 0x06 || buffer == 0x08) {
      if (counterRecord == 0x32) {
        counter--;
        counterRecord = 0x30 | buffer;
      }
      else {
        counter++;
        counterRecord = 0xc0 | buffer;
      }
      eventTrigger = Helper::modifyBit(eventTrigger, 0, 1);
    }
    else if (buffer == 0x02 || buffer == 0x0c) {
      if (counterRecord == 0xc8) {
        counter++;
        counterRecord = 0xc0 | buffer;
      }
      else  {
        counter--;
        counterRecord = 0x30 | buffer;
      }
      eventTrigger = Helper::modifyBit(eventTrigger, 0, 1);
    }
    buffer <<= 2;
    buffer &= 0x0f;
    lastRotate = micros();
  }
}

void RotaryEncoder::press() {
  if (millis() - lastPress > 500) {
    eventTrigger = Helper::modifyBit(eventTrigger, 4, 1);
    lastPress = millis();
  }
}