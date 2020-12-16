#include "PageLayoutRange.h"


PageLayoutRange::PageLayoutRange(){
    min = 0;
    max = 0;
}

PageLayoutRange::PageLayoutRange(int8_t min, int8_t max){
    this->min = min;
    this->max = max;
}