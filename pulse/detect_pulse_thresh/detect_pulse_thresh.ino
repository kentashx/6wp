//int analog_output = 0;
int digital_output = 5;
int pulse = 0;//パルスが出力
int count =0;//ループ回数
int loop_count =5000;//ループ回数
double bpm =0.0;//bpm値を計測
static double one_loop_time =0;//1ループの時間

//pulseを検出する関数
void detect_pulse(){
  static int old_detect_val = 0;
  static int seq_count =0;//パルスの連続回数
  static int thresh_hold =20;//ノイズ除去閾値
  static int detect_val = 0;
  Serial.println(pulse);
//detect_val =analogRead(analog_output);
  detect_val = digitalRead(digital_output);
//HIGHが連続した時のみカウントする
  if(old_detect_val==1){
    if(detect_val==1){
      seq_count =seq_count+1;
     }
  }
  else{
    seq_count=0;
  }
//HIGHの連続値が閾値を超えた時，パルス出力
  if(seq_count>thresh_hold){
    pulse = 1;
    pulse = pulse+1;
    seq_count =0;
    delay(132);
  } 
  else{
    pulse=0;
  }
  old_detect_val = detect_val;
}

//最後にパルス値を出力する関数
void pulse_info(){
 static double time = 0.0;
 if(count>loop_count){
    time = millis();
    bpm = pulse*60/(time/1000);
    //prints time since program started
    Serial.println("1ループにかかる時間は");
    Serial.println(one_loop_time);
    Serial.println("終了時間は");
    Serial.println(time);
    Serial.println("msです");
    Serial.println("END");
    Serial.println("検出パルス数は");
    Serial.println(pulse);
    Serial.println("個です");
    Serial.println("BPMは");
    Serial.println(bpm);
    Serial.println("END");
    delay(10000000);
  }
}

//1ループにかかる時間を検出
void loop_time() {
  static int flag =0;//1ループを計測するためのフラグ
  flag=flag+1;
  if(flag==2){
    one_loop_time =millis();
    flag = flag+1;
  }
}

void setup() {
 //pinMode(digital_output,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  count = count+1;
  loop_time();
  detect_pulse();
  pulse_info();
  delay(2);
}
