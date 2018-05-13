/**********************************************
＊プログラム概要説明
脈拍を計測時間中は、計測。（デフォルトは10秒）
１０秒後、bpm_delayを算出し、その後はそのテンポで鳴らし続ける。
音は、テキストデータとして格納

＊課題
計測時間の妥当性。
**********************************************/
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
double bpm = 0;
double temp1 =0;//bpmが180の時は166.6666。
double temp2 =0;//bpmが180の時は83.33
double temp_flag=0;//テンポフラグが0の時のみ計算。1になったら計算ストップ
int vol =100;//ボリューム
int val = 0;

//脈拍用
//int analog_output = 0;
int digital_output = 5;//脈拍のデジタル値を読み込むのためのピン
static int seq_pulse = 0;//パルスの連続個数
int pulse = 0;//パルスの検出値
int bpm_flag = 0;//bpmの計算を一回にするためのフラグ
int bpm_delay = 1000;//bpm値に基づくdelay
static double one_loop_time =0.0;//1ループの時間
static int measure_time = 10000;//計測時間(ミリ秒)
static int flag =0;//1ループを計測するためのフラグ

//ボタン用
int button_flag = 0;// トグル:どの切り替えがされているかが格納
int toggle = 13;//トグルピンを読み込むピン
static int SW =13;
static int PUSH_SHORT = 70;//ショートボタンの閾値
static int PUSH_LONG = 1000;//ロングボタンの閾値
boolean button = 0;

//リセットする関数 
void software_reset(){
  asm volatile (" jmp 0");
}

//bpm値を検出する関数
void bpm_pulse(){
    if(bpm_flag==0){
      bpm = seq_pulse*60/(measure_time/1000);
      bpm_delay = 60000/bpm;
      bpm_flag = bpm_flag+1;
  }
}

//ON-OFF-ONのトグルスイッチの切り替えによって動作を変える
void detect_toggle_button(){
  int old_old_val = 0;//チャタリング用
  int old_val = 0;//チャタリング用
  int val = 0;
  old_old_val = digitalRead(toggle);
  delay(5);
  old_val = digitalRead(toggle);
  delay(5);
  val = digitalRead(toggle);
  if((old_old_val==0)&&(old_val==0)&&(val==0)){
    button_flag=0;
  }
  else{
    button_flag=1;
  }
}

//pulseを検出する関数
void detect_pulse(){
  static int old_detect_val = 0;
  static int seq_count =0;//パルスの連続回数
  static int thresh_hold =100;//ノイズ除去時間
  static int high_time_start = 0;//ノイズ除去用の時間
  static int high_time_total = 0;
  static int detect_val = 0;
  Serial.println(seq_pulse);
//detect_val =analogRead(analog_output);
  detect_val = digitalRead(digital_output);
//HIGHの立ち上がりの時間を検出,HIGHになっている時間を検出
  if(old_detect_val==0){
    if(detect_val==1){
      high_time_start = millis();
     }
  }
  else if(detect_val==1){
    high_time_total = millis() - high_time_start;
  }
  else{
    high_time_total = 0;
    high_time_start = 0;
  }
//HIGHの連続値が閾値を超えた時，パルス出力
  if(high_time_total>thresh_hold){
    //Serial.println(high_time_start);
    pulse=1;
    seq_pulse = seq_pulse+1;
    delay(100);
  } 
  else{
    pulse=0;
  }
  old_detect_val = detect_val;
}

//最後にパルス値を出力する関数
void pulse_info(){
  static int pulse_flag = 0;
  if (pulse_flag==0){
    Serial.print("bpmは");
    Serial.println(bpm);
    Serial.print("bpm_dalayは");
    Serial.println(bpm_delay);
    Serial.print("1ループにかかる時間は");
    Serial.print(one_loop_time/100);
    Serial.println("msです");
    Serial.print("終了時間は");
    Serial.print(millis());
    Serial.println("msです");
    Serial.print("検出パルス数は");
    Serial.print(seq_pulse);
    Serial.println("個です");
    Serial.println("END");
    pulse_flag = pulse_flag + 1;
  }
}

//1ループにかかる時間を検出
void loop_time() {
  //delay(5000);//脈拍が安定するまでの5秒間は待つ
  flag=flag+1;
  if(flag==2){
   Serial.println("はじめ");
  }
  if(flag==100){
    one_loop_time =millis();
    flag = flag+1;
  }
}
//テンポ計測用
void temp_measure(){
  if(temp_flag==0){
    temp1 = 60000/bpm/2;
    temp2 = 60000/bpm/4; 
    /*Serial.print("temp1:");
    Serial.println(temp1);
    Serial.print("temp2:");
    Serial.println(temp2);
    temp_flag++;*/
  }
}
void detect_reset(){
    detect_toggle_button();
    if(button_flag==0){
      software_reset();
      delay(1000);
  }
}

//再生用
void play_coffe(){
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
      detect_reset;
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
      detect_reset;
    delay(temp1);
    detect_reset;
}

void play(){
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
      detect_reset;
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
      detect_reset;
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
      detect_reset;
    delay(temp1);
    detect_reset;
}
void setup() {
  Serial.begin(9600);
  MIDI.begin();
  pinMode(3,OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);

}

void loop(){
  detect_toggle_button();
  if(button_flag==0){
    Serial.print("reset!!!!");
    delay(1000);
    software_reset();
  }
  else if(button_flag == 1){
    if(millis()<measure_time){
      //Serial.println("はじめ");
      detect_pulse();
      loop_time();//チェック用
    }
    else{
    //Serial.println("後半");
    bpm_pulse();
    temp_measure();
    pulse_info();
    play();
    }
  }
}


