
const int NOTE_C_FREQ = 262;
const int NOTE_D_FREQ = 294;
const int NOTE_E_FREQ = 330;
const int NOTE_F_FREQ = 349;
const int MAX_ANALOG_VAL = 1023;

void setup() {
   Serial.begin(9600); 
}

void loop() {
   int keyVal = analogRead(A0);
   Serial.println(keyVal);
   
   if (keyVal == MAX_ANALOG_VAL) {
      tone(8, NOTE_C_FREQ);
   } else if (keyVal >= 990 && keyVal <= 1010) {
      tone(8, NOTE_D_FREQ); 
   } else if (keyVal >= 505 && keyVal <= 515) {
      tone(8, NOTE_E_FREQ); 
   } else if (keyVal >= 5 && keyVal <=10) {
      tone(8, NOTE_F_FREQ); 
   } else {
      noTone(8); 
   }
}
