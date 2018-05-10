#define LED 6
#define SW  4
boolean button = 0;
 
#define PUSH_SHORT 70//ショートボタンの閾値
#define PUSH_LONG  1000//ロングボタンの閾値

//ボタンを検出する関数
void detect_button(){
  unsigned long gauge_time = 0;
  static unsigned long gauge_time_start = 0;
  static unsigned long gauge_time_flag = 0;
  //HIGHになってる時間を検出
  while (!digitalRead(SW))
  {
    if(gauge_time_flag == 0){
      gauge_time_start = millis();
      gauge_time_flag = 1;
    }
    gauge_time = millis() - gauge_time_start;
  }
//HIGHの連続時間により短い押し、長い押しを判断
 if(gauge_time>PUSH_LONG){
    button = 0;
    Serial.print(button);
    Serial.print(":");
    Serial.print(gauge_time);
    Serial.print("  LONG!");
    Serial.println();
    gauge_time_flag = 0;
  } 
  else if(gauge_time>PUSH_SHORT){
    button = !button;
    Serial.print(button);
    Serial.print(":");
    Serial.print(gauge_time);
    Serial.print("  SHORT!");
    Serial.println();
    gauge_time_flag = 0;
  } 
  gauge_time = 0;
  gauge_time_start=0;
  gauge_time_flag = 0;
}


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop() {
  detect_button();
  digitalWrite(LED, button);
}
