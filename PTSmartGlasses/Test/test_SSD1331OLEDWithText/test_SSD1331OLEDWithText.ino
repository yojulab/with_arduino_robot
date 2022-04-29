/*************************************************** 
  This is a example sketch demonstrating the graphics
  capabilities of the SSD1331 library  for the 0.96" 
  16-bit Color OLED with SSD1331 driver chip

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/684

  These displays use SPI to communicate, 4 or 5 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/


// You can use any (4 or) 5 pins 
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8


// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>

#define buttonPin 2
// Option 1: use any pins but a little slower
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);  

// Option 2: must use the hardware SPI pins 
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be 
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
//Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);

char readData;
int buttonState;

void setup(void) {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  display.begin();

  Serial.println("init");
  display.fillScreen(MAGENTA);
  display.setTextSize(2);
      display.setTextColor(BLACK);
}

short cnt = 0;
void loop() {
//  buttonState = digitalRead(buttonPin);
//    Serial.print("buttonState : ");
//    Serial.println(buttonState);
//  if (buttonState == HIGH) {
//    Serial.write("+");
//    display.fillScreen(WHITE);
//    display.setCursor(1, 23);
//    display.setTextColor(BLACK);
//    Serial.flush();
////    delay(300);  
//  }
  
  if (Serial.available()) {
    readData = Serial.read();
    display.fillScreen(WHITE);
    display.setCursor(1, 23);
    display.print(cnt++);
    display.print(readData);
//    Serial.flush();
  }
}
