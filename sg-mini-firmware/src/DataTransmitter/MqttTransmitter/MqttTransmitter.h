#ifndef MqttTransmitter_h
#define MqttTransmitter_h

#include <WiFi.h>
#include <PubSubClient.h>

#include "../DataTransmitter.h"
#include "../../Helper/Helper.h"
#include "../JsonParser/JsonParser.h"

#define MESSAGE_BUFFER 100

class MqttTransmitter : public DataTransmitter {
    
    public:
        void init();
        void mainLoop();
        void send(TransmitAction::SendAction actionType);
        bool reconnect();
    
    private:
        const char* mqttServer = "192.168.0.105";
        WiFiClient wifiClient;
        PubSubClient *client;
        unsigned long lastReconnectAttempt = 0;
        static void handleReceiveMessage(char *title, byte *message, unsigned int length);
        static String deviceId;
        static String basePath;
        static String sendDataPath;
        static String controlValvePath;
};

#endif