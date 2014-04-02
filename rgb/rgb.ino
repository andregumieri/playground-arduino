#define RED 3
#define BLUE 5
#define GREEN 6
#define BTN 2

int red = 10, green = 0, blue = 0;
int val = 0;
int buttonState = 0;
int buttonAction = 0;
int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BTN, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  randomLight();
}

void loop() {
  readButton();
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
  analogWrite(RED, red);
  
  if(Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
  }
}

void readButton() {
  buttonState = digitalRead(BTN);
  if(buttonState==HIGH && buttonAction==0) {
     buttonAction = 1; 
     randomLight();
   } else if (buttonState==LOW) {
      buttonAction = 0; 
   } 
}


void randomLight() {
  red = random(256);
  green = random(256);
  blue = random(256);
  Serial.println("---");
  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.print(blue);
}
