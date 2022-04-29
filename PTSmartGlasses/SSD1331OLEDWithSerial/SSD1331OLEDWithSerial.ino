/*************************************************** 
  This is a example sketch demonstrating bitmap drawing
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

  The Adafruit GFX Graphics core library is also required
  https://github.com/adafruit/Adafruit-GFX-Library
  Be sure to install it!
 ****************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>


// If we are using the hardware SPI interface, these are the pins (for future ref)
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8

// Color definitions
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

#define WIDTH      96
#define HEIGHT     64

// to draw images from the SD card, we will share the hardware SPI interface
Adafruit_SSD1331 tft = Adafruit_SSD1331(cs, dc, rst);  

// For Arduino Uno/Duemilanove, etc
//  connect the SD card with MOSI going to pin 11, MISO going to pin 12 and SCK going to pin 13 (standard)
//  Then pin 4 goes to CS (or whatever you have set up)
#define SD_CS 4    // Set the chip select line to whatever you use (4 doesnt conflict with the library)


void setup(void) {
  Serial.begin(115200);
   
  pinMode(cs, OUTPUT);
  digitalWrite(cs, HIGH);
     
  // initialize the OLED
  tft.begin();

  Serial.println("init");

  tft.fillScreen(WHITE);

  delay(500);

}

short row=0, col=0;
uint16_t readData;
void loop() {
  Serial.println("display reading .....");
  if (Serial.available()) {
    readData = Serial.read();
    tft.goTo(col, row);
    tft.pushColor(readData);
    if(col++ >= WIDTH){
      col = 0;
      row++;
    }
    if(row >= HEIGHT){
      row = 0;
      col = 0;
      tft.fillScreen(YELLOW);
    }
    Serial.print("display write ..... readData : ");
    Serial.print(readData);
    Serial.print(" / row : ");
    Serial.print(row);
    Serial.print(" / col : ");
    Serial.println(col);
  }
}



