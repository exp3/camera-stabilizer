#include "Arduino.h"
#include <Servo.h>

void setup();
void loop();

class rotation{
    int x;
    int y;
    int z;
}

//サーボモータのクラス
/*メンバ
変数：現在の角度・次の角度・目標の角度
関数：
*/
class servomotor{
    int nowAngle;//現在の角度
    int nextAngle;//次の角度
    int targetAngle;//目標の角度
    Servo myServo;
}

//加速度センサのクラス
class sensor{
    rotation acceleration;

    //呼び出されたときから1ms間の入力の平均値を取る。
    void input();
}


inline rotation input(){
    int x[10], y[10], z[10];
    rotation inputAcceleration;
    inputAcceleration

    for(int i = 0; i < 10; i++){
        x[i] = (analogRead() + analogRead()) / 2;
        y[i] = (analogRead() + analogRead()) / 2;
        z[i] = (analogRead() + analogRead()) / 2;
    }

    for(int i = 0; i < 10; i++){
        inputAcceleration. += [];
    }

    return inputAcceleration;
}
