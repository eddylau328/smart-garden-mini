#include "DataTransmitter.h"

void DataTransmitter::init() {}
void DataTransmitter::mainLoop() {}
void DataTransmitter::disconnect() {}

void DataTransmitter::send(TransmitAction::SendAction actionType) {
    JsonParser *parser = this->getJsonParser(actionType);
    switch (actionType) {
        case TransmitAction::SendAction::SensorData:
            this->sendSensorData(parser);
            break;
        case TransmitAction::SendAction::Init:
            this->sendInit(parser);
            break;
        default:
            break;
    }
    delete parser;
}

bool DataTransmitter::getIsEnableTransmission() {
    return isEnableTransmission;
}
void DataTransmitter::setIsEnableTransmission(bool isEnable) {
    isEnableTransmission = isEnable;
}

// protected
void DataTransmitter::sendInit(JsonParser *parser) {}
void DataTransmitter::sendSensorData(JsonParser *parser) {}


// privated
JsonParser* DataTransmitter::getJsonParser(TransmitAction::SendAction actionType) {
    switch(actionType) {
        case TransmitAction::SendAction::Init:
            return new InitJsonParser();
        case TransmitAction::SendAction::SensorData:
            return new SensorJsonParser(); 
        default:
            return NULL;
    }
}