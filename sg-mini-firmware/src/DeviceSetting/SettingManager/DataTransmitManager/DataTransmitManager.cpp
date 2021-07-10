#include "DataTransmitManager.h"


void DataTransmitManager::init() {
    retrieveIsTransmitData();
    retrieveTransmitMethod();
    retrieveIsMqttTransmitSet();
    if (this->isMqttTransmitSet)
        retrieveMqttTransmitSetting();
}

void DataTransmitManager::restoreDefault() {
    this->isTransmitData = false;
    this->isMqttTransmitSet = false;
    this->transmitMethod = TransmitConstant::TransmitMethod::MqttMode;
    this->mqttTransmitSetting = MqttTransmitSetting();
    storeIsTransmitData();
    storeIsMqttTransmitSet();
    storeTransmitMethod();
    storeMqttTransmitSetting();
}

void DataTransmitManager::setIsTransmitData(bool isTransmitData) {
    this->isTransmitData = isTransmitData;
    storeIsTransmitData();
}

void DataTransmitManager::setTransmitMethod(TransmitConstant::TransmitMethod method) {
    this->transmitMethod = method;
    storeTransmitMethod();
}

void DataTransmitManager::setMqttTransmitSetting(MqttTransmitSetting mqttTransmitSetting) {
    this->mqttTransmitSetting = mqttTransmitSetting;
    this->isMqttTransmitSet = true;
    storeMqttTransmitSetting();
    storeIsMqttTransmitSet();
}

bool DataTransmitManager::getIsTransmitData() {
    return this->isTransmitData;
}

bool DataTransmitManager::getIsMqttTransmitSet() {
    return this->isMqttTransmitSet;
}

TransmitConstant::TransmitMethod DataTransmitManager::getTransmitMethod() {
    return this->transmitMethod;
}

MqttTransmitSetting DataTransmitManager::getMqttTransmitSetting() {
    return this->mqttTransmitSetting;
}

// private

void DataTransmitManager::storeIsTransmitData() {
    BooleanData data(
        this->isTransmitData,
        StorageLocation(
            IS_TRANSMIT_DATA_LENGTH,
            IS_TRANSMIT_DATA_STORE_INDEX
        )
    );
    Storage::set(data);
}

void DataTransmitManager::storeIsMqttTransmitSet() {
    BooleanData data(
        this->isMqttTransmitSet,
        StorageLocation(
            IS_MQTT_TRANSMIT_SET_LENGTH,
            IS_MQTT_TRANSMIT_SET_STORE_INDEX
        )
    );
    Storage::set(data);
}

void DataTransmitManager::retrieveIsTransmitData() {
    BooleanData data(StorageLocation(
        IS_TRANSMIT_DATA_LENGTH,
        IS_TRANSMIT_DATA_STORE_INDEX
    ));
    Storage::get(data);
    this->isMqttTransmitSet = data.getData();
}

void DataTransmitManager::retrieveIsMqttTransmitSet() {
    BooleanData data(StorageLocation(
        IS_MQTT_TRANSMIT_SET_LENGTH,
        IS_MQTT_TRANSMIT_SET_STORE_INDEX
    ));
    Storage::get(data);
    this->isMqttTransmitSet = data.getData();
}

void DataTransmitManager::storeMqttTransmitSetting() {
    UCharArrayData mqttServerIpData(
        this->mqttTransmitSetting.getMqttServerIp(),
        StorageLocation(
            MQTT_TRANSMIT_SERVER_IP_LENGTH,
            MQTT_TRANSMIT_SERVER_IP_STORE_INDEX
        )
    );
    Storage::set(mqttServerIpData);

    UInt16Data mqttServerPortData(
        this->mqttTransmitSetting.getMqttServerPort(),
        StorageLocation(
            MQTT_TRANSMIT_SERVER_PORT_LENGTH,
            MQTT_TRANSMIT_SERVER_PORT_STORE_INDEX
        )
    );
    Storage::set(mqttServerPortData);
}

void DataTransmitManager::retrieveMqttTransmitSetting() {
    StorageLocation mqttServerIpLocation = StorageLocation(
        MQTT_TRANSMIT_SERVER_IP_LENGTH,
        MQTT_TRANSMIT_SERVER_IP_STORE_INDEX
    );
    UCharArrayData mqttServerIpData(mqttServerIpLocation);
    Storage::get(mqttServerIpData);

    StorageLocation mqttServerPortLocation = StorageLocation(
        MQTT_TRANSMIT_SERVER_PORT_LENGTH,
        MQTT_TRANSMIT_SERVER_PORT_STORE_INDEX
    );
    UInt16Data mqttServerPortData(mqttServerPortLocation);
    Storage::get(mqttServerPortData);

    this->setMqttTransmitSetting(MqttTransmitSetting(
        mqttServerIpData.getData(),
        mqttServerPortData.getData()
    ));
}

void DataTransmitManager::storeTransmitMethod() {
    UInt8Data data(
        this->transmitMethod,
        StorageLocation(
            TRANSMIT_METHOD_LENGTH,
            TRANSMIT_METHOD_STORE_INDEX
        )
    );
    Storage::set(data);
}

void DataTransmitManager::retrieveTransmitMethod() {
    UInt8Data data(StorageLocation(
        TRANSMIT_METHOD_LENGTH,
        TRANSMIT_METHOD_STORE_INDEX
    ));
    Storage::get(data);
    this->transmitMethod = static_cast<TransmitConstant::TransmitMethod>(data.getData());
}