#ifndef PageLayoutRange_h
#define PageLayoutRange_h

#include <Arduino.h>

class PageLayoutRange{
  public:
      PageLayoutRange();
      PageLayoutRange(int8_t min, int8_t max);
      int8_t min, max;
};

#endif