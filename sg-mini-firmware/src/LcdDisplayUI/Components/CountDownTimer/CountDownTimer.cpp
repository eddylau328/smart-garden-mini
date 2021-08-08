#include "CountDownTimer.h"


void CountDownTimer::updateContent() {
    if (timer.isRunning() && !isFinished) {
        isFinished = timer.justFinished();
        uint8_t newSecond = (uint8_t) ceil((float) timer.remaining() / 1000.0);
        if (newSecond < second) {
            connectContent->updateContent((int)newSecond);
            second = newSecond;
        }
    }
}

void CountDownTimer::setTimer(unsigned long startTime) {
    this->startTime = startTime;
}

bool CountDownTimer::isFinish() {
    return isFinished;
}

void CountDownTimer::start() {
    second = startTime / 1000;
    connectContent->updateContent((int) second);
    timer.start(startTime);
}

void CountDownTimer::stop() {
    timer.stop();
}

void CountDownTimer::restart() {
    isFinished = false;
    second = startTime / 1000;
    connectContent->updateContent((int) second);
    timer.restart();
}