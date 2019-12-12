#include "Arduino.h"
#include "ServoMotor.hpp"
#include <Servo.h>


//モーターの回転加速度の最大
#define ANGLE_CHANGE_LIMIT 2

float t_sqrtF(int);

//5ms毎に呼び出し
void servomotor::ServoAngle(int target){
    servomotor::targetAngle = target;

    //ダンピングの実装
    servomotor::Damping();


    servomotor::Motor.write(servomotor::nextAngle);

    //時間ごとの数値を代入して終了
    servomotor::nowAngle = servomotor::nextAngle;
    servomotor::changeAngle = servomotor::nextChangeAngle;
}

void servomotor::ServoSetup(int pin){
    servomotor::pinNum = pin;

    servomotor::Motor.attach(pin);

}

void servomotor::Damping(void){
    int v = servomotor::nextChangeAngle;
    int A = servomotor::targetAngle;
    int t;

    t = 4 * (t_sqrtF(v * v + 2 * ANGLE_CHANGE_LIMIT ) - v) / (ANGLE_CHANGE_LIMIT * ANGLE_CHANGE_LIMIT);

    if(servomotor::nextChangeAngle > 0 && servomotor::nextChangeAngle > servomotor::targetAngle){
    }
}

float t_sqrtF(int xi){
    float x = xi;
    
    float xHalf;
    int tmp;
    float xRes;
    xHalf = 0.5f * x;
    tmp = 0x5F3759DF - ( *(int*)&x >> 1 ); //初期値
    xRes = *(float*)&tmp;
    xRes *= ( 1.5f - ( xHalf * xRes * xRes));
    return xRes * x;
}