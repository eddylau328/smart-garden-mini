//Testing code for all sensor for smartgarden mini (ESP32 dev Kit V1) on breadboard

// File datafile;  // for SD card file 
#define pumpen 4 //Pumpenable Pin 

#include <DS1307.h> // Real Time Clock
DS1307 rtc;

long lastclock;

#include "src/Config/Config.h"
#include "src/LcdDisplayUI/LcdDisplayUI.h"
#include "src/LcdDisplayUI/PageControl.h"
#include "src/Sensors/Sensors.h"
#include "src/LcdDisplayUI/RotaryEncoder.h"
#include "src/DeviceSetting/DeviceSetting.h"

Sensors sensors;
LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);

char name[4] = {'E', 'd', 'd', 'y'};

//---------------------------------------SET UP--------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  lastclock = millis();
  
  Serial.begin(9600);
  LOG_SET_LEVEL(DebugLogLevel::ERRORS); // all log is printed
  
  DeviceSetting::init();
  DeviceSetting::setUserName(name, 4);

  pinMode(12, OUTPUT); //On board LED

  digitalWrite(pumpen,HIGH); // Pull high pump enable pin to close pump 

  rtc.begin(); // Real time Clock setting
  rtc.fillByYMD(2020, 11, 5); //Jan 19,2013
  rtc.fillByHMS(15, 28, 30); //15:28 30"
  rtc.fillDayOfWeek(SAT);//Saturday
  rtc.setTime();//write time to the RTC chip

  sensors.init();
  pageControl.init(&sensors);
  pageControl.initInput(&rotaryEncoder);
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
  
  // if(millis() - lastclock >= 5000){ 
  //   printTime();
  //   sensors.read();
  //   lastclock = millis();
  // }
  pageControl.mainLoop();
  display.render();
  if (millis() - lastclock > 2000) {
    sensors.read();
    lastclock = millis();
  }
  
}

void printTime() {
    rtc.getTime();
    Serial.print(rtc.hour, DEC);
    Serial.print(":");
    Serial.print(rtc.minute, DEC);
    Serial.print(":");
    Serial.print(rtc.second, DEC);
    Serial.print("  ");
    Serial.print(rtc.month, DEC);
    Serial.print("/");
    Serial.print(rtc.dayOfMonth, DEC);
    Serial.print("/");
    Serial.print(rtc.year + 2000, DEC);
    Serial.print(" ");
    Serial.print(rtc.dayOfMonth);
    Serial.print("*");
    switch (rtc.dayOfWeek) { // Friendly printout the weekday
        case MON:
            Serial.print("MON");
            break;
        case TUE:
            Serial.print("TUE");
            break;
        case WED:
            Serial.print("WED");
            break;
        case THU:
            Serial.print("THU");
            break;
        case FRI:
            Serial.print("FRI");
            break;
        case SAT:
            Serial.print("SAT");
            break;
        case SUN:
            Serial.print("SUN");
            break;
    }
    Serial.println(" ");
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
