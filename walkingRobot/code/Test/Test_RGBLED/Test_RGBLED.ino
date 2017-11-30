// RED LED를 디지털 13번 핀에 연결합니다.
const int RED_PIN = 13;
// GREEN LED를 디지털 12번 핀에 연결합니다.
const int GREEN_PIN = 12;
// BLUE LED를 디지털 11번 핀에 연결합니다.
const int BLUE_PIN = 11;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
void setup() {
  // 11번 핀을 출력으로 설정 합니다.
  pinMode(RED_PIN, OUTPUT);    
  // 10번 핀을 출력으로 설정 합니다.
  pinMode(GREEN_PIN, OUTPUT); 
  // 9번 핀을 출력으로 설정 합니다.
  pinMode(BLUE_PIN, OUTPUT);      
}

// setup() 함수가 호출된 이후, loop() 함수가 호출되며,
// 블록 안의 코드를 무한히 반복 실행합니다.
void loop() {
  // RGB LED로 빨간색 불빛을 출력합니다.
  // RED LED를 ON 시킵니다.
  digitalWrite(RED_PIN,HIGH);  
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);

  // 2초 대기합니다.
  delay(2000);                   

  // RGB LED로 초록색 불빛을 출력합니다.
  digitalWrite(RED_PIN,LOW);
  // GREEN LED를 ON 시킵니다.
  digitalWrite(GREEN_PIN,HIGH);    
  digitalWrite(BLUE_PIN,LOW);
 
  // 2초 대기합니다.
  delay(2000);

  // RGB LED로 파란색 불빛을 출력합니다.
  digitalWrite(RED_PIN,LOW);
  digitalWrite(GREEN_PIN,LOW);
  //BLUE LED를 ON 시킵니다.
  digitalWrite(BLUE_PIN,HIGH);     

  // 2초 대기합니다.
  delay(2000);

  // RGB LED를 소등합니다.
  // 모든 LED를 OFF 시킵니다.
  digitalWrite(RED_PIN,LOW);      
  digitalWrite(GREEN_PIN,LOW);
  digitalWrite(BLUE_PIN,LOW);   

  // 2초 대기합니다.
  delay(2000);
}
