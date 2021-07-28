#ifndef MqttTransmitter_h
#define MqttTransmitter_h

#include <WiFi.h>
#include <PubSubClient.h>

#include "../../WifiController/WifiController.h"
#include "../DataTransmitter.h"
#include "../../Helper/Helper.h"
#include "../JsonParser/JsonParser.h"
#include "../JsonParser/InitJsonParser/InitJsonParser.h"
#include "../JsonParser/SensorJsonParser/SensorJsonParser.h"
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
        bool isConnected = false;

        WiFiClient wifiClient;
        PubSubClient *client;
        unsigned long lastReconnectAttempt = 0;
        static void handleReceiveMessage(char *title, byte *message, unsigned int length);

        static String deviceId;
        static const String BASE_PATH;
        static const String INIT_PATH;
        static const String SEND_DATA_PATH;
        static const String CONTROL_VALVE_PATH;

        uint8_t mqttServerIp[4];
        uint16_t mqttServerPort;
        bool shouldUpdateServer(MqttTransmitSetting setting);
        void updateServerSetting();
        JsonParser* getJsonParser(TransmitAction::SendAction actionType);
        String getPublishPath(TransmitAction::SendAction actionType);
};

#endif