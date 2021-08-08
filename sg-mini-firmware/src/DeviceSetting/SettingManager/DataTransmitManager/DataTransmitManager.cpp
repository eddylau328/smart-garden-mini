#include "DataTransmitManager.h"


void DataTransmitManager::init() {
    retrieveIsEnableTransmit();
    retrieveIsTransmitSensorData();
    retrieveTransmitMethod();
    retrieveIsMqttTransmitSet();
    if (this->isMqttTransmitSet)
        retrieveMqttTransmitSetting();
}

void DataTransmitManager::restoreDefault() {
    this->isEnableTransmit = false;
    this->isTransmitSensorData = false;
    this->isMqttTransmitSet = false;
    this->transmitMethod = TransmitConstant::TransmitMethod::MqttMode;
    this->mqttTransmitSetting = MqttTransmitSetting();
    storeIsEnableTransmit();
    storeIsTransmitSensorData();
    storeIsMqttTransmitSet();
    storeTransmitMethod();
    storeMqttTransmitSetting();
}

void DataTransmitManager::setIsEnableTransmit(bool isTransmitData) {
    this->isEnableTransmit = isTransmitData;
    storeIsEnableTransmit();
}

void DataTransmitManager::setIsTransmitSensorData(bool isTransmitSensorData) {
    this->isTransmitSensorData = isTransmitSensorData;
    storeIsTransmitSensorData();
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

bool DataTransmitManager::getIsEnableTransmit() {
    return this->isEnableTransmit;
}

bool DataTransmitManager::getIsTransmitSensorData() {
    return this->isTransmitSensorData;
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

void DataTransmitManager::storeIsEnableTransmit() {
    BooleanData data(
        this->isEnableTransmit,
        StorageLocation(
            IS_ENABLE_TRANSMIT_LENGTH,
            IS_ENABLE_TRANSMIT_STORE_INDEX
        )
    );
    Storage::set(data);
}

void DataTransmitManager::storeIsTransmitSensorData() {
    BooleanData data(
        this->isTransmitSensorData,
        StorageLocation(
            IS_TRANSMIT_SENSOR_DATA_LENGTH,
            IS_TRANSMIT_SENSOR_DATA_STORE_INDEX
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

void DataTransmitManager::retrieveIsEnableTransmit() {
    BooleanData data(StorageLocation(
        IS_ENABLE_TRANSMIT_LENGTH,
        IS_ENABLE_TRANSMIT_STORE_INDEX
    ));
    Storage::get(data);
    this->isMqttTransmitSet = data.getData();
}

void DataTransmitManager::retrieveIsTransmitSensorData() {
    BooleanData data(StorageLocation(
        IS_TRANSMIT_SENSOR_DATA_LENGTH,
        IS_TRANSMIT_SENSOR_DATA_STORE_INDEX
    ));
    Storage::get(data);
    this->isTransmitSensorData = data.getData();
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