#include <SparkFun_I2C_Mux_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_I2C_Mux
QWIICMUX myMux;

#define NUMBER_OF_SENSORS 6

#include <Wire.h>

#include "SparkFun_SCD30_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_SCD30
SCD30 airSensor;

void setup() 
{

  //Disable all eight mux ports initially, then we can enable them one at a time
  for (byte x = 0 ; x <= 7 ; x++)
  {
    myMux.disablePort(x);
  }

  //Initialize all the sensors
  for (byte x = 0 ; x < NUMBER_OF_SENSORS ; x++)
  {
    myMux.enablePort(x); //Tell mux to connect to port X

    
    Serial.begin(115200);
    Serial.println("SCD30 Example");
    Wire.begin();

    if (airSensor.begin() == false)
    {
    Serial.println("Air sensor not detected. Please check wiring. Freezing...");
    Serial.println(x);
    while (1)
      ;
    }

    
    Serial.print("Initialized. Sensor number: ");
    Serial.println(x);
    
    myMux.disablePort(x); //Tell mux to disconnect to port X
  }
}

void loop() 
{

}
