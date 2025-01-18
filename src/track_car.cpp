#include <Arduino.h>
#include "functions.h"

class TrackCar {
    public:
        // Define class member variables (attributes)
        int directionPinA;
        int directionPinB;
        int brakePinA;
        int brakePinB;
        int pwmPinA;
        int pwmPinB;

        // Constructor to initialize the object with data
        TrackCar(int directionPinA, int directionPinB, int brakePinA, int brakePinB, int pwmPinA, int pwmPinB)
            // Put that data in the class members (like self.pin = pin (Python))
            : directionPinA(directionPinA), directionPinB(directionPinB), brakePinA(brakePinA), brakePinB(brakePinB), pwmPinA(pwmPinA), pwmPinB(pwmPinB){
            // Constructor body (optional)
            }  

    void rotate_in_situ(int degrees, int work_duty) {
        // positive degrees is clockwise, negative degrees in counter clockwise
        if (degrees > 0) {
        digitalWrite(directionPinA, LOW);
        digitalWrite(directionPinB, HIGH);
        }
        else {
        digitalWrite(directionPinA, HIGH);
        digitalWrite(directionPinB, LOW);
        }

        //release breaks
        digitalWrite(brakePinA, LOW);
        digitalWrite(brakePinB, LOW);

        //set work duty for the motor
        analogWrite(pwmPinA, work_duty);
        analogWrite(pwmPinB, work_duty);

        // Map the degrees to the time to keep the motors running
        int turn_delay = map( abs(degrees), 0, 360, 1, 1350 );  
        delay( 50 + turn_delay );    // int for the intertia, which is always the same

        //activate breaks
        digitalWrite(brakePinA, HIGH);
        digitalWrite(brakePinB, HIGH);

        //set work duty for the motor to 0 (off)
        analogWrite(pwmPinA, 0);
        analogWrite(pwmPinB, 0);
    }

    void drive_straight(int time, int work_duty) {
        digitalWrite(directionPinA, HIGH);
        digitalWrite(directionPinB, HIGH);

        //release breaks
        digitalWrite(brakePinA, LOW);
        digitalWrite(brakePinB, LOW);

        //set work duty for the motor
        analogWrite(pwmPinA, work_duty);
        analogWrite(pwmPinB, work_duty);
    }

    void stop() {
        //activate breaks
        digitalWrite(brakePinA, HIGH);
        digitalWrite(brakePinB, HIGH);

        //set work duty for the motor to 0 (off)
        analogWrite(pwmPinA, 0);
        analogWrite(pwmPinB, 0);
    }
};


