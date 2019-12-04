#include "Arduino.h"
#include <Servo.h>

void setup();
void loop();

class rotation{
    int x;
    int y;
    int z;
};

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
};

//加速度センサのクラス
class sensor{
    rotation acceleration;
    rotation inputAcceleration;
    //呼び出されたときから1ms間の入力の平均値を取る。
    void input();
};


inline rotation input(){
    int x[10], y[10], z[10];

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
