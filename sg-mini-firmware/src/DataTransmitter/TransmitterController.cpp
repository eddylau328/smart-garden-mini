#include "TransmitterController.h"


DataTransmitter *TransmitterController::transmitter;
TaskHandle_t TransmitterController::transmitMainLoop;


void TransmitterController::init() {
    transmitter = new MqttTransmitter();
    transmitter->init();

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
    while (true) {
        transmitter->mainLoop();
        vTaskDelay(xDelay);
    }
}