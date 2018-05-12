#include <Adafruit_NeoPixel.h>

/////////////////////////////////////////////////////定義とglobal関数だから本元のところにおいておいておいてね///////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>
 
#define PIN            10 //シリアル通信GPIOピン番号
#define MAXPIXELS      12 //LED素子の最大数
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAXPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
uint8_t LedNum1_Inc = 9; //最初にフェードインするLED番号
uint8_t LedNum1_Dec = 8; //フェードアウトするLED番号
 
uint8_t ChangeType = 3; //LED点灯パターンを決める引数
uint32_t ChangeTime; //LED点灯パターンを変える時間
int cnt = 0; //256段階でLEDをフェードさせるためのカウント
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(255); //Max 255.power of bllitness
  ChangeTime = millis();
}      


///////////////////////////////////////////////////////////関数としてloop内で毎回呼び出す//////////////////////////////////////////////////////////////////

void led_loading(){
      
      pixels.setPixelColor(LedNum1_Inc, pixels.Color(0, cnt, 30));
      pixels.show();
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

void loop(){
  led_loading();
}
      
