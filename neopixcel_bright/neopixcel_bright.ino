/////////////////////////////////////////////////////定義とglobal関数だから本元のところにおいておいておいてね///////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>
//ボタン用
//boolean start_button_flag =  0;//0でstop、１でstart
//boolean button_flag =  0;//0は無効、1でreset
int button_flag = 0;// トグル:どの切り替えがされているかが格納
int toggle = 13;//トグルピンを読み込むピン
static long start_time = 0;//処理開始時間
static long start_time_flag = 0;//処理開始判定。0の時は処理行われず。1の時は処理開始。
static int PUSH_SHORT = 70;//ショートボタンの閾値
static int PUSH_LONG = 1000;//ロングボタンの閾値
boolean button = 0;
static int measure_time = 10000;//計測時間(ミリ秒)
#define PIN            10 //シリアル通信GPIOピン番号
#define MAXPIXELS      12 //LED素子の最大数
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAXPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
uint8_t LedNum1_Inc = 9; //最初にフェードインするLED番号
uint8_t LedNum1_Dec = 8; //フェードアウトするLED番号
 
uint8_t ChangeType = 3; //LED点灯パターンを決める引数
uint32_t ChangeTime; //LED点灯パターンを変える時間
int cnt = 0; //256段階でLEDをフェードさせるためのカウント

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
    //Serial.println("LOW");
  }
  else{
    button_flag =1;
    //Serial.println("HIGH");
  }
}

void led_loading(){
      
      pixels.setPixelColor(LedNum1_Inc, pixels.Color(0, cnt, 30));
//      pixels.show();
      pixels.setPixelColor(LedNum1_Dec, pixels.Color(0,255-cnt, 30));
      pixels.show();

      cnt = cnt+1;

      if(cnt == 256){ //フェードが最大、最少になったらLED素子を変える
        LedNum1_Inc++;
        if(LedNum1_Inc >= 12){ 
        LedNum1_Inc = 0;
        }
        LedNum1_Dec++;
        if(LedNum1_Dec >= 12) LedNum1_Dec = 0;
        cnt = 0;
       }
}

void setup() {
  //Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(255); //Max 255.power of bllitness
}      


///////////////////////////////////////////////////////////関数としてloop内で毎回呼び出す//////////////////////////////////////////////////////////////////


void loop(){
  detect_toggle_button();
  if(button_flag==0){
    start_time_flag=0;
  }
  else if(button_flag == 1){
    if((millis() - start_time)<measure_time){
      led_loading();
    }
    else{
    }
  }
}
