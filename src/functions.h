#ifndef DISTANCE_H
#define DISTANCE_H

void rotate_in_situ(int degrees, int work_duty, int directionPinA, int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB);

void drive_straight(int time, int work_duty, int directionPinA, int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB);

// Function that returns the distance. Assumes usage of the HC-SR04 ultrasonic sensor.
// Takes up 15 [ms].
// HC-SR04 example project: https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1
// 
// Args: 
// - trigPin (int): Pin number of the sending pin of the sensor.
// - echoPin (int): Pin number of the recieving pin of the sensor.
//
//  Returns:
// - distance (float) in [cm]. 
float getDistance(int trigPin, int echoPin);

#endif