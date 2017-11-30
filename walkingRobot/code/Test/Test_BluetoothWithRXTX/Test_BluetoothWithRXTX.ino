/*
 * Note :
 * 1. Don’t upload to Firmware during Turn On BLuetooth Module.
 * 2. Don’t  Connect RX to RX and TX to TX of Bluetooth to arduinoyou 
 * will receive no data , Here TX means Transmit and RX means Receive
 * 
 */

 // TX->TX | RX->RX(Monitor) and TX->RX | RX->TX(Mobile)
String message; //string that stores the incoming message

void setup()
{
  Serial.begin(9600); //set baud rate
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Available Serial !");
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Available Serial !");
}

void loop()
{
  while(Serial.available())
  { //while there is data available on the serial monitor
    message+=char(Serial.read());//store string from serial command
  }
  if(!Serial.available())
  {
    if(message!="")
    { //if data is available
      Serial.println(message); //show the data
      message=""; //clear the data
    }
  }
  delay(5000); //delay
}
    
