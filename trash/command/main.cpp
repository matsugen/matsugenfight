#include"Dxlib.h"
#include<stdio.h>
#include"Skill.h"
#include"command.h"
#include"KeyTime.h"
#include"KeyDisplay.h"


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
        /*�����ɕϐ���S�̂Ŏg�p�����`����*/
	int Key[256];
	enum Menu ID;
	int i;
        /*�ϐ����`����̂͂����܂�*/
	double FPS=60.0;//FPS���w��
        int RefreshTime=0;//fps�����p
	SetBackgroundColor(255,255,255);//�w�i�𔒂�
	SetGraphMode(1280,720,16);//16bit�J���[1280*720window
        ChangeWindowMode(TRUE) ;
        SetDrawScreen( DX_SCREEN_BACK );               //����ʂ��g�p����
        if( DxLib_Init() == -1 ){
		return -1;                                            
	}  
	/*�������p�̃v���O����������*/
	/*�������p�̃v���O�����͂����܂�*/
        while(ProcessMessage() == 0){
                ClearDrawScreen();                      //����ʂ̏�����
		/*�������瓮�삳����v���O����������*/
		KeyTime(Key);
		ID=Command(Key);
		Skill(ID,Key);
		KeyDisplay(Key);
		/*���삳����v���O�����������̂͂����܂�*/
                if(Key[KEY_INPUT_ESCAPE]==1){
			break;  //Escape�������ꂽ��I��
		}
                RefreshTime = GetNowCount();            //���̎��Ԃ��擾
                while(GetNowCount() - RefreshTime <= (1.00/FPS)){//1���̏�����1/60�b�ɂȂ�܂ő҂�
		}
		ScreenFlip();                         //�\��
        }
        DxLib_End() ;
        return 0 ;
}
