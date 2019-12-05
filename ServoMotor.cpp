#include "Arduino.h"
#include "ServoMotor.hpp"
#include <Servo.h>

void servomotor::ServoAngle(int target){
    //ダンピングの実装

    //時間ごとの数値を代入して終了
    servomotor::nowAngle = servomotor::nextAngle;
    servomotor::changeAngle = servomotor::nextChangeAngle;
}
