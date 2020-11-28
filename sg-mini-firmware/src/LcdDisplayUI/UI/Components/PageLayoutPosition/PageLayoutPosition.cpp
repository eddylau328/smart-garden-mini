/*
    PageLayoutPosition.cpp - class is for saving the column and row of a content, cursor or other page objects
*/

#include "PageLayoutPosition.h"

PageLayoutPosition::PageLayoutPosition(){
    col = 0;
    row = 0;
}

PageLayoutPosition::PageLayoutPosition(byte col, byte row){
    this->col = col;
    this->row = row;
}

void PageLayoutPosition::set(byte col, byte row){
    this->col = col;
    this->row = row;
}

void PageLayoutPosition::set(PageLayoutPosition pos){
    this->col = pos.col;
    this->row = pos.row;
}

void PageLayoutPosition::setRow(byte row){
    this->row = row;
}

void PageLayoutPosition::setCol(byte col){
    this->col = col;
}

PageLayoutPosition PageLayoutPosition::get(){
    return *this;
}

bool PageLayoutPosition::compare(PageLayoutPosition pos){
    if (pos.col == this->col && pos.row == this->row)
        return true;
    else
        return false;
}


PageLayoutRange::PageLayoutRange(){
    min = 0;
    max = 0;
}

PageLayoutRange::PageLayoutRange(byte min, byte max){
    this->min = min;
    this->max = max;
}

void PageLayoutRange::set(byte min, byte max){
    this->min = min;
    this->max = max;
}

void PageLayoutRange::set(PageLayoutRange range){
    this->min = range.min;
    this->max = range.max;
}