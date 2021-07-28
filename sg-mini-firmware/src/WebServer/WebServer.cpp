// #include "WebServer.h"


// TaskHandle_t WebServer::webServerMainLoop;
// WiFiServer WebServer::server(WEB_SERVER_PORT);


// void WebServer::init() {
//     xTaskCreatePinnedToCore(
//                 mainLoop,   /* Task function. */
//                 "webServerMainLoop",     /* name of task. */
//                 9999,       /* Stack size of task */
//                 NULL,        /* parameter of the task */
//                 1,           /* priority of the task */
//                 &webServerMainLoop,      /* Task handle to keep track of created task */
//                 0);          /* pin task to core 0 */   
// }

// void WebServer::mainLoop(void * pvParameters ) {
//     const TickType_t xDelay = 2000 / portTICK_PERIOD_MS;
//     while (true) {
//         vTaskDelay(xDelay);
//     }
// }
