#ifndef MqttTransmitter_h
#define MqttTransmitter_h

#include <WiFi.h>
#include <PubSubClient.h>

#include "../../WifiController/WifiController.h"
#include "../DataTransmitter.h"
#include "../../Helper/Helper.h"
#include "../JsonParser/JsonParser.h"
#include "../../DeviceSetting/SettingManager/DataTransmitManager/MqttTransmitSetting/MqttTransmitSetting.h"

#define MESSAGE_BUFFER 100

class MqttTransmitter : public DataTransmitter {
    
    public:
        MqttTransmitter();
        ~MqttTransmitter();
        void init();
        void mainLoop();
        void send(TransmitAction::SendAction actionType);
        bool reconnect();
        void disconnect();
    
    private:
        WiFiClient wifiClient;
        PubSubClient *client;
        unsigned long lastReconnectAttempt = 0;
        static void handleReceiveMessage(char *title, byte *message, unsigned int length);
        static String deviceId;
        static String basePath;
        static String sendDataPath;
        static String controlValvePath;

        uint8_t mqttServerIp[4];
        uint16_t mqttServerPort;
        bool shouldUpdateServer(MqttTransmitSetting setting);
        void updateServerSetting();
};

#endif