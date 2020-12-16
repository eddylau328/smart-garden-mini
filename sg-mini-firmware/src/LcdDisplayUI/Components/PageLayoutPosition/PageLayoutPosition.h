/*
    PageLayoutPosition.h - class is for saving the column and row of a content, cursor or other page objects
*/

#ifndef PageLayoutPosition_h
#define PageLayoutPosition_h

#include <Arduino.h>

class PageLayoutPosition{
    public:
        PageLayoutPosition();
        PageLayoutPosition(int8_t col, int8_t row);
        void set(int8_t col, int8_t row);
        bool operator == (const PageLayoutPosition &pos);
        void operator = (const PageLayoutPosition &pos);
        int8_t col, row;
};

#endif
