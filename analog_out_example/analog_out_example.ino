const int SENSOR_PIN = A0;
const float BASELINE_TEMP = 20.0;
const int TEMP_DELTA = 2;

const int PIN_2 = 2;
const int PIN_3 = 3;
const int PIN_4 = 4;

float normalizeVoltage(const int sensorVal) {
  return (sensorVal/1024.0) * 5.0;
}

float calculateDegreesCelcius(const float voltage) {
   return (voltage - 0.5) * 100;
}

bool isCold(const float temp) {
    return temp <  BASELINE_TEMP;
}

bool isLowTemp(const float temp) {
  return (temp >= (BASELINE_TEMP + TEMP_DELTA)) &&
      (temp < (BASELINE_TEMP + (TEMP_DELTA * 2)));
}

bool isMediumTemp(const float temp) {
  return (temp >= (BASELINE_TEMP + (TEMP_DELTA * 2))) &&
      (temp < (BASELINE_TEMP + (TEMP_DELTA * 3)));  
}

bool isHot(const float temp) {
  return temp >= (BASELINE_TEMP + (TEMP_DELTA * 3));  
}

void displayReading(const float temp) {
  if (isCold(temp)) {
    digitalWrite(PIN_2, LOW);
    digitalWrite(PIN_3, LOW);
    digitalWrite(PIN_4, LOW);  
  } else if (isLowTemp(temp)) {
    digitalWrite(PIN_2, HIGH);
    digitalWrite(PIN_3, LOW);
    digitalWrite(PIN_4, LOW);    
  } else if (isMediumTemp(temp)) {
    digitalWrite(PIN_2, HIGH);
    digitalWrite(PIN_3, HIGH);
    digitalWrite(PIN_4, LOW);    
  } else if (isHot(temp)) {
    digitalWrite(PIN_2, HIGH);
    digitalWrite(PIN_3, HIGH);
    digitalWrite(PIN_4, HIGH);  
  }
}

void setup() {
  for (int pinNumber=2; pinNumber<5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(SENSOR_PIN);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  float voltage = normalizeVoltage(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltage);
    
  float temp = calculateDegreesCelcius(voltage);
  Serial.print(", degrees Celcius: ");
  Serial.print(temp);
  
  Serial.println();
  
  displayReading(temp);
  
  delay(1);
}


