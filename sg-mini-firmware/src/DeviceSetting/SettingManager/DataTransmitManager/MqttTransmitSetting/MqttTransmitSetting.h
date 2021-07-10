#ifndef MqttTransmitSetting_h
#define MqttTransmitSetting_h

#include "../../../../Helper/Helper.h"


class MqttTransmitSetting {

    public:
        MqttTransmitSetting();
        MqttTransmitSetting(uint8_t *ip, uint16_t port);

        void setMqttServerIp(uint8_t *ip);
        void setMqttServerIp(const uint8_t *ip);
        void setMqttServerPort(uint16_t port);

        uint8_t* getMqttServerIp();
        uint16_t getMqttServerPort();

        MqttTransmitSetting& operator = (const MqttTransmitSetting &setting);
    
    private:
        uint8_t mqttServerIp[4];
        uint16_t mqttServerPort;
};

#endif