#include "Arduino.h"
#include "Sensor.hpp"
#include "ServoMotor.hpp"

servomotor servo1;
servomotor servo2;

sensor sensor1;
sensor sensor2;

void setup(){
    servo1.ServoSetup(2);
    servo2.ServoSetup(3);
}

void loop(){
    
}