#include <Arduino.h>

const int forwardMotordPin = 2;
const int backwardMotorPin = 3;
const int forwardCaptorPin = 4;
const int backwardCaptorPin = 5;
const int buttonPin = 6;

const int delayTime = 100;

enum MovementState {
  FORWARD,
  BACKWARD,
  STOP
};
MovementState movementState = STOP;

void moveForward();
void moveBackward();
void stopMovement();

void setup() { 
  Serial.print("hola");
  pinMode(forwardMotordPin, OUTPUT);
  pinMode(backwardMotorPin, OUTPUT);
  pinMode(forwardCaptorPin, INPUT_PULLUP);
  pinMode(backwardCaptorPin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if(buttonState==LOW) {
    if (movementState==STOP) {
      movementState = FORWARD;
    }
    else {
      movementState = STOP;
    }
  }
  switch(movementState) {
  case FORWARD:
    moveForward();
    break;
  case BACKWARD:
    moveBackward();
    break;
  case STOP:
    stopMovement();
    break;
  }
}

void moveForward() {
  digitalWrite(forwardMotordPin, HIGH);
  digitalWrite(backwardMotorPin, LOW);
  int forwardCaptorState = digitalRead(forwardCaptorPin);
  if(forwardCaptorState==LOW) {
    movementState = BACKWARD;
    delay(delayTime);
  }
}

void moveBackward() {
  digitalWrite(forwardMotordPin, LOW);
  digitalWrite(backwardMotorPin, HIGH);
  int backwardCaptorState = digitalRead(backwardCaptorPin);
  if(backwardCaptorState==LOW) {
    movementState = STOP;
    delay(delayTime);
  }
}

void stopMovement() {
  digitalWrite(forwardMotordPin, LOW);
  digitalWrite(backwardMotorPin, LOW);
}
