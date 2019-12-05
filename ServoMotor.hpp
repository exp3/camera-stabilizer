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
    Servo Motor;

    void ServoAngle(int);
};