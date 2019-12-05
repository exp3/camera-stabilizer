#include "Arduino.h"
#include "Sensor.hpp"

void sensor::input(){
    int x[10], y[10], z[10];

    sensor::inputAcceleration.rotationX = 0;
    sensor::inputAcceleration.rotationY = 0;
    sensor::inputAcceleration.rotationZ = 0;

    //二つのセンサーの入力値の管理
    //10ms間で10回の値を取得
    for(int i = 0; i < 10; i++){
        x[i] = (analogRead(0) + analogRead(3)) / 2;
        y[i] = (analogRead(1) + analogRead(4)) / 2;
        z[i] = (analogRead(2) + analogRead(5)) / 2;
        delay(1);
    }

    //微小区間の平均化
    for(int i = 0; i < 10; i++){
        sensor::inputAcceleration.rotationX += x[i];
        sensor::inputAcceleration.rotationY += y[i];
        sensor::inputAcceleration.rotationZ += z[i];
    }
}