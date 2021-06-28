#ifndef TransmitterController_h
#define TransmitterController_h

#include "MqttTransmitter/MqttTransmitter.h"
#include "DataTransmitter.h"

class TransmitterController {

    public:
        static void init();

    private:
        static TaskHandle_t transmitMainLoop;
        static void mainLoop(void * pvParameters );
        static DataTransmitter *transmitter;

};

#endif