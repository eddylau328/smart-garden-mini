#ifndef DataTransmitter_h
#define DataTransmitter_h

#include "TransmitAction.h"

class DataTransmitter {

    public:
        virtual void init();
        virtual void mainLoop();
        virtual void send(TransmitAction::SendAction actionType);
        bool getIsEnableTransmission();
        void setIsEnableTransmission(bool isEnable);

    private:
        bool isEnableTransmission = false;

};

#endif