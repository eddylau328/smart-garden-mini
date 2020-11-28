/*
    PageLayoutPosition.h - class is for saving the column and row of a content, cursor or other page objects
*/

#ifndef PageLayoutPosition_h
#define PageLayoutPosition_h

#include <Arduino.h>

class PageLayoutPosition{
    public:
        PageLayoutPosition();
        PageLayoutPosition(byte col, byte row);
        void set(byte col, byte row);
        void setRow(byte row);
        void setCol(byte col);
        void set(PageLayoutPosition pos);
        bool compare(PageLayoutPosition pos);
        PageLayoutPosition get();
        byte col, row;
};

class PageLayoutRange{
    public:
        PageLayoutRange();
        PageLayoutRange(byte min, byte max);
        void set(byte min, byte max);
        void set(PageLayoutRange range);
        byte min, max;
};

#endif
