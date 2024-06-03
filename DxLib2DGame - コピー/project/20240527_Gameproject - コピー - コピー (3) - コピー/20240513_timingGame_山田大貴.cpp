#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
//定数
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200

//変数
typedef struct circle
{
    int posX;
    int posY;
    int radius;
}circle;

circle Circle;
//円の最大面積
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//ゲームフラグ
bool enterPressedLastFrame = false;     //エンターキーが押されたかどうかのフラグ
bool gameStartFlag = false;             //ゲーム開始フラグ
bool circleGenerationFlag = true;       //円の生成フラグ
bool gameEndFlag = true;
//メイン関数
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windowsのメインで動かす
{
        if (DxLib_Init() == -1)
        {
            //エラーが起きたら直ちに終了
            return -1;
        }
    Circle.posX = 150;
    Circle.posY = 200;
    int circleColor = GetColor(0, 0, 255);
    Circle.radius = 30;
    //---------------------------//
    // 基本設定
    //---------------------------//

    //---------------------------//
    // ゲームループ
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //画面に円を描画させる
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, circleColor, TRUE);
        if (CheckHitKey(KEY_INPUT_UP))
        {
            Circle.radius += 2;
        }
    }


    return 0;
}