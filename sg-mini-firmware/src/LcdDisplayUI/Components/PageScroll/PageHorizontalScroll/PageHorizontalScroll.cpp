#include "PageHorizontalScroll.h"

void PageHorizontalScroll::setCoverArea(PageLayoutRange colRange, PageLayoutRange rowRange) {
  this->colRange = colRange;
  this->rowRange = rowRange;
  leftScrollMax = -(colRange.max - screenWidth + 1);
  rightScrollMax = colRange.min;
}

void PageHorizontalScroll::updateScroll(PageContent **contents, int length, int counter) {
  PageLayoutPosition newPos;
  int8_t newOrigin = (int8_t)counter + currentOrigin; 
  if (counter < 0) {
    if (newOrigin < leftScrollMax )
      newOrigin = leftScrollMax;
  }
  else if (counter > 0) {
    if (newOrigin > rightScrollMax)
      newOrigin = rightScrollMax;
  }
  if (newOrigin != currentOrigin) {
    for (int i = 0; i < length; i++){
      newPos = contents[i]->getNewPos();
      if (Helper::int8_tInRange(newPos.row, rowRange.min, rowRange.max)) {
        newPos.col += (newOrigin - currentOrigin);
        contents[i]->updatePos(newPos);
      }
    }
    currentOrigin = newOrigin;
  }
}

void PageHorizontalScroll::resetScroll(PageContent **contents, int length) {
  PageLayoutPosition newPos; 
  for (int i = 0; i < length; i++){
    newPos = contents[i]->getNewPos();
    if (Helper::int8_tInRange(newPos.row, rowRange.min, rowRange.max)) {
      newPos.col -= currentOrigin;
      contents[i] ->updatePos(newPos);
    }
  }
}