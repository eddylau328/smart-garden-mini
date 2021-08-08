#ifndef DataTransmitter_h
#define DataTransmitter_h

#include "TransmitAction.h"
#include "JsonParser/JsonParser.h"
#include "JsonParser/InitJsonParser/InitJsonParser.h"
#include "JsonParser/SensorJsonParser/SensorJsonParser.h"
#include "../DeviceSetting/DeviceManager.h"
#include "../DeviceSetting/SettingManager/DataTransmitManager/DataTransmitManager.h"

class DataTransmitter {

    public:
        virtual void init();
        virtual void mainLoop();
        virtual void disconnect();

        void send(TransmitAction::SendAction actionType);
        bool getIsEnableTransmission();
        void setIsEnableTransmission(bool isEnable);

    protected:
        // actions
        virtual void sendInit(JsonParser *parser);
        virtual void sendSensorData(JsonParser *parser);

    private:
        bool isEnableTransmission = false;
        // helper functions
        JsonParser* getJsonParser(TransmitAction::SendAction actionType);

};

#endif