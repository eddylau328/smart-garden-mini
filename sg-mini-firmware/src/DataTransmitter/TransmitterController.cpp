#include "TransmitterController.h"


DataTransmitter *TransmitterController::transmitter;
TaskHandle_t TransmitterController::transmitMainLoop;
TransmitConstant::TransmitMethod TransmitterController::transmitMethod;


void TransmitterController::init() {
    DataTransmitManager *manager = DeviceManager::getDataTransmitManager();
    updateTransmitMethod(manager->getTransmitMethod());

    xTaskCreatePinnedToCore(
                mainLoop,   /* Task function. */
                "transmitMainLoop",     /* name of task. */
                9999,       /* Stack size of task */
                NULL,        /* parameter of the task */
                1,           /* priority of the task */
                &transmitMainLoop,      /* Task handle to keep track of created task */
                0);          /* pin task to core 0 */   
}

void TransmitterController::mainLoop(void * pvParameters ) {
    const TickType_t xDelay = 2000 / portTICK_PERIOD_MS;
    DataTransmitManager *manager = DeviceManager::getDataTransmitManager();
    while (true) {
        if (manager->getIsTransmitData()) {
            if (manager->getTransmitMethod() != transmitMethod)
                updateTransmitMethod(manager->getTransmitMethod());
            transmitter->mainLoop();
        }
        vTaskDelay(xDelay);
    }
}

void TransmitterController::updateTransmitMethod(TransmitConstant::TransmitMethod method) {
    if (transmitter) {
        transmitter->disconnect();
        TransmitterFactory::destroy(transmitter);
    }
    transmitMethod = method;
    transmitter = TransmitterFactory::create(transmitMethod);
    transmitter->init();
}

DataTransmitter* TransmitterController::TransmitterFactory::create(TransmitConstant::TransmitMethod method) {
    switch (method) {
        case TransmitConstant::TransmitMethod::MqttMode:
            return new MqttTransmitter();
        default:
            return new DataTransmitter();
    }
}

void TransmitterController::TransmitterFactory::destroy(DataTransmitter *transmitter) {
    delete transmitter;
}