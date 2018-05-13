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
#define PIN1            9 //シリアル通信GPIOピン番号
#define PIN2            10 //シリアル通信GPIOピン番号
#define MAXPIXELS      12 //LED素子の最大数
 
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(MAXPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(MAXPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
 
uint8_t LedNum1_Inc = 9; //最初にフェードインするLED番号
uint8_t LedNum1_Dec = 8; //フェードアウトするLED番号
 
uint8_t ChangeType = 0; //LED点灯パターンを決める引数
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
      pixels1.setPixelColor(LedNum1_Inc, pixels1.Color(0, cnt, 30));
      pixels1.setPixelColor(LedNum1_Dec, pixels1.Color(0,255-cnt, 30));
      pixels1.show();

      pixels2.setPixelColor(LedNum1_Inc, pixels2.Color(0, cnt, 30));
      pixels2.setPixelColor(LedNum1_Dec, pixels2.Color(0,255-cnt, 30));
      pixels2.show();
      
      cnt = cnt+5;

      if(cnt >= 256){ //フェードが最大、最少になったらLED素子を変える
        LedNum1_Inc++;
        if(LedNum1_Inc >= 12){ 
        LedNum1_Inc = 0;
        }
        LedNum1_Dec++;
        if(LedNum1_Dec >= 12) {
          LedNum1_Dec = 0;
        }
        cnt = 0;
       }
}

 void led_pulse1(){
      int a = random(0, 255);
      int b = random(0, 255);
      int c = random(0, 255);

  
      pixels1.setPixelColor(0, pixels1.Color(a, b, c));
      pixels1.setPixelColor(1, pixels1.Color(a, b, c));
      pixels1.setPixelColor(2, pixels1.Color(a, b, c));
      pixels1.setPixelColor(3, pixels1.Color(a, b, c));
      pixels1.setPixelColor(4, pixels1.Color(a, b, c));
      pixels1.setPixelColor(5, pixels1.Color(a, b, c));
      pixels1.setPixelColor(6, pixels1.Color(a, b, c));
      pixels1.setPixelColor(7, pixels1.Color(a, b, c));
      pixels1.setPixelColor(8, pixels1.Color(a, b, c));
      pixels1.setPixelColor(9, pixels1.Color(a, b, c));
      pixels1.setPixelColor(10, pixels1.Color(a, b, c));
      pixels1.setPixelColor(11, pixels1.Color(a, b, c));
      pixels1.show(); // This sends the updated pixel color to the hardware.
      delay(100);
      pixels1.setPixelColor(0, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(1, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(2, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(3, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(4, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(5, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(6, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(7, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(8, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(9, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(10, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(11, pixels1.Color(0, 0, 0));
      pixels1.show(); // This sends the updated pixel color to the hardware.
      delay(100);
 }
       
void led_pulse2(){
      int a = random(0, 255);
      int b = random(0, 255);
      int c = random(0, 255);
      pixels2.setPixelColor(0, pixels2.Color(a, b, c));
      pixels2.setPixelColor(1, pixels2.Color(a, b, c));
      pixels2.setPixelColor(2, pixels2.Color(a, b, c));
      pixels2.setPixelColor(3, pixels2.Color(a, b, c));
      pixels2.setPixelColor(4, pixels2.Color(a, b, c));
      pixels2.setPixelColor(5, pixels2.Color(a, b, c));
      pixels2.setPixelColor(6, pixels2.Color(a, b, c));
      pixels2.setPixelColor(7, pixels2.Color(a, b, c));
      pixels2.setPixelColor(8, pixels2.Color(a, b, c));
      pixels2.setPixelColor(9, pixels2.Color(a, b, c));
      pixels2.setPixelColor(10, pixels2.Color(a, b, c));
      pixels2.setPixelColor(11, pixels2.Color(a, b, c));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      delay(100);
      pixels2.setPixelColor(0, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(1, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(2, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(3, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(4, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(5, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(6, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(7, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(8, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(9, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(10, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(11, pixels2.Color(0, 0, 0));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      delay(100);
 }

 void led_start(){
  if(millis() - ChangeTime > 15000){ //15 second Type Change
    ChangeType++;
      pixels1.setPixelColor(0, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(1, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(2, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(3, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(4, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(5, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(6, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(7, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(8, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(9, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(10, pixels1.Color(0, 0, 0));
      pixels1.setPixelColor(11, pixels1.Color(0, 0, 0));
      pixels1.show(); // This sends the updated pixel color to the hardware.
      cnt=0;

            pixels2.setPixelColor(0, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(1, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(2, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(3, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(4, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(5, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(6, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(7, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(8, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(9, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(10, pixels2.Color(0, 0, 0));
      pixels2.setPixelColor(11, pixels2.Color(0, 0, 0));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      cnt=0;
    if(ChangeType == 4) {
      ChangeType = 0;
    }
    ChangeTime = millis();
  }
   
  switch(ChangeType){
    case 0: //R type
      pixels1.setPixelColor(0, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(1, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(2, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(3, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(4, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(5, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(6, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(7, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(8, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(9, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(10, pixels1.Color(cnt, 0, 0));
      pixels1.setPixelColor(11, pixels1.Color(cnt, 0, 0));
      pixels1.show(); // This sends the updated pixel color to the hardware.

            pixels2.setPixelColor(0, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(1, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(2, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(3, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(4, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(5, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(6, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(7, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(8, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(9, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(10, pixels2.Color(cnt, 0, 0));
      pixels2.setPixelColor(11, pixels2.Color(cnt, 0, 0));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      break;

      //cntで処理する部分以外を0にしとかないとcntがフェードアウトしていくときに、そこの成分の色が残ってしまうので消えない
       
    case 1: //G type
      pixels1.setPixelColor(0, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(1, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(2, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(3, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(4, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(5, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(6, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(7, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(8, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(9, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(10, pixels1.Color(0, cnt, 0));
      pixels1.setPixelColor(11, pixels1.Color(0, cnt, 0));
      pixels1.show(); // This sends the updated pixel color to the hardware.
      
            pixels2.setPixelColor(0, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(1, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(2, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(3, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(4, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(5, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(6, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(7, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(8, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(9, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(10, pixels2.Color(0, cnt, 0));
      pixels2.setPixelColor(11, pixels2.Color(0, cnt, 0));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      break;

       
    case 2: //B type
      pixels1.setPixelColor(0, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(1, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(2, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(3, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(4, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(5, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(6, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(7, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(8, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(9, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(10, pixels1.Color(0, 0, cnt));
      pixels1.setPixelColor(11, pixels1.Color(0, 0, cnt));
      pixels1.show(); // This sends the updated pixel color to the hardware.

            pixels2.setPixelColor(0, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(1, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(2, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(3, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(4, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(5, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(6, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(7, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(8, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(9, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(10, pixels2.Color(0, 0, cnt));
      pixels2.setPixelColor(11, pixels2.Color(0, 0, cnt));
      pixels2.show(); // This sends the updated pixel color to the hardware.
      break;

      
      //orange点灯→その２つ後ろで緑点灯
      //色空間指定のところで10を指定しているので、フェードアウト後に色が消えず,10の文が残っている
  }
  cnt=cnt+1;
  delay(100);
}

void setup() {
//  Serial.begin(9600);
  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin(); // This initializes the NeoPixel library.
  pixels1.setBrightness(255); //Max 255.power of bllitness
  pixels2.setBrightness(255); //Max 255.power of bllitness
  ChangeTime = millis();
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}      


///////////////////////////////////////////////////////////関数としてloop内で毎回呼び出す//////////////////////////////////////////////////////////////////


void loop(){
  detect_toggle_button();
  
  if(button_flag==0){
    start_time_flag=0;
    led_start();
  }
  
  else if(button_flag == 1){

    if(start_time_flag == 0){
      start_time = millis();
      start_time_flag = 1;
    }
    
    if((millis() - start_time)<measure_time){
      led_loading();
      //detect_pulse
    }
    else if((digitalRead(11)==HIGH)&&(digitalRead(12)==HIGH)){ //Ard_1 is high
      led_pulse1();
      led_pulse2();
    }
    else if((digitalRead(11)==HIGH)&&(digitalRead(12)==LOW)){ //Ard_2 is high
      //ここにサウンド関数
      led_pulse1();
    }
     else if((digitalRead(11)==LOW)&&(digitalRead(12)==HIGH)){ //Ard_2 is high
      //ここにサウンド関数
      led_pulse2();
    }
  }
}
