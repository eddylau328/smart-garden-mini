// File datafile;  // for SD card file 
#include "src/Config/Config.h"
#include "src/LcdDisplayUI/LcdDisplayUI.h"
#include "src/LcdDisplayUI/PageControl.h"
#include "src/Sensors/Sensors.h"
#include "src/LcdDisplayUI/RotaryEncoder.h"
#include "src/WifiController/WifiController.h"
#include "src/WaterController/WaterController.h"
#include "src/DeviceSetting/DeviceManager.h"
#include "src/Storage/Storage.h"


LcdDisplayUI display(LCDScreenWidth, LCDScreenHeight);
PageControl pageControl(&display);
RotaryEncoder rotaryEncoder(DT_PIN, CLK_PIN, SW_PIN, 10);


//---------------------------------------SET UP--------------------------------------------------------------------
void init() {
  Storage::init();
  WaterController::init();

  DeviceManager::init();
  WifiController::init();
  Sensors::init();

  pageControl.init();
  pageControl.initInput(&rotaryEncoder);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  LOG_SET_LEVEL(DebugLogLevel::ERRORS); // all log is printed
  init();
  
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
  pageControl.mainLoop();
  display.render();
  Sensors::mainLoop();
  WaterController::mainLoop();
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
