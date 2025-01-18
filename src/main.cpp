#include <Arduino.h>
#include <functions.h>

// Motor A
const int directionPinA = 12;
const int pwmPinA = 3;
const int brakePinA = 9;

// Motor B
const int directionPinB = 13;
const int pwmPinB = 11;
const int brakePinB = 8;

// Buzzer
const int buzzerPin = 5;
const int ultraSend = 6;
const int ultraRecieve = 7;

void setup() {
  
  // Motor A
  pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);
  pinMode(brakePinA, OUTPUT);

  // Motor B
  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(brakePinB, OUTPUT);

  // Ultrasonic Sensor
  pinMode(ultraRecieve, INPUT);
  pinMode(ultraSend, OUTPUT);

  // Buzzer
  pinMode(buzzerPin, OUTPUT);

  // Initialize the Serial (pc console)
  Serial.begin(9600);
}

void loop() {
  // Get the distance from the ultrasonic sensor
  float distance = getDistance(ultraSend, ultraRecieve);
  Serial.print("Distance [cm]: ");
  Serial.println(distance);

  if (distance < 10) {
    stop(directionPinB, brakePinA, brakePinB, pwmPinA, pwmPinB);
    rotate_in_situ(90, 500, directionPinA, directionPinB, brakePinA, brakePinB, pwmPinA, pwmPinB);
  }
  else {
    drive_straight(500, directionPinA, directionPinB, brakePinA, brakePinB, pwmPinA, pwmPinB);
  }
  
  // Small delay for stable readings
  delay(1);
}