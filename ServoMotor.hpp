#pragma once
#include "Arduino.h"
#include "Servo.h"
void setup();
void loop();

//サーボモータのクラス
/*メンバ
変数：現在の角度・次の角度・目標の角度
関数：
*/
class servomotor{
    int nowAngle;//現在の角度
    int nextAngle;//次の角度
    int targetAngle;//目標の角度
    int changeAngle;//前の角度の変化量
    int nextChangeAngle;//次の角度の変化量

    //回転加速度(変化量の変化量)
    int AngleAccel1;
    int AngleAccel2;
    int AngleAccel3;

    Servo Motor;//サーボモータオブジェクト
    
    void ServoSetup(int);
    void ServoAngle(int);
    void Damping(int);
};