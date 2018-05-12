/////////////////////////////////////////////////////定義とglobal関数だから本元のところにおいておいておいてね///////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>
 
#define PIN            5 //シリアル通信GPIOピン番号
#define MAXPIXELS      12 //LED素子の最大数
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAXPIXELS, PIN, NEO_GRB + NEO_KHZ800);
 
uint8_t ChangeType = 0; //LED点灯パターンを決める引数
uint32_t ChangeTime; //LED点灯パターンを変える時間
int cnt = 0; //256段階でLEDをフェードさせるためのカウント
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
  pixels.setBrightness(100); //Max 255.power of bllitness
  ChangeTime = millis();
}

///////////////////////////////////////////////////////////関数としてloop内で毎回呼び出す//////////////////////////////////////////////////////////////////
 
void loop(){
  if(millis() - ChangeTime > 15000){ //15 second Type Change
    ChangeType++;
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.setPixelColor(3, pixels.Color(0, 0, 0));
      pixels.setPixelColor(4, pixels.Color(0, 0, 0));
      pixels.setPixelColor(5, pixels.Color(0, 0, 0));
      pixels.setPixelColor(6, pixels.Color(0, 0, 0));
      pixels.setPixelColor(7, pixels.Color(0, 0, 0));
      pixels.setPixelColor(8, pixels.Color(0, 0, 0));
      pixels.setPixelColor(9, pixels.Color(0, 0, 0));
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
      pixels.show(); // This sends the updated pixel color to the hardware.
      cnt=0;
    if(ChangeType == 4) {
      ChangeType = 0;
    }
    ChangeTime = millis();
  }
   
  switch(ChangeType){
    case 0: //RGB type
      pixels.setPixelColor(0, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(1, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(2, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(3, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(4, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(5, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(6, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(7, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(8, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(9, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(10, pixels.Color(cnt, 0, 0));
      pixels.setPixelColor(11, pixels.Color(cnt, 0, 0));
      pixels.show(); // This sends the updated pixel color to the hardware.
      break;

      //cntで処理する部分以外を0にしとかないとcntがフェードアウトしていくときに、そこの成分の色が残ってしまうので消えない
       
    case 1: //Blue type
      pixels.setPixelColor(0, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(1, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(2, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(3, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(4, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(5, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(6, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(7, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(8, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(9, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(10, pixels.Color(0, cnt, 0));
      pixels.setPixelColor(11, pixels.Color(0, cnt, 0));
      pixels.show(); // This sends the updated pixel color to the hardware.
      break;

       
    case 2: //CMY type
      pixels.setPixelColor(0, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(1, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(2, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(3, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(4, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(5, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(6, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(7, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(8, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(9, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(10, pixels.Color(0, 0, cnt));
      pixels.setPixelColor(11, pixels.Color(0, 0, cnt));
      pixels.show(); // This sends the updated pixel color to the hardware.
      break;

      
      //orange点灯→その２つ後ろで緑点灯
      //色空間指定のところで10を指定しているので、フェードアウト後に色が消えず,10の文が残っている
  }
  cnt++;
  delay(100);
}
