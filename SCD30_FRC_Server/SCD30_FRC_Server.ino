#include <SparkFun_I2C_Mux_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_I2C_Mux
QWIICMUX myMux;

#define NUMBER_OF_SENSORS 6
#include <ESP32WebServer.h>    //https://github.com/Pedroalbuquerque/ESP32WebServer download and place in your Libraries folder
#include <ESPmDNS.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <Wire.h>
#include <CSS.h>

WiFiClient client;

SCD30 airSensor;


String calibVal = "";
String scount = "";
void frcset() {

  append_page_header();
  webpage += F("<h3>Sensor FRC</h3>"); 
  webpage += F("<FORM action='/get' method='get'>");
  webpage += F("<label for='sensorcount'> choose number of sensors:</label>");
  webpage += F("<select id='sensorcount' name='sensorcount'");

  webpage += F("<option value='1'> 1 </option>");
  webpage += F("<option value='2'> 2 </option>");
  webpage += F("<option value='3'> 3 </option>");
  webpage += F("<option value='4'> 4 </option>");
  webpage += F("<option value='5'> 5 </option>");
  webpage += F("<option value='6'> 6 </option>");
  webpage += F("<option value='7'> 7 </option>");
  webpage += F("<option value='8'> 8 </option>");
  webpage += F("</select>");
  webpage += F("input type='text'name='setCalib' id='setCalib' value='' style='width:25%'>")
  webpage += F("<button class='buttons' style='width:10%' type='submit'>Update</button><br><br>");
  webpage += F("<a href='/'>[Back]</a><br><br>");
  append_page_footer();
  server.send(200, "text/html",webpage);
}

void forceCalibData(int value){

  airSensor.setForcedRecalibrationFactor(value);
  server.send(200, "text/plain", "Calibration Set Successfully");
}
void connectWiFi() 
{
WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
WiFi.setHostname(hostname.c_str()); //define hostname

WiFi.begin(ssid, pass);
Serial.println("Connecting");

while(WiFi.status() != WL_CONNECTED) 
{
delay(1000);
Serial.print(".");
wifiTime++;
if (wifiTime > 20)
{
Serial.println("WiFi not connected. Locally logged");
}
}
Serial.println("");
Serial.print("Connected to WiFi network with IP Address: ");
Serial.println(WiFi.localIP());
}

void dataTransfer()
{
  
// u8g2.clearBuffer();
// u8g2.drawStr(3, 15, "FTP Enabled"); 
// u8g2.sendBuffer(); 

if(WiFi.status() != WL_CONNECTED)
{
connectWiFi(); 

server.on("/setTime",  frcset);
server.on("/get", HTTP_GET,[](){
 
  
   
      server.send(200, "text/plain", "Calibration is in process... Please wait for the Status");
    
      Serial.println(server.arg(0));
      Serial.println(server.arg(1));
      scount = server.arg(0);
      calibVal = server.arg(1);
      Serial.println(server.arg(0));
      Serial.println(server.arg(1));
      int calibValues = atoi(calibVal.c_str());
      forceCalibData(calibValues);

    
    });
server.on("/fupload",  HTTP_POST,[](){ server.send(200);}, handleFileUpload);
server.begin();

//Set your preferred server name, if you use "mcserver" the address would be http://mcserver.local/
/*if (!MDNS.begin(servername)) 
{          
Serial.println(F("Error setting up MDNS responder!")); 
ESP.restart(); 
}*/
}
for(;;){
server.handleClient();
}
}

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
