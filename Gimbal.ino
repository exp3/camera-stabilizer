/*
1.2
数値の平滑化を実装
ON、OFFのスイッチ実装

1.3
二軸化
*/


#include <Servo.h>

void input();
void output();
void smoothing();
void DebugLog();
int input_switch();
void calibration();
int analoginput(int port);

//宣言
Servo myServo; // create a servo object
 
int const potPin = A0; // analog pin used to connect the potentiometer
int input_x, input_y, input_z; //インプットの値
int input_Calibrationed_x, input_Calibrationed_y, input_Calibrationed_z;//キャリブレーション用
int count;//デバッグのタイミングカウント用
int output_x, output_y, output_z;//アウトプット用
int output_x_hold, output_y_hold, output_z_hold;//アウトプットの保持用
float outputf_x;//アウトプットのfloat型用
int input_UI, time_count_switch; //UIのスイッチの判定用
bool go = true;//動作の状態

//初期化の関数
void setup() {
    int button = input_switch;

    while(button != 1)  delay(10);
    
    myServo.attach(2);  //サーボモータをポート２にアタッチ //attach servo motor
    Serial.begin(9600); // 9600bpsでシリアルポートを開く

    //インプット変数初期化
    input_x = 0;
    input_y = 0;
    input_z = 0;

    //駆動開始宣言
    
    Serial.print("start");
    Serial.println();

    //動作確認駆動
    delay(1000);
    myServo.write(150); //output to servo motor
    delay(2000);
    myServo.write(30);
    delay(2000);
    myServo.write(90);
    delay(2000);

    //キャリブレーション用の値測定（初期値）
    calibration();

    count = 0;
}
 
void loop() {

    //スイッチの入力判定
    switch (input_switch())
    {
    case 0:
        break;
    case 1:
        if(go)  go = false;
        else  go = true;
        break;
    case 2:
        calibration();
        break;
    default:
        break;
    }

    if(go){
        update();
    }

    
}

void update(){
    //入力
    input();

    //補正
    correct();

    //平滑化
    //前の変化との差を軽減する
    smoothing();
    
    //出力
    output();

    //シリアル通信での値の表示を1秒毎に行う
    if(count == 20){
        DebugLog();
        count = 0;
    }

    delay(10);
    count++;
}

void calibration(){
    int calibration_x[10], calibration_x_ave;
    int calibration_y[10], calibration_y_ave;
    int calibration_z[10], calibration_z_ave;
    delay(500);
    for(int count = 0; count <= 9; count++){
        calibration_x[count] = analoginput(0);
        calibration_y[count] = analoginput(1);
        calibration_z[count] = analoginput(2);
        delay(10);
    }
    for(int count = 0; count <= 9; count++){
        calibration_x_ave += calibration_x[count];
    }

    input_Calibrationed_x = calibration_x_ave / 10;
}

void input(){
    input_x = analoginput(0);
    input_y = analoginput(1);    
    input_z = analoginput(2);
}

void correct(){
    outputf_x = 100 + (input_Calibrationed_x + 200 - input_x) * 0.45;    //0.45 = 90° ÷ 200
    output_x_hold = output_x;
    output_x = outputf_x;
}

void smoothing(){
    if(output_x_hold - output_x > 3){
        output_x = output_x_hold - 3;
    }
    if(output_x_hold - output_x < 3){
        output_x = output_x_hold + 3;
    }
}

void output(){
    myServo.write(-output_x);
}

void DebugLog(void){
    Serial.print("x = ");
    Serial.print(input_x);
    Serial.println(); //改行
    Serial.print("y = ");
    Serial.print(input_y);
    Serial.println();
    Serial.print("z = ");
    Serial.print(input_z);
    Serial.println();
    Serial.println();
}

/*スイッチは0.1秒程度押してくれれば動作可能。*/
int input_switch(){
    int input_UI_now, code = 0;

    input_UI_now = digitalRead(3);
    /*
    code
    0:ボタンは押されていない
    1:ボタンが押された
    2:ボタンが長押しされた
    */

    if((input_UI != input_UI_now) && (input_UI = 1)){
        code = 1;
    }

    //長押し
    else{
        if(input_UI == 0){
            time_count_switch ++;
            if(time_count_switch > 100){
                time_count_switch = 0;
                code = 2;
            }
        }
        else{
            if(time_count_switch != 0){
                time_count_switch = 0;
            }
        }
    }

    input_UI = input_UI_now;
    return code;
}

int analoginput(port){
    int sensor1, sensor2, ave_value;
    sensor1 = analogRead(port);
    sensor2 = analogRead(port + 3);
    
    ave_value = sensor1 + (sensor2 - sensor1)/2;
    
    return ave_value;
}