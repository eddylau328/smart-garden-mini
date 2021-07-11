#ifndef TransmitterController_h
#define TransmitterController_h

#include "MqttTransmitter/MqttTransmitter.h"
#include "DataTransmitter.h"
#include "TransmitConstant.h"

class TransmitterController {

    public:
        static void init();

    private:
        static TaskHandle_t transmitMainLoop;
        static void mainLoop(void * pvParameters );
        static DataTransmitter *transmitter;

        static TransmitConstant::TransmitMethod transmitMethod;
        static void updateTransmitMethod(TransmitConstant::TransmitMethod method);

        class TransmitterFactory {
            public:
                static DataTransmitter* create(TransmitConstant::TransmitMethod method);
                static void destroy(DataTransmitter *transmitter);
        };
};

#endif