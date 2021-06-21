//#include <Wire.h>
byte statusLed    = 13;
byte sensorInterrupt = 0;
byte sensorPin       = 2;
float calibrationFactor = 4.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
String fml = "";
void setup()
{
 // Wire.begin(9);
  //Wire.onRequest(requestEvent);
  Serial.begin(9600);
  pinMode(statusLed, OUTPUT);
  digitalWrite(statusLed, HIGH);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  oldTime           = 0;
  attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}
void loop()
{
   
   if((millis() - oldTime) > 1000)
  { 
    detachInterrupt(sensorInterrupt);
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    flowMilliLitres = (flowRate / 60) * 1000;
    fml = (String)flowMilliLitres + "";
    oldTime = millis();
    unsigned int frac;
    Serial.println((String)flowMilliLitres); 
    pulseCount = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
  }
}
void pulseCounter(){pulseCount++;}
/*void requestEvent() {
char buf[3];
   fml.toCharArray(buf, 3);
  Wire.write(buf);
}
*/
