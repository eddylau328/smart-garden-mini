#ifndef CountDownTimer_h
#define CountDownTimer_h

#include <millisDelay.h>
#include "../BaseComponent/BaseComponent.h"

/**
 * @brief this used to count down seconds
 * 
 */
class CountDownTimer : public BaseComponent {
    public:
        void updateContent();

        void setTimer(unsigned long startTime);
        bool isFinish();

        void start();
        void stop();
        void restart();

    private:
        unsigned long startTime;
        millisDelay timer;
        bool isFinished = false;
        uint8_t second;
};

#endif