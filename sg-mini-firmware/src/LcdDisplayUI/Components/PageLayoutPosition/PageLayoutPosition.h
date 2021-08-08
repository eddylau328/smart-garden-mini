/*
    PageLayoutPosition.h - class is for saving the column and row of a content, cursor or other page objects
*/

#ifndef PageLayoutPosition_h
#define PageLayoutPosition_h

#include <Arduino.h>

/**
 * @brief saving the column and row of a content, cursor or other page objects
 * 
 */
class PageLayoutPosition{
    public:
        PageLayoutPosition();

        /**
         * @brief Construct a new Page Layout Position object
         * the origin position of the Lcd screen is the left up corner which is (col, row) = (0, 0) 
         * 
         * @param col - the column position  
         * @param row - the row position
         */
        PageLayoutPosition(int8_t col, int8_t row);

        /**
         * @brief update the position with new column and row position
         * 
         * @param col - the new column position
         * @param row - the new row position
         */
        void set(int8_t col, int8_t row);

        /**
         * @brief compare two PageLayoutPosition
         * 
         * @param pos - the position you want to compare with
         * @return true - the position are same
         * @return false - the position are different
         */
        bool operator == (const PageLayoutPosition &pos);

        /**
         * @brief assign new PageLayoutPosition
         * 
         * @param pos - the position you want to assign
         */
        void operator = (const PageLayoutPosition &pos);
        int8_t col, row;
};

#endif
