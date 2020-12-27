#include "Controller.h"

portMUX_TYPE Controller::timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile int Controller::interruptCounter = 0;

Controller::Controller() {}

Controller::~Controller() {
  delete sensors;
}

void Controller::init(Sensors *sensors) {
  this->sensors = sensors; 

  initInterval();
}

void Controller::update() {
  if (interruptCounter > 0) {
 
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);

    LOG_WARNING("Interrupt Start");
    LOG_WARNING("Read all sensors");
    this->sensors->read();
    LOG_WARNING("Interrupt End");
  }
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

