const int forwardPin = 2;
const int backwardPin = 3;
const int motorPin = 4;
const int buttonPin = 5;

int buttonState;
int lastButtonState = HIGH;
unsigned long pushTime = 0;
unsigned long debounceDelay = 50;
const int movementDelay = 1000;

void setup() {
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState==LOW && millis()-pushTime>debounceDelay) {
    pushTime = millis();
    go_forward();
    go_backward();
    stop();
  }
  lastButtonState = buttonState;
}

void go_forward() {
  digitalWrite(forwardPin, HIGH);
  digitalWrite(backwardPin, LOW);
  digitalWrite(motorPin, HIGH);
}

void go_backward() {
  digitalWrite(forwardPin, LOW);
  digitalWrite(backwardPin, HIGH);
  digitalWrite(motorPin, HIGH);
}

void stop() {
  digitalWrite(motorPin, LOW);
}
