#pragma once
typedef struct rotation{
    int rotationX;
    int rotationY;
    int rotationZ;
};

//加速度センサのクラス
class sensor{
    rotation acceleration;

    public:
    rotation inputAcceleration;
    //呼び出されたときから1ms間の入力の平均値を取る。
    rotation input();
};