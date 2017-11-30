/*
 * robot arm loop 
 */

#include <Servo.h> 
Servo clawServo, horizontalServo, verticalServo, rotateServo, ballServo;

int delayTime = 30;
int ballValue = 0;
int clawValue = 0;
int horizontalValue = 0;
int verticalValue = 0;
int rotateValue = 0;

void setup() {
  ballServo.attach(12);
  clawServo.attach(8);
  horizontalServo.attach(9);
  verticalServo.attach(10);
  rotateServo.attach(11);
  //Setup usb serial connection to computer
  Serial.begin(9600);

}

void loop() {
  homeServo(90);
  ballValue = moveServo(ballServo, ballValue, -52);
  // hold ball
  rotateValue = moveServo(rotateServo, rotateValue, 24);
  clawValue = moveServo(clawServo, clawValue, 25);
  horizontalValue = moveServo(horizontalServo, horizontalValue, -46);
  verticalValue = moveServo(verticalServo, verticalValue,30);
  clawValue = moveServo(clawServo, clawValue, -17);

  // fall ball
  horizontalValue = moveServo(horizontalServo, horizontalValue, 5);
  verticalValue = moveServo(verticalServo, verticalValue,-10);
  horizontalValue = moveServo(horizontalServo, horizontalValue, 80);
  rotateValue = moveServo(rotateServo, rotateValue, -43);
  verticalValue = moveServo(verticalServo, verticalValue,10);
  clawValue = moveServo(clawServo, clawValue, 10);

  //  // initial home
  rotateValue = moveServo(rotateServo, rotateValue, 20);
  verticalValue = moveServo(verticalServo, verticalValue,-28);
  horizontalValue = moveServo(horizontalServo, horizontalValue, -37);

}

void homeServo(int moveValue) {
  ballValue = moveValue;
  clawValue = moveValue;
  horizontalValue = moveValue;
  verticalValue = moveValue;
  rotateValue = moveValue;

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

int moveServo(Servo servo, int moveFromValue, int stepValue){
  int toValue = moveFromValue + stepValue;
  int pos = 0;
  
  if(stepValue >= 0){
    for(pos=moveFromValue; pos <= toValue; pos += 1){
      servo.write(pos);
      delay(15);
    }
  } else {
    for(pos=moveFromValue; pos >= toValue; pos -= 1){
      servo.write(pos);
      delay(15);
    }
  }

  return toValue;
}

