#include"Dxlib.h"
#include"macro.h"
#include"Player1.h"
#include"Test.h"
#include<stdio.h>


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
        /*�����ɕϐ���S�̂Ŏg�p�����`����*/
	Test *P1;
	P1=new Test();
        /*�ϐ����`����̂͂����܂�*/
	char Key[MAXBUF];//���͂��ꂽ�L�[�{�[�h�̊m�F������W���C�p�b�h�Ȃǂɂ��Ή�
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
	P1->Load();
	/*�������p�̃v���O�����͂����܂�*/
        while(ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0){
                ClearDrawScreen();                      //����ʂ̏�����
		/*�������瓮�삳����v���O����������*/
		P1->CONTROL(Key);
		P1->Move();
		P1->Print();
		/*���삳����v���O�����������̂͂����܂�*/
                if(Key[KEY_INPUT_ESCAPE]==1){
			break;  //Escape�������ꂽ��I��
		}
                RefreshTime = GetNowCount();            //���̎��Ԃ��擾
                while(GetNowCount() - RefreshTime <= (1.00/FPS)){//1���̏�����1/60�b�ɂȂ�܂ő҂�
		}
		ScreenFlip();                         //�\��
        }
	delete P1;    
        DxLib_End() ;
        return 0 ;
}
