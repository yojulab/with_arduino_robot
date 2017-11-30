const int buzzer = 10; //buzzer to arduino pin 10


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 10 as an output

}

void loop(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  
}
