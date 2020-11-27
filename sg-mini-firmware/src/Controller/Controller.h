#ifndef Controller_h
#define Controller_h

#include <Arduino.h>
#include <DebugLog.h>
#include "../Config/Config.h"


class Controller {

  public:
    Controller();
    ~Controller();

    void init();
    void update();
  
  private:
    void initInterval();
    static void onTimer();

    int totalInterruptCounter;
    hw_timer_t *timer = NULL;
    static volatile int interruptCounter;
    static portMUX_TYPE timerMux;
};

#endif