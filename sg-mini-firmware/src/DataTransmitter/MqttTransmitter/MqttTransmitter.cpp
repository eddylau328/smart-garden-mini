#include "MqttTransmitter.h"

String MqttTransmitter::deviceId = "";
String MqttTransmitter::basePath = "device/";
String MqttTransmitter::sendDataPath = "data/";
String MqttTransmitter::controlValvePath = "valve/";


MqttTransmitter::MqttTransmitter() {
    client = new PubSubClient(wifiClient);
}

MqttTransmitter::~MqttTransmitter() {
    delete client;
}

void MqttTransmitter::init() {
    updateServerSetting();
    deviceId = WiFi.macAddress();
    lastReconnectAttempt = 0;
    Serial.println(deviceId);
}

void MqttTransmitter::mainLoop() {
    if (!WifiController::isConnectedNetwork()) return;

    updateServerSetting();
    if (!client->connected()) {
        if (millis() - lastReconnectAttempt > 5000 && reconnect())
            lastReconnectAttempt = 0;
    }
    else {
        // Client connected
        client->loop();
    }
}

void MqttTransmitter::send(TransmitAction::SendAction actionType) {
    char *message = new char[MESSAGE_BUFFER];
    JsonParser::writeSensorData(&message, MESSAGE_BUFFER);
    String path = basePath + sendDataPath + deviceId;
    Serial.println(path);
    bool isPublished = client->publish(path.c_str(), message);
    Serial.print("publish ");
    Serial.println(isPublished);
    Serial.println(message);
    Serial.println(client->state());
}

void MqttTransmitter::handleReceiveMessage(char *title, byte *message, unsigned int length) {
    char *serializedMessage = new char[length];
    Helper::copyString(serializedMessage, message, length);
    String path = basePath + controlValvePath + deviceId;
    if (Helper::compareString(title, path.c_str(), 30)) {
        for (int i = 0; i < length; i++)
            Serial.print(*(serializedMessage+i));
        Serial.println();
    }
}

bool MqttTransmitter::reconnect() {
  if (client->connect("esp32Client")) {
    // ... and resubscribe
    String path = basePath + controlValvePath + deviceId;
    client->subscribe(path.c_str());
  }
  return client->connected();
}

void MqttTransmitter::disconnect() {
    if (client && client->connected())
        client->disconnect();
}

// private

bool MqttTransmitter::shouldUpdateServer(MqttTransmitSetting setting) {
    return Helper::compareUInt8_t(
        this->mqttServerIp,
        setting.getMqttServerIp(),
        4
    ) && this->mqttServerPort == setting.getMqttServerPort();
}

void MqttTransmitter::updateServerSetting() {
    DataTransmitManager *manager = DeviceManager::getDataTransmitManager();
    MqttTransmitSetting setting = manager->getMqttTransmitSetting();
    if (manager->getIsMqttTransmitSet() && this->shouldUpdateServer(setting)) {
        Helper::copyUInt8_t(this->mqttServerIp, setting.getMqttServerIp(), 4);
        this->mqttServerPort = setting.getMqttServerPort();
        this->disconnect();
        client->setServer(mqttServerIp, mqttServerPort);
        client->setCallback(handleReceiveMessage);
    }
}