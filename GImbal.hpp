#include "Arduino.h"
#include <Servo.h>

void setup();
void loop();

class rotation{
    public:int x;
    public:int y;
    public:int z;
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
    int changeAngle;//前の角度の変化量
    int nextChangeAngle;//次の角度の変化量
    Servo myServo;

    void ServoAngle(int);
};

//加速度センサのクラス
class sensor{
    rotation acceleration;
    rotation inputAcceleration;
    //呼び出されたときから1ms間の入力の平均値を取る。
    rotation input();
};


inline rotation sensor::input(){
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

inline void servomotor::ServoAngle(targetAngle){
    //ダンピングの実装

    //時間ごとの数値を代入して終了
    nowAngle = nextAngle;
    changeAngle = nextChangeAngle;
}
