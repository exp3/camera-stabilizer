#include "Arduino.h"
#include "Sensor.hpp"
#include "ServoMotor.hpp"
#include "Switch.hpp"

servomotor servo1;
servomotor servo2;

sensor sensor1;

Switch switch1;

rotation inputRotation;

void setup(){
    servo1.ServoSetup(2);
    servo2.ServoSetup(3);
}

void loop(){
    inputRotation = sensor1.input();
    servo1.ServoAngle(inputRotation.rotationX);
    servo2.ServoAngle(inputRotation.rotationY);
}