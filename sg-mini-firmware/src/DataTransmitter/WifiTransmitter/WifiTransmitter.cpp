#include "WifiTransmitter.h"

void WifiTransmitter::listen() {

}

void WifiTransmitter::send(TransmitAction::SendAction actionType) {
    switch(actionType) {
        case TransmitAction::SendAction::SensorData:
            sendSensorData();
            break;
        default:
            break;
    }
}

void WifiTransmitter::sendSensorData() {
    if (WifiController::isConnectedNetwork()) {
        // HTTPClient http;
        // // Your Domain name with URL path or IP address with path
        // http.begin(serverName);
        // // Specify content-type header
        // http.addHeader("Content-Type", "application/json");

        String postData;
        JsonParser::writeSensorData(postData);
        Serial.print(postData);
        Serial.println();
        // int httpResponseCode = http.POST(postData);
        // Serial.print("HTTP Response code: ");
        // Serial.println(httpResponseCode);
        // // Free resources
        // http.end();
    }
}