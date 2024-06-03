#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
//�萔
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
}circle;

circle Circle;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;
//�Q�[���t���O
bool enterPressedLastFrame = false;     //�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;             //�Q�[���J�n�t���O
bool circleGenerationFlag = true;       //�~�̐����t���O
bool gameEndFlag = true;
//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//Windows�̃��C���œ�����
{
        if (DxLib_Init() == -1)
        {
            //�G���[���N�����璼���ɏI��
            return -1;
        }
    Circle.posX = 150;
    Circle.posY = 200;
    int circleColor = GetColor(0, 0, 255);
    Circle.radius = 30;
    //---------------------------//
    // ��{�ݒ�
    //---------------------------//

    //---------------------------//
    // �Q�[�����[�v
    //---------------------------//

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //��ʂɉ~��`�悳����
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, circleColor, TRUE);
        if (CheckHitKey(KEY_INPUT_UP))
        {
            Circle.radius += 2;
        }
    }


    return 0;
}