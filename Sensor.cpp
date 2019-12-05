#include "Arduino.h"
#include "Sensor.hpp"

rotation sensor::input(){
    int x[10], y[10], z[10];

    inputAcceleration.x = 0;
    inputAcceleration.y = 0;
    inputAcceleration.z = 0;

    for(int i = 0; i < 10; i++){
        x[i] = (analogRead(0) + analogRead(3)) / 2;
        y[i] = (analogRead(1) + analogRead(4)) / 2;
        z[i] = (analogRead(2) + analogRead(5)) / 2;
    }

    //微小区間の平均化
    for(int i = 0; i < 10; i++){
        inputAcceleration.x += x[i];
        inputAcceleration.y += y[i];
        inputAcceleration.z += z[i];
    }

    return inputAcceleration;
}