/*
 * robot arm loop 
 */

#include <Servo.h> 
Servo clawServo, horizontalServo, verticalServo, rotateServo, ballServo;

void setup() {
  ballServo.attach(12);
  clawServo.attach(8);
  horizontalServo.attach(9);
  verticalServo.attach(10);
  rotateServo.attach(11);
  //Setup usb serial connection to computer
  Serial.begin(9600);
//  checkServo(90);
  checkServo(90);
}

void loop() {
}

void checkServo(int moveValue) {
  int delayTime = 15;
  int ballValue = moveValue;
  int clawValue = moveValue;
  int horizontalValue = moveValue;
  int verticalValue = moveValue;
  int rotateValue = moveValue;

  Serial.print("checkServo : ");
  Serial.println(moveValue);

  delay(delayTime);
  ballServo.write(ballValue);                  // sets the servo 1 position 
  delay(delayTime);
  clawServo.write(clawValue);                  // sets the servo 1 position 
  delay(delayTime);
  horizontalServo.write(horizontalValue);                  // sets the servo 2 position
  delay(delayTime);
  verticalServo.write(verticalValue);                  // sets the servo 2 position
  delay(delayTime);
  rotateServo.write(rotateValue);                  // sets the servo 2 position
  delay(delayTime);
}

