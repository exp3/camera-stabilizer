#pragma once
typedef struct rotation{
    int rotationX;
    int rotationY;
    int rotationZ;
};

//加速度センサのクラス
class sensor{
    rotation acceleration;
    rotation inputAcceleration;
    int pinNum;//ピン番号
    //呼び出されたときから1ms間の入力の平均値を取る。
    void input();
};