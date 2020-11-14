//Testing code for all sensor for smartgarden mini (ESP32 dev Kit V1) on breadboard

//-------------Soil Temperature DS18B20-------------
#include <OneWire.h>
#include <DallasTemperature.h>
#define DS18B20PIN 33  
OneWire oneWire(DS18B20PIN);
DallasTemperature sensors(&oneWire);
float temperatureC;
float temperatureF;

//-------------Soil humid-------------
#define soilhumidPIN 14
const int AirValue = 3600;   //you need to replace this value with Value_1
const int WaterValue = 1260;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;


#include <SPI.h>
#include <SD.h>
const int cs = 10;

//-------------DHT sensor-------------
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 13
#define DHTTYPE DHT12  //match to version
DHT dht(DHTPIN, DHTTYPE);
float h;
float t; 
float f;

//-------------LCD 1602 I2C-------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//-------------Ultrasound sensor-------------
#define trigPin 32
#define echoPin 35
long duration;
float distance;

//-------------INA219 I2C Current sensor-------------
#include <Wire.h>
#include <INA219_WE.h>
#define I2C_ADDRESS 0x40
INA219_WE ina219(I2C_ADDRESS);


//-------------GY49 lux sensor------------
#include <Max44009.h>
Max44009 myLux(0x4A);
float lux=0;

//-------------Knob---------------------
#define clk_knob 36
#define dt_knob 39
#define sw_knob 34
int rotateflag = 0;
bool pressing = false;
int countpos = 0;

File datafile;  // for SD card file 
#define pumpen 4 //Pumpenable Pin 

#include <DS1307.h> // Real Time Clock
DS1307 rtc;

long lastclock;

//---------------------------------------SET UP--------------------------------------------------------------------
void setup() {
  // put your setup code here, to run once:
  lastclock = millis();
  
  Serial.begin(9600);
  Wire.begin();
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");

  pinMode(trigPin, OUTPUT);// Ultra Sound pin setting
  pinMode(echoPin, INPUT);
  pinMode(pumpen,OUTPUT);
  
  pinMode(clk_knob,INPUT);// Knob pin setting
  pinMode(dt_knob,INPUT);
  pinMode(sw_knob,INPUT);
  
  pinMode(12, OUTPUT); //On board LED

  digitalWrite(pumpen,HIGH); // Pull high pump enable pin to close pump 
  attachInterrupt(digitalPinToInterrupt(clk_knob), rotate, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(sw_knob), push, RISING);

  if(!ina219.init())  // INA init
    Serial.println("INA219 not connected!");
    else
    {
    ina219.setADCMode(SAMPLE_MODE_128);
    ina219.setMeasureMode(CONTINUOUS);
    }

  rtc.begin(); // Real time Clock setting
  rtc.fillByYMD(2020, 11, 5); //Jan 19,2013
  rtc.fillByHMS(15, 28, 30); //15:28 30"
  rtc.fillDayOfWeek(SAT);//Saturday
  rtc.setTime();//write time to the RTC chip

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
  digitalWrite(12,!digitalRead(12)); //Blinking LED
  
/*  if(rotateflag == 100)
    {
    Serial.print("New countpos is:");
    Serial.println(countpos);
    for( ;rotateflag>0;rotateflag--);
    }

  if(pressing == true)
    {
    Serial.println("Pressed!");
    pressing = false;
    }
  delay(200);
*/
  if(millis() - lastclock >= 2000){ 
  printTime();
  getdht();
  getlux();
  soilhumid();
  soiltemp();
  ultrasound();
  ina();
  

  lastclock = millis();
  Serial.println();
  }
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

void getdht(){
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f))
  Serial.println(F("Failed to read from DHT sensor!"));
  else{
    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false);
    Serial.print(F("air Humidity: "));
    Serial.print(h);
    Serial.print(F("%   air Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  air Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
  }
}
  
void soilhumid(){
  soilMoistureValue = analogRead(soilhumidPIN);  //put Sensor insert into soil
  Serial.print("soil humidity: ");
  Serial.print(soilMoistureValue);
  Serial.print(" ");
  soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
  if(soilmoisturepercent > 100)
    Serial.println("100 %");
  else if(soilmoisturepercent <0)
    Serial.println("0 %");
  else if(soilmoisturepercent >0 && soilmoisturepercent < 100){
    Serial.print(soilmoisturepercent);
    Serial.println("%"); }
  }

void soiltemp(){
  sensors.requestTemperatures(); 
  temperatureC = sensors.getTempCByIndex(0);
  temperatureF = sensors.getTempFByIndex(0);
  Serial.print("Soil temp: ");
  Serial.print(temperatureC);
  Serial.print("ºC ");
  Serial.print(temperatureF);
  Serial.println("ºF");
  }

void ina(){
  float shuntVoltage_mV = 0.0;
  float loadVoltage_V = 0.0;
  float busVoltage_V = 0.0;
  float current_mA = 0.0;
  float power_mW = 0.0; 
  bool ina219_overflow = false;
  
  shuntVoltage_mV = ina219.getShuntVoltage_mV();
  busVoltage_V = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getBusPower();
  loadVoltage_V  = busVoltage_V + (shuntVoltage_mV/1000);
  
  Serial.print("Shunt Voltage [mV]: "); Serial.print(shuntVoltage_mV);
  Serial.print("  Bus Voltage [V]: "); Serial.print(busVoltage_V);
  Serial.print("  Load Voltage [V]: "); Serial.print(loadVoltage_V);
  Serial.print("  Current[mA]: "); Serial.print(current_mA);
  Serial.print("  Bus Power [mW]: "); Serial.println(power_mW);

  }
  
void ultrasound(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  Serial.print("Distance: ");
  Serial.println(distance);
  }

void getlux(){
    lux = myLux.getLux();
    int err = myLux.getError();
    if (err != 0)
    {
      Serial.print("Error:\t");
      Serial.println(err);
    }
    else
    {
      Serial.print("lux:\t");
      Serial.println(lux);
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
