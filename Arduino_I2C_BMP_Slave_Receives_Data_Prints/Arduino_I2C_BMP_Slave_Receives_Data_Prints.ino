#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

Adafruit_BMP280 bme;

String txdata = "";
  
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  
  if (!bme.begin(0x76)) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
  
void loop() {
   txdata = (String)bme.readTemperature()+" "+(String)bme.readPressure()+" "+(String)bme.readAltitude(1013.25);
   //Serial.println(txdata);
   //Serial.println(txdata.length());
   
   delay(100);
}

void requestEvent() {
char buf[21];
   txdata.toCharArray(buf, 21);
   Serial.println(txdata);
  Wire.write(buf);
}
