#ifndef DataTransmitter_h
#define DataTransmitter_h

#include "TransmitAction.h"
#include "../DeviceSetting/DeviceManager.h"
#include "../DeviceSetting/SettingManager/DataTransmitManager/DataTransmitManager.h"

class DataTransmitter {

    public:
        virtual void init();
        virtual void mainLoop();
        virtual void send(TransmitAction::SendAction actionType);
        virtual void disconnect();

        bool getIsEnableTransmission();
        void setIsEnableTransmission(bool isEnable);

    private:
        bool isEnableTransmission = false;

};

#endif