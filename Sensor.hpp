
class rotation{
    int x;
    int y;
    int z;
};

//加速度センサのクラス
class sensor{
    rotation acceleration;
    rotation inputAcceleration;
    //呼び出されたときから1ms間の入力の平均値を取る。
    rotation input();
};