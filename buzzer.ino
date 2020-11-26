// 분갈이모듈
int SW_POT = 13;

// play_music모듈 변수
int BUZZER = 12; //스피커가 연결된 디지털핀 설정
int note[] = {2093,2349,2637,2793,3136,3520,3951,4186}; //도레미파솔라시도
int music[] = {3136,3136,2637,2093,2093,3136,3136,2793,2793,2349,2349,2349,2349,2349,2349,
              2793,2793,2349,1975,1975,2793,2793,2637,2637,2093,2093,2093,2093,2093,2093,
              1760,1760,3520,3520,3136,2793,2637,2793,3136,3136,3136,2093,2093,2093,2093,2093,
              2793,2637,2093,2793,2637,2093,3520,3136,3136,3136,3136,3136,3136,
              1567,1567,1567,2793,2637,2349,2093,2093,2093};



void setup() {
  Serial.begin(9600);
  pinMode(SW_POT, INPUT_PULLUP);
  play_music();
}
 
void loop() {
  // 분갈이 스위치 눌렀을 때
  if(digitalRead(SW_POT) == LOW)
    Serial.println(rtc.getDate());
    Serial.println(rtc.getYear());
    Serial.print();
    //Serial.print(rtc.getMonth(),DEC);
    //Serial.print(rtc.getDay(),DEC);
   else
    Serial.print("그만해줘")
   
}

// 음악재생 모듈
void play_music(){
  int elementCount = sizeof(music) / sizeof(int);
  for (int i=0; i < elementCount; i++)  
  {
    tone(BUZZER,music[i]/12,500);
    delay(350);
  }
}
