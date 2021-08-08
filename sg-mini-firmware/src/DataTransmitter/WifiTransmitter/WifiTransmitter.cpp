#include "WifiTransmitter.h"

void WifiTransmitter::sendSensorData(JsonParser *parser) {
    if (WifiController::isConnectedNetwork()) {
        // HTTPClient http;
        // // Your Domain name with URL path or IP address with path
        // http.begin(serverName);
        // // Specify content-type header
        // http.addHeader("Content-Type", "application/json");

        // String postData;
        // JsonParser::writeSensorData(postData);
        // Serial.print(postData);
        // Serial.println();
        // int httpResponseCode = http.POST(postData);
        // Serial.print("HTTP Response code: ");
        // Serial.println(httpResponseCode);
        // // Free resources
        // http.end();
    }
}