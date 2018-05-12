#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
double bpm = 180;
double temp1 =0;//bpmが180の時は166.6666
double temp2 =0;//bpmが180の時は83.33
double temp_flag=0;//テンポフラグが0の時のみ計算。1になったら計算ストップ
int vol =100;//ボリューム
void setup() {
  MIDI.begin();
  //Serial.begin(9600);
}
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

void play(){
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(60,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(60,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(62,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(62,0,1);
    delay(temp1);
}
void loop() {
  temp_measure();
  play();
}
