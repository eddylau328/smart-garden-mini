#include "LoadingSpinner.h"

void LoadingSpinner::setLinkage(PageContent *content) {
  this->connectContent = content;
}

void LoadingSpinner::spin(bool isSpin) {
  this->isEnableSpin = isSpin;
  loadingUpdateDelay.start(500);
}

void LoadingSpinner::clear() {
  connectContent->updateContent(" ", 1);
  loadingUpdateDelay.stop();
}

void LoadingSpinner::updateSpinner() {
  if (isEnableSpin && loadingUpdateDelay.justFinished()) {
    loadingUpdateDelay.repeat();
    switch(loadingIndex) {
      case 0:
        connectContent->updateContent("-", 1);
        break;
      case 1:
        connectContent->setCustomCharacterIndex(CUSTOM_BACKSLASH);
        break;
      case 2:
        connectContent->updateContent("|", 1);
        break;
      case 3:
        connectContent->updateContent("/", 1);
        break;
    }
    loadingIndex = (loadingIndex + 1) % 4;
  }
}

bool LoadingSpinner::isSpinning() {
  return isEnableSpin;
}