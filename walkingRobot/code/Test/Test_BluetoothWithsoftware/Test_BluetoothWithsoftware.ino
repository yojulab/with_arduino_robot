#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9); // TX --> 8 | RX --> 9
void setup(){
  Serial.begin(9600);  
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Available Serial !");

  BTSerial.begin(9600);
  Serial.println("Available BTSerial !");
  
}
void loop(){
// BT –> Data –> Serial
  if (BTSerial.available()) { 
    Serial.write(BTSerial.read());
  }
// Serial –> Data –> BT
  if (Serial.available()) {   
    BTSerial.write(Serial.read());
  }
}
