#include "Arduino.h"
#include "ServoMotor.hpp"
#include <Servo.h>

//モーターの回転加速度の最大
#define ANGLE_CHANGE_LIMIT (1)

//5ms毎に呼び出し
void servomotor::ServoAngle(int target){
    //ダンピングの実装

    servomotor::targetAngle = target;
    
    if(/*角度が前の角度よりも大きい*/){
        /*変化量の変化量を使い、変化量を求め、変化量をnextAngleに足す*/
        servomotor::Damping(1);
        
    }else if(/*角度が前の角度よりも小さい*/){
        servomotor::Damping(-1);
    }
    /*回転角の変化なし。必要無かったら消す*/
    else{}

    servomotor::Motor.write(servomotor::nextAngle);

    //時間ごとの数値を代入して終了
    servomotor::nowAngle = servomotor::nextAngle;
    servomotor::changeAngle = servomotor::nextChangeAngle;
}

void servomotor::ServoSetup(int pin){
    servomotor::pinNum = pin;

    servomotor::Motor.attach(pin);

}

void servomotor::Damping(int BigOrSmall){

}