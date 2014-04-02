#define RELAY 2
#define PCELL A0

int sensorValue = 0;
int outputValue = 0;
int statusLuz = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY, OUTPUT);
}

void loop() {
  loopPhotocell();
  loopRelay();
  delay(100);
}

void loopPhotocell() {
  sensorValue = analogRead(PCELL);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  if(outputValue<=50 && statusLuz==LOW) {
    statusLuz = HIGH;
  } else if (outputValue>50) {
    statusLuz = LOW;    
  }
}

void loopRelay() {
  digitalWrite(RELAY, statusLuz);
  Serial.println(statusLuz);
}
