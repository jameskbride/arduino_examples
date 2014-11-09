int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int LED_PIN = 13;
const int PIEZOMETER_PIN = 8;
const int FIVE_SECONDS = 5000;

const int OUTPUT_MIN = 50;
const int OUTPUT_MAX = 4000;

const int TONE_LENGTH_MILLIS = 20;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  while(millis() < FIVE_SECONDS) {
    if (sensorValue < sensorHigh) {
      sensorHigh = sensorValue;
    }
  
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }  
  }
  
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, OUTPUT_MIN, OUTPUT_MAX);
  tone(PIEZOMETER_PIN, pitch, TONE_LENGTH_MILLIS);
  delay(10);
}
