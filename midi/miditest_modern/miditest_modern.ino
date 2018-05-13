
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
double temp1 =166;//bpmが180の時は166.6666
double temp2 =83;//bpmが180の時は83.33
int vol =100;
void setup() {
  MIDI.begin();
}
 
void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp2); //volms待つ
      MIDI.sendNoteOn(36,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(36,0,1);
    delay(temp1); //volms待つ
      MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
    delay(temp1); //volms待つ
          MIDI.sendNoteOn(38,vol,1); //Note No 36をオンベロシティvol,1chで送信
      MIDI.sendNoteOff(38,0,1);
    delay(temp1);
}
