int TempSensorPin = A0; 
int RedLedPin = 13;    
int GreenLedPin = 12;
int BlueLedPin = 8;

void AllLedOFF() {
  digitalWrite(RedLedPin, LOW);
  digitalWrite(GreenLedPin, LOW);
  digitalWrite(BlueLedPin, LOW);
}

void setup() {
  pinMode(TempSensorPin, INPUT);
  pinMode(RedLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
  pinMode(BlueLedPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(TempSensorPin); 
  int Temperature = map(sensorValue, 20, 358, -40, 125);
  Serial.print("Temperature: ");
  Serial.print(Temperature);
  Serial.println(" C");

  if (Temperature < 10) {
    AllLedOFF();
    digitalWrite(BlueLedPin, HIGH);
  }
  else if (Temperature > 40) {
    AllLedOFF();
    digitalWrite(RedLedPin, HIGH);
  }
  else if (Temperature >= 10 && Temperature <= 40) {
    AllLedOFF();
    digitalWrite(GreenLedPin, HIGH);
  }

  delay(1000); 
}

