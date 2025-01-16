#include <Arduino.h>
#include "functions.h"

float getDistance(int trigPin, int echoPin) {

    float duration;
    float distance;

    // Send out an ultrasound signal using the trigger pin. When this bounces, it will be received by the echoPin.
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Listen for how long the echoPin is HIGH. When the sound waves hit the receiver, it turns the Echo pin high for however long the waves were traveling for.
    duration = pulseIn(echoPin, HIGH); // [microseconds]

    // Now we have the sound traveling time. We also have the speed of sound (340 m/s = 0.0343 cm/microsecond).
    // So: distance = (speed * time) / 2. The division by 2 is because the 'duration' is the travel time to and back.
    distance = (duration * 0.0343) / 2; // [cm]

    return distance;
}
