#include <Servo.h>

Servo servo;

const int SERIAL_PORT = 9600;

const int POTENT_PIN = A0;
const int SERVO_PIN = 9;

const int BYTE_INPUT_MIN = 0;
const int BYTE_INPUT_MAX = 1023;

const int ANGLE_OUTPUT_MIN = 0;
const int ANGLE_OUTPUT_MAX = 179;  

int potentVal;
int angle;

void setup() {
  servo.attach(SERVO_PIN);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  potentVal = analogRead(POTENT_PIN);
  Serial.print("Potentiometer value: ");
  Serial.print(potentVal);
  
  angle = map(potentVal, BYTE_INPUT_MIN, BYTE_INPUT_MAX, ANGLE_OUTPUT_MIN, ANGLE_OUTPUT_MAX);
  Serial.print(", angle: ");
  Serial.print(angle);
  Serial.println();
  
  servo.write(angle);
  delay(15);
}
