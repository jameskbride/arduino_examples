int switchState = 0;

int PIN_2 = 2;
int PIN_3 = 3;
int PIN_4 = 4;
int PIN_5 = 5;

void setup() {
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
  pinMode(PIN_5, OUTPUT);
  pinMode(PIN_2, INPUT);
}

void loop() {
  switchState = digitalRead(PIN_2);
  
  if (switchState == LOW) {
    digitalWrite(PIN_3, HIGH);
    digitalWrite(PIN_4, LOW);
    digitalWrite(PIN_5, LOW);    
  } else {
    digitalWrite(PIN_3, LOW);
    digitalWrite(PIN_4, HIGH);
    digitalWrite(PIN_5, HIGH);
   
    delay(250);
    digitalWrite(PIN_4, LOW);
    digitalWrite(PIN_5, LOW);
    delay(250);
  }

}
