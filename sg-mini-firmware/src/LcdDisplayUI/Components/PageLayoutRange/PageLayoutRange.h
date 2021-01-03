#ifndef PageLayoutRange_h
#define PageLayoutRange_h

#include <Arduino.h>

/**
 * @brief provides a structure for storing the range of the display area
 * 
 */
class PageLayoutRange{
  public:
      PageLayoutRange();

      /**
       * @brief Construct a new Page Layout Range object
       * 
       * @param min - minimum range of the display area
       * @param max - maximum range of the display area
       */
      PageLayoutRange(int8_t min, int8_t max);
      int8_t min, max;
};

#endif