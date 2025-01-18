#include <trackcar.h>

void TrackCar::rotate_in_situ(int degrees, int work_duty) {
    if (degrees > 0) {
        digitalWrite(directionPinA, LOW);
        digitalWrite(directionPinB, HIGH);
    } else {
        digitalWrite(directionPinA, HIGH);
        digitalWrite(directionPinB, LOW);
    }

    digitalWrite(brakePinA, LOW);
    digitalWrite(brakePinB, LOW);

    analogWrite(pwmPinA, work_duty);
    analogWrite(pwmPinB, work_duty);

    int turn_delay = map(abs(degrees), 0, 360, 1, 1350);
    delay(50 + turn_delay);

    digitalWrite(brakePinA, HIGH);
    digitalWrite(brakePinB, HIGH);

    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);
}

void TrackCar::drive_straight(int work_duty) {
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, HIGH);

    digitalWrite(brakePinA, LOW);
    digitalWrite(brakePinB, LOW);

    analogWrite(pwmPinA, work_duty);
    analogWrite(pwmPinB, work_duty);
}

void TrackCar::stop() {
    digitalWrite(brakePinA, HIGH);
    digitalWrite(brakePinB, HIGH);

    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);
}
