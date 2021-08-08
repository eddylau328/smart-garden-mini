#ifndef MqttTransmitter_h
#define MqttTransmitter_h

#include <WiFi.h>
#include <PubSubClient.h>

#include "../../WifiController/WifiController.h"
#include "../DataTransmitter.h"
#include "../../Helper/Helper.h"
#include "../../DeviceSetting/SettingManager/DataTransmitManager/MqttTransmitSetting/MqttTransmitSetting.h"

#define MESSAGE_BUFFER 100

class MqttTransmitter : public DataTransmitter {
    
    public:
        MqttTransmitter();
        ~MqttTransmitter();
        void init();
        void mainLoop();
        bool reconnect();
        void disconnect();

    protected:
        void sendInit(JsonParser *parser);
        void sendSensorData(JsonParser *parser);
    
    private:
        bool isConnected = false;

        WiFiClient wifiClient;
        PubSubClient *client;
        unsigned long lastReconnectAttempt = 0;
        static void handleReceiveMessage(char *title, byte *message, unsigned int length);

        static String deviceId;
        const static String BASE_PATH;
        const static String INIT_PATH;
        const static String SEND_DATA_PATH;
        const static String CONTROL_VALVE_PATH;

        uint8_t mqttServerIp[4];
        uint16_t mqttServerPort;
        bool shouldUpdateServer(MqttTransmitSetting setting);
        void updateServerSetting();

        String getPublishPath(TransmitAction::SendAction actionType);

        void mqttSend(String path, char *message);

        void debugConnection();
};

#endif