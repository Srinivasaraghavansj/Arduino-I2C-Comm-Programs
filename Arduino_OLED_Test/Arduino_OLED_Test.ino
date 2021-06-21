#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16




static const unsigned char PROGMEM arduino_logo[] ={
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00011000, B00000000, B00000000,
B00000000, B00000000, B00110100, B00000000, B00000000,
B00000000, B00000000, B01000010, B00000000, B00000000,
B00000000, B00000000, B10011001, B00000000, B00000000,
B00000000, B00000011, B00011000, B11000000, B00000000,
B00000000, B00000110, B00011000, B01100000, B00000000,
B00000000, B00001100, B00000000, B00110000, B00000000,
B00000000, B00011000, B00011000, B00011000, B00000000,
B00000000, B00110000, B00011000, B00001100, B00000000,
B00000000, B00111111, B11111111, B11111100, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000,
};

void setup(){
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  testanimate(arduino_logo, LOGO_WIDTH, LOGO_HEIGHT);
  display.display();
  delay(2000); // Pause for 2 secondstestanimate(logo_bmp, LOGO_WIDTH, LOGO_HEIGHT);
}

void loop(){}
