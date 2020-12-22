#include "PageVerticalScroll.h"


void PageVerticalScroll::setCoverArea(PageLayoutRange rowRange) {
  this->rowRange = rowRange;
  upScrollMax = -(rowRange.max - screenHeight + 1);
  downScrollMax = rowRange.min;
}

void PageVerticalScroll::setCursor(PageContent *content, int defaultRow = 0 ) {
  cursor = content;
  cursorDefaultRow = (int8_t) defaultRow;
  if (cursorDefaultRow >= rowRange.max)
    cursorRow = screenHeight - 1;
  else if (cursorDefaultRow <= rowRange.min)
    cursorRow = 0;
  else
    cursorRow = (screenHeight - 1) / 2;
}

void PageVerticalScroll::updateScroll(PageContent *contents, int length, int counter) {
  PageLayoutPosition newPos;
  int8_t adjustCounter = (int8_t)counter;
  int8_t rowMaxIndex = screenHeight - 1;
  if (cursor) {
    if (cursorRow == 0) {
      // handle cursor scroll down (clockwise +)
      if (adjustCounter > 0) {
        if (adjustCounter > rowMaxIndex) {
          cursorRow = rowMaxIndex;
          adjustCounter -= rowMaxIndex;
        }
        else {
          cursorRow += adjustCounter;
          adjustCounter = 0;
        }
      }
      // no need to handle cursor scroll up
    }
    else if (cursorRow == rowMaxIndex) {
      // handle cursor scroll up (anti-clockwise -)
      if (adjustCounter < 0) {
        if (adjustCounter + rowMaxIndex < 0) {
          cursorRow = 0;
          adjustCounter += rowMaxIndex;
        }
        else {
          cursorRow += adjustCounter;
          adjustCounter = 0;
        }
      }
      // no need to handle cursor scroll down
    }
    else {
      if (adjustCounter < 0) {
        if (adjustCounter + cursorRow < 0) {
          adjustCounter += cursorRow;
          cursorRow = 0;
        }
        else {
          cursorRow += adjustCounter;
          adjustCounter = 0;
        }
      }
      else {
        if (adjustCounter + cursorRow > rowMaxIndex) {
          adjustCounter -= rowMaxIndex - cursorRow;
          cursorRow = rowMaxIndex;
        }
        else {
          cursorRow += adjustCounter;
          adjustCounter = 0;
        }
      }
    }
    newPos = cursor->getNewPos();
    if (cursorRow != newPos.row) {
      newPos.row = cursorRow;
      cursor->updatePos(newPos);
    }
  }

  int8_t reverseCounter = -adjustCounter;
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
    if (cursor) {
      for (int i = 0; i < length; i++){
        if (cursor != contents+i) {
          newPos = (contents + i)->getNewPos();
          newPos.row += (newOrigin - currentOrigin);
          (contents + i)->updatePos(newPos);
        }
      }
    }
    else {
      for (int i = 0; i < length; i++){
        newPos = (contents + i)->getNewPos();
        newPos.row += (newOrigin - currentOrigin);
        (contents + i)->updatePos(newPos);
      }
    }
    currentOrigin = newOrigin;
  }
}

void PageVerticalScroll::resetScroll(PageContent *contents, int length) {
  PageLayoutPosition newPos;
  if (cursor) {
    newPos = cursor->getNewPos();
    newPos.row = cursorDefaultRow;
    cursor->updatePos(newPos);
    for (int i = 0; i < length; i++){
      if (cursor != contents+i) {
        newPos = (contents + i)->getNewPos();
        newPos.row -= currentOrigin;
        (contents + i)->updatePos(newPos);
      }
    }
  }
  else {
    for (int i = 0; i < length; i++){
      newPos = (contents + i)->getNewPos();
      newPos.row -= currentOrigin;
      (contents + i)->updatePos(newPos);
    }
  }
  currentOrigin = 0;
}

int8_t PageVerticalScroll::getCurrentArrowRow(PageContent *contents, int length) {
  PageLayoutPosition newPos;
  for (int i = 0; i < length; i++) {
    if (cursor != contents+i) {
      newPos = (contents + i)->getNewPos();
      if (newPos.row == cursorRow)
        return newPos.row - currentOrigin;
    }
  }
  return 0;
}