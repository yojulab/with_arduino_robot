#include <Servo.h>

Servo myservo;  
int pos = 0;  

void setup() {
  // put your setup code here, to run once:
  myservo.attach(4);
}

void loop() {
  // put your main code here, to run repeatedly:
//    myservo.write(map(analogRead(A0),0,1023,0,120));
    delay(15);

  // put your main code here, to run repeatedly:
  for(pos=0; pos < 120; pos += 1){
    myservo.write(pos);
    delay(15);
  }
}
