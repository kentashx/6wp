int analog_output = 0;
int digital_output = 5;
int detect_val = 0;
int count =0;
int time = 0;
void setup() {
 //pinMode(digital_output,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  count = count+1;
//detect_val =analogRead(analog_output);
  detect_val = digitalRead(digital_output);
  Serial.println(detect_val);
  if(count>10000){
    time = millis();
    //prints time since program started
    Serial.println("終了時間は");
    Serial.println(time);
    Serial.println("msです");
    Serial.println("END");
    delay(100000);
  }
}
