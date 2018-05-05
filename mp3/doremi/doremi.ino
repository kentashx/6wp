//***************************************/
// tone関数で音を鳴らすプログラムその1
//***************************************/
#define BEATTIME 200 //音を出している時間(msec)
#define SPEAKER 12 //スピーカーの出力ピン番号
void setup() {
}
void loop() {
tone(SPEAKER,262,BEATTIME) ; // ド
delay(BEATTIME) ;
tone(SPEAKER,294,BEATTIME) ; // レ
delay(BEATTIME) ;
tone(SPEAKER,330,BEATTIME) ; // ミ
delay(BEATTIME) ;
tone(SPEAKER,349,BEATTIME) ; // ファ
delay(BEATTIME) ;
tone(SPEAKER,392,BEATTIME) ; // ソ
delay(BEATTIME) ;
tone(SPEAKER,440,BEATTIME) ; // ラ
delay(BEATTIME) ;
tone(SPEAKER,494,BEATTIME) ; // シ
delay(BEATTIME) ;
tone(SPEAKER,523,BEATTIME) ; // ド
delay(BEATTIME) ;
}
