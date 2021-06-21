#include <Wire.h>
String c = "";
int dlen = 21, dlen2=3;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  Wire.requestFrom(8, dlen);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
     
  c += (char)Wire.read();         // print the character
  if(c.length()>= dlen){
    Serial.println(c);
    c = "";
  }
  Wire.requestFrom(9, dlen2);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
     
  c += (char)Wire.read();         // print the character
  if(c.length()>= dlen2){
    Serial.println(c);
    c = "";
  }
  }

  delay(500);
}}
