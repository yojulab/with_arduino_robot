/*
base info from https://www.arduino.cc/en/Reference/Servo
test sketch made by Nicu FLORICA (niq_ro) for verify position for Otto legs  
*/
#include <Servo.h>

Servo myservo1;  // create servo object to control a servo 1
Servo myservo2;  // create servo object to control a servo 2
Servo myservo3;  // create servo object to control a servo 3
Servo myservo4;  // create servo object to control a servo 4

int minim = 30;
int middle = 90;
int maxim = 150;
int delayTime = 3000;

void setup() {
  // Legs
  myservo1.attach(2);  // attaches the servo on pin 2 to the servo object 1
  myservo2.attach(3);  // attaches the servo on pin 3 to the servo object 2 

  // Foots
  myservo3.attach(4);  // attaches the servo on pin 4 to the servo object 3
  myservo4.attach(5);  // attaches the servo on pin 5 to the servo object 4 

  // Legs
  delay(delayTime);
  myservo1.write(middle);                  // sets the servo 1 position 
  delay(delayTime);
  myservo2.write(middle);                  // sets the servo 2 position

  // Foots
  delay(delayTime);
  myservo3.write(middle);                  // sets the servo 3 position 
  delay(delayTime);
  myservo4.write(middle);                  // sets the servo 4 position
  
}

void loop() {
/*
  // Leg
  myservo1.write(minim);                  // sets the servo 1 position 
  myservo2.write(minim);                  // sets the servo 2 position
  delay(delayTime);
  myservo1.write(maxim);                  // sets the servo 1 position 
  myservo2.write(maxim);                  // sets the servo 2 position
  delay(delayTime);
  myservo1.write(middle);                  // sets the servo 1 position 
  myservo2.write(middle);                  // sets the servo 2 position
  delay(delayTime);

  // Foot
  myservo3.write(minim);                  // sets the servo 3 position 
  myservo4.write(minim);                  // sets the servo 4 position
  delay(delayTime);
  myservo3.write(maxim);                  // sets the servo 3 position 
  myservo4.write(maxim);                  // sets the servo 4 position
  delay(delayTime);
  myservo3.write(middle);                  // sets the servo 3 position 
  myservo4.write(middle);                  // sets the servo 4 position
  delay(delayTime);
*/
}

