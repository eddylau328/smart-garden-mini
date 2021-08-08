#include "MqttTransmitter.h"

String MqttTransmitter::deviceId = "";
const String MqttTransmitter::BASE_PATH = "device/";
const String MqttTransmitter::INIT_PATH = "init/";
const String MqttTransmitter::SEND_DATA_PATH = "data/";
const String MqttTransmitter::CONTROL_VALVE_PATH = "valve/";



MqttTransmitter::MqttTransmitter() {
    client = new PubSubClient(wifiClient);
}

MqttTransmitter::~MqttTransmitter() {
    delete client;
}

void MqttTransmitter::init() {
    deviceId = WiFi.macAddress();
    lastReconnectAttempt = 0;
    Serial.print("deviceId");
    Serial.println(deviceId);
}

void MqttTransmitter::mainLoop() {
    if (!WifiController::isConnectedNetwork()) return;

    updateServerSetting();
    if (!client->connected()) {
        this->isConnected = false;
        if (millis() - lastReconnectAttempt > 5000 && reconnect())
            lastReconnectAttempt = 0;
    }
    else {
        if (!this->isConnected) {
            this->isConnected = true;
            this->send(TransmitAction::SendAction::Init);
        }
        // Client connected
        client->loop();
    }
}

void MqttTransmitter::sendInit(JsonParser *parser) {
    String path = BASE_PATH + INIT_PATH + deviceId;
    char *message = new char[MESSAGE_BUFFER];
    parser->parse(&message, MESSAGE_BUFFER);
    this->mqttSend(path, message);
    delete message;
}

void MqttTransmitter::sendSensorData(JsonParser *parser) {
    String path = BASE_PATH + SEND_DATA_PATH + deviceId;
    char *message = new char[MESSAGE_BUFFER];
    parser->parse(&message, MESSAGE_BUFFER);
    this->mqttSend(path, message);
}

void MqttTransmitter::handleReceiveMessage(char *title, byte *message, unsigned int length) {
    char *serializedMessage = new char[length];
    Helper::copyString(serializedMessage, message, length);
    String path = BASE_PATH + CONTROL_VALVE_PATH + deviceId;
    if (Helper::compareString(title, path.c_str(), 30)) {
        for (int i = 0; i < length; i++)
            Serial.print(*(serializedMessage+i));
        Serial.println();
    }
}

bool MqttTransmitter::reconnect() {
  if (client->connect("esp32Client")) {
    // ... and resubscribe
    String path = BASE_PATH + CONTROL_VALVE_PATH + deviceId;
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
    return !(Helper::compareUInt8_t(
        this->mqttServerIp,
        setting.getMqttServerIp(),
        4
    ) && this->mqttServerPort == setting.getMqttServerPort());
}

void MqttTransmitter::updateServerSetting() {
    DataTransmitManager *manager = DeviceManager::getDataTransmitManager();
    MqttTransmitSetting setting = manager->getMqttTransmitSetting();
    if (manager->getIsMqttTransmitSet() && this->shouldUpdateServer(setting)) {
        Helper::copyUInt8_t(this->mqttServerIp, setting.getMqttServerIp(), 4);
        this->mqttServerPort = setting.getMqttServerPort();
        this->disconnect();
        this->debugConnection();
        client->setServer(mqttServerIp, mqttServerPort);
        client->setCallback(handleReceiveMessage);
    }
}

void MqttTransmitter::mqttSend(String path, char *message) {
    bool isPublished = client->publish(path.c_str(), message);
    Serial.print("publish ");
    Serial.println(path);
    Serial.println(isPublished);
    Serial.println(message);
    Serial.println(client->state());
}

void MqttTransmitter::debugConnection() {
    Serial.print("establish connection to ");
    for (int i = 0; i < 4; i++) {
        Serial.print(mqttServerIp[i]);
        if (i < 3)
            Serial.print(".");
    }
    Serial.print(":");
    Serial.println(mqttServerPort);
}