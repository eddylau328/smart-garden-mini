#include "ModeController.h"

bool ModeController::getIsIdle() {
    return this->isIdle;
}

void ModeController::setIsIdle(bool isIdle) {
    this->isIdle = isIdle;
}