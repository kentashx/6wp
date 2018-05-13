
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
int temp =166;
void setup() {
  MIDI.begin();
}
 
void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
      MIDI.sendNoteOn(60,50,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOff(45,0,1);
    delay(temp); //100ms待つ
      MIDI.sendNoteOn(45,50,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOff(45,0,1);
    delay(temp); //100ms待つ
      MIDI.sendNoteOn(45,50,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOff(45,0,1);
    delay(temp); //100ms待つ
      MIDI.sendNoteOn(33,120,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOn(38,120,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOn(45,120,1); //Note No 36をオンベロシティ100,1chで送信
      MIDI.sendNoteOff(33,0,1);
      MIDI.sendNoteOff(48,0,1);
      MIDI.sendNoteOff(45,0,1);
    delay(temp); //100ms待つ
}
