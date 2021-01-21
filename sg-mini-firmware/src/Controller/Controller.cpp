#include "Controller.h"

portMUX_TYPE Controller::timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile int Controller::interruptCounter = 0;

Controller::Controller() {}

Controller::~Controller() {}

void Controller::init() {
  initInterval();
}

void Controller::mainLoop() {
  if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    scheduleTask();
  }
  // if()
}

void Controller::onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void Controller::initInterval() {
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, ReadingInterval, true);
  timerAlarmEnable(timer);
}

void Controller::scheduleTask() {

}

void Controller::AutomodeTask(){

}

void Controller::ScheduleModeTask(){

}

void Controller::ManualModeTask(){

}