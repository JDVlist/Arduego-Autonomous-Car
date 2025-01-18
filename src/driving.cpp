
#include <Arduino.h>
#include "functions.h"

void rotate_in_situ(int degrees, int work_duty, int directionPinA, int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB) {
  // positive degrees is clockwise, negative degrees in counter clockwise
  if (degrees > 0) {
    digitalWrite(directionPinA, LOW);
    digitalWrite(directionPinB, HIGH);
  }
  else {
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, LOW);
    degrees*1.2;  // somehow it is harder to turn this was, so give it a little increase
  }

  //release breaks
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);

  //set work duty for the motor
  analogWrite(pwmPinA, work_duty);
  analogWrite(pwmPinB, work_duty);

  // Map the degrees to the time to keep the motors running
  int turn_delay = map( abs(degrees), 0, 360, 1, 1425 );  
  delay(turn_delay);

  //activate breaks
  digitalWrite(brakePinA, HIGH);
  digitalWrite(brakePinB, HIGH);

  //set work duty for the motor to 0 (off)
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);
}

void drive_straight(int work_duty, int directionPinA, int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB) {
  digitalWrite(directionPinA, HIGH);
  digitalWrite(directionPinB, HIGH);

  //release breaks
  digitalWrite(brakePinA, LOW);
  digitalWrite(brakePinB, LOW);

  //set work duty for the motor
  analogWrite(pwmPinA, work_duty);
  analogWrite(pwmPinB, work_duty);
}

void stop(int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB) {
  digitalWrite(brakePinA, HIGH);
  digitalWrite(brakePinB, HIGH);

  analogWrite(brakePinA, 0);
  analogWrite(brakePinB, 0);
}