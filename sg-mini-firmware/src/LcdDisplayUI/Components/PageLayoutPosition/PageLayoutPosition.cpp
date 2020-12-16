/*
    PageLayoutPosition.cpp - class is for saving the column and row of a content, cursor or other page objects
*/

#include "PageLayoutPosition.h"

PageLayoutPosition::PageLayoutPosition(){
    col = 0;
    row = 0;
}

PageLayoutPosition::PageLayoutPosition(int8_t col, int8_t row){
    this->col = col;
    this->row = row;
}

void PageLayoutPosition::set(int8_t col, int8_t row){
    this->col = col;
    this->row = row;
}

void PageLayoutPosition::operator = (const PageLayoutPosition& pos) {
    this->col = pos.col;
    this->row = pos.row;
}

bool PageLayoutPosition::operator == (const PageLayoutPosition& pos){
    if (pos.col == this->col && pos.row == this->row)
        return true;
    else
        return false;
}