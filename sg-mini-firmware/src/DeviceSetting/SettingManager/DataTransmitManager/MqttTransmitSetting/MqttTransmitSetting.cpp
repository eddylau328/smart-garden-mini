#include "MqttTransmitSetting.h"


MqttTransmitSetting::MqttTransmitSetting() {}

MqttTransmitSetting::MqttTransmitSetting(uint8_t *ip, uint16_t port) {
    this->setMqttServerIp(ip);
    this->setMqttServerPort(port);
}

void MqttTransmitSetting::setMqttServerIp(const uint8_t *ip) {
    if (sizeof(ip)/sizeof(ip[0]) != 4)
        return;
    for (int i = 0; i < 4; i++)
        this->mqttServerIp[i] = ip[i];
}

void MqttTransmitSetting::setMqttServerIp(uint8_t *ip) {
    if (sizeof(ip)/sizeof(ip[0]) != 4)
        return;
    for (int i = 0; i < 4; i++)
        this->mqttServerIp[i] = ip[i];
}

void MqttTransmitSetting::setMqttServerPort(uint16_t port) {
    this->mqttServerPort = port;
}

uint8_t* MqttTransmitSetting::getMqttServerIp() {
    return this->mqttServerIp;
}

uint16_t MqttTransmitSetting::getMqttServerPort() {
    return this->mqttServerPort;
}

MqttTransmitSetting& MqttTransmitSetting::operator=(const MqttTransmitSetting& target) {
    setMqttServerIp(target.mqttServerIp);
    setMqttServerPort(target.mqttServerPort);
}
