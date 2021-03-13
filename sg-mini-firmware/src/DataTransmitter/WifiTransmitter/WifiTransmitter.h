#ifndef WifiTransmitter_h
#define WifiTransmitter_h

#include "../DataTransmitter.h"
#include <HTTPClient.h>
#include "../../WifiController/WifiController.h"
#include "../JsonParser/JsonParser.h"


class WifiTransmitter : public DataTransmitter {

    public:
        void listen();
        void send(TransmitAction::SendAction actionType);
    
    private:
        void sendSensorData();
        const char* serverName = "http://192.168.0.105:3000/";
};

#endif