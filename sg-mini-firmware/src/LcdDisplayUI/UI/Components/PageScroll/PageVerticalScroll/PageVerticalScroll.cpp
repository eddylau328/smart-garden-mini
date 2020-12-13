#include "PageVerticalScroll.h"

void PageVerticalScroll::setCoverArea(PageLayoutRange rowRange) {
  this->rowRange = rowRange;
  upScrollMax = -(rowRange.max - screenHeight + 1);
  downScrollMax = rowRange.min;
}

void PageVerticalScroll::updateScroll(PageContent *contents, int length, int counter) {
  PageLayoutPosition newPos;
  int8_t reverseCounter = -(int8_t)counter;
  int8_t newOrigin = reverseCounter + currentOrigin; 
  if (reverseCounter < 0) {
    if (newOrigin < upScrollMax )
      newOrigin = upScrollMax;
  }
  else if (reverseCounter > 0) {
    if (newOrigin > downScrollMax)
      newOrigin = downScrollMax;
  }
  if (newOrigin != currentOrigin) {
    for (int i = 0; i < length; i++){
      newPos = (contents + i)->getNewPos();
      newPos.row += (newOrigin - currentOrigin);
      (contents + i)->updatePos(newPos);
    }
    currentOrigin = newOrigin;
  }
}

void PageVerticalScroll::resetScroll(PageContent *contents, int length) {
  PageLayoutPosition newPos; 
  for (int i = 0; i < length; i++){
    newPos = (contents + i)->getNewPos();
    newPos.row -= currentOrigin;
    (contents + i) ->updatePos(newPos);
  }
}