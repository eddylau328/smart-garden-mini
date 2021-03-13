#ifndef DataTransmitter_h
#define DataTransmitter_h

#include "TransmitAction.h"

class DataTransmitter {

    public:
        virtual void listen() = 0;
        virtual void send(TransmitAction::SendAction actionType) = 0;
        bool getIsEnableTransmission();
        void setIsEnableTransmission(bool isEnable);

    private:
        bool isEnableTransmission = false;

};

#endif