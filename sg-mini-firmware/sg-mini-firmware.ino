//Testing code for all sensor for smartgarden mini (ESP32 dev Kit V1) on breadboard

//-------------LCD 1602 I2C-------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//-------------Knob---------------------
#define clk_knob 36
#define dt_knob 39
#define sw_knob 34
int rotateflag = 0;
bool pressing = false;
int countpos = 0;

// File datafile;  // for SD card file 
#define pumpen 4 //Pumpenable Pin 

#include <DS1307.h> // Real Time Clock
DS1307 rtc;

long lastclock;

#include "src/Sensors/Sensors.h"
#include "src/Controller/Controller.h"

Sensors sensors;
Controller controller;

//---------------------------------------SET UP--------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  lastclock = millis();
  
  Serial.begin(9600);
  LOG_SET_LEVEL(DebugLogLevel::VERBOSE); // all log is printed
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  
  pinMode(clk_knob,INPUT);// Knob pin setting
  pinMode(dt_knob,INPUT);
  pinMode(sw_knob,INPUT);
  
  pinMode(12, OUTPUT); //On board LED

  digitalWrite(pumpen,HIGH); // Pull high pump enable pin to close pump 
  attachInterrupt(digitalPinToInterrupt(clk_knob), rotate, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(sw_knob), push, RISING);

  rtc.begin(); // Real time Clock setting
  rtc.fillByYMD(2020, 11, 5); //Jan 19,2013
  rtc.fillByHMS(15, 28, 30); //15:28 30"
  rtc.fillDayOfWeek(SAT);//Saturday
  rtc.setTime();//write time to the RTC chip

  sensors.init();
  controller.init(&sensors);
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
  controller.update();
}

void rotate(){
  if(rotateflag ==0)
    {
  if(digitalRead(clk_knob) == digitalRead(dt_knob))
      countpos++;
    else
      countpos--;
    rotateflag = 100;
    }
  }
void push(){
  pressing = true;
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
