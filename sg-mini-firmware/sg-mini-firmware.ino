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

LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);
Controller controller;

//---------------------------------------SET UP--------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  lastclock = millis();

  Serial.begin(9600);
  LOG_SET_LEVEL(DebugLogLevel::ERRORS); // all log is printed
  
  DeviceSetting::init();
  WifiController::init();

  pinMode(12, OUTPUT); //On board LED

  digitalWrite(pumpen,HIGH); // Pull high pump enable pin to close pump 

  Sensors::init();
  pageControl.init();
  pageControl.initInput(&rotaryEncoder);

  controller.init();
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
