
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
 
void setup() {
  MIDI.begin();
}
 
void loop() {
  // play notes from F#-0 (0x1E) to F#-5 (0x5A):
      MIDI.sendNoteOn(10,100,1); //Note No 36をオンベロシティ100,1chで送信
    delay(1000); //1秒待つ
          MIDI.sendNoteOn(40,100,1); //Note No 40をオンベロシティ100,1chで送信
    delay(1000); //1秒待つ
}
