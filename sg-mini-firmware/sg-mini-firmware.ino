//Testing code for all sensor for smartgarden mini (ESP32 dev Kit V1) on breadboard

// File datafile;  // for SD card file 
#define pumpen 4 //Pumpenable Pin 

unsigned long lastclock;

#include "src/Config/Config.h"
#include "src/LcdDisplayUI/LcdDisplayUI.h"
#include "src/LcdDisplayUI/PageControl.h"
#include "src/Sensors/Sensors.h"
#include "src/LcdDisplayUI/RotaryEncoder.h"
#include "src/DeviceSetting/DeviceSetting.h"
#include "src/Controller/Controller.h"
#include "src/WifiController/WifiController.h"
#include "src/DataTransmitter/MqttTransmitter/MqttTransmitter.h"

LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);
Controller controller;

MqttTransmitter transmitter;

// #include <WiFi.h>


char *ssid = "TP-LINK_953128";
char *pw = "50675098";

unsigned long lastSend;

//---------------------------------------SET UP--------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  lastclock = millis();

  Serial.begin(9600);
  LOG_SET_LEVEL(DebugLogLevel::NONE); // all log is printed
  
  DeviceSetting::init();
  WifiController::init();

  pinMode(12, OUTPUT); //On board LED

  digitalWrite(pumpen,HIGH); // Pull high pump enable pin to close pump 

  Sensors::init();
  pageControl.init();
  pageControl.initInput(&rotaryEncoder);

  controller.init();
  WifiController::connect(ssid, pw);

  // WiFi.mode(WIFI_STA);
  // WiFi.begin(ssid, pw);
  // while (WiFi.status() != WL_CONNECTED) {
  //   Serial.println("Connecting to WiFi..");
  //   delay(500);
  // }

  transmitter.init();
  
// SD card file name create
/*  char filename[] = "data00.txt";
  while(SD.exists(filename)){
    if(filename[5] = '9'){
      filename[5] = '0';
      filename[4]++;
      }
    else filename[5]++;
    }
  File datafile = SD.open(filename,FILE_WRITE);
  if (datafile) {
    Serial.println("SD card initiaseld");
    datafile.println('The DATA of ' +filename);
    datafile.println("Time, ,Soil humidity,Soil Temperature, ,Light level,Air temperature,Air humidity,INA226 ,Bus Voltage,Pump current,Shunt power, ,UntraSound distance");
  }
*/ 
}

void loop() {
  // digitalWrite(12,!digitalRead(12)); //Blinking LED

  pageControl.mainLoop();
  display.render();
  controller.mainLoop();
  Sensors::mainLoop();
  DeviceSetting::mainLoop();
  transmitter.mainLoop();

  if (millis() - lastSend > 100) {
    transmitter.send(TransmitAction::SendAction::SensorData);
    lastSend = millis();
  }
}


/* void sdcard(){
  if (datafile){
   //  datafile.println("Time, ,Soil humidity,Soil Temperature, ,Light level,Air temperature,Air humidity,INA226 ,Bus Voltage,Pump current,Shunt power, ,UntraSound distance")
   datafile.print(millis()/1000,1);
   datafile.print(", ,");
   datafile.print(soilmoisturepercent);
   datafile.print(",");
   datafile.print(temperatureC);
   datafile.print(", ,");
   datafile.print(lux);
   datafile.print(",");
   datafile.print(t);
   datafile.print(",");
   datafile.print(h);
   datafile.print(", ,");
   datafile.print(busVoltage_V);
   datafile.print(",");
   datafile.print(current_mA);
   datafile.print(",");
   datafile.print(power_mW);   
   datafile.print(",");   
   datafile.print(distance,2);
     }
   }
*/
