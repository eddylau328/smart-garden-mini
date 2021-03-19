#include "DataTransmitter.h"

void DataTransmitter::init() {}
void DataTransmitter::mainLoop() {}
void DataTransmitter::send(TransmitAction::SendAction actionType) {}

bool DataTransmitter::getIsEnableTransmission() {
    return isEnableTransmission;
}
void DataTransmitter::setIsEnableTransmission(bool isEnable) {
    isEnableTransmission = isEnable;
}