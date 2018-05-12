/////////////////////////////////////////////////////定義とglobal関数だから本元のところにおいておいておいてね///////////////////////////////////////////////

#include <Adafruit_NeoPixel.h>
 
#define PIN            5 //シリアル通信GPIOピン番号
#define MAXPIXELS      12 //LED素子の最大数
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(MAXPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int cnt = 0; //256段階でLEDをフェードさせるためのカウント
 
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show();
  pixels.setBrightness(255); //Max 255.power of bllitness
}

///////////////////////////////////////////////////////////関数としてloop内で毎回呼び出す//////////////////////////////////////////////////////////////////

 void loop(){
      int a = random(0, 255);
      int b = random(0, 255);
      int c = random(0, 255);

  
      pixels.setPixelColor(0, pixels.Color(a, b, c));
      pixels.setPixelColor(1, pixels.Color(a, b, c));
      pixels.setPixelColor(2, pixels.Color(a, b, c));
      pixels.setPixelColor(3, pixels.Color(a, b, c));
      pixels.setPixelColor(4, pixels.Color(a, b, c));
      pixels.setPixelColor(5, pixels.Color(a, b, c));
      pixels.setPixelColor(6, pixels.Color(a, b, c));
      pixels.setPixelColor(7, pixels.Color(a, b, c));
      pixels.setPixelColor(8, pixels.Color(a, b, c));
      pixels.setPixelColor(9, pixels.Color(a, b, c));
      pixels.setPixelColor(10, pixels.Color(a, b, c));
      pixels.setPixelColor(11, pixels.Color(a, b, c));
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(100);
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
      delay(100);
      
 }

