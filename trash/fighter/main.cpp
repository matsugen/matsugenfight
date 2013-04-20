#include"Dxlib.h"
#include"macro.h"
#include"Player1.h"
#include"Test.h"
#include<stdio.h>


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
        /*ここに変数を全体で使用する定義する*/
	Test *P1;
	P1=new Test();
        /*変数を定義するのはここまで*/
	char Key[MAXBUF];//入力されたキーボードの確認←今後ジョイパッドなどにも対応
	double FPS=60.0;//FPSを指定
        int RefreshTime=0;//fps処理用
	SetBackgroundColor(255,255,255);//背景を白に
	SetGraphMode(1280,720,16);//16bitカラー1280*720window
        ChangeWindowMode(TRUE) ;
        SetDrawScreen( DX_SCREEN_BACK );               //裏画面を使用する
        if( DxLib_Init() == -1 ){
		return -1;                                            
	}  
	/*初期化用のプログラムを書く*/
	P1->Load();
	/*初期化用のプログラムはここまで*/
        while(ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0){
                ClearDrawScreen();                      //裏画面の初期化
		/*ここから動作させるプログラムを書く*/
		P1->CONTROL(Key);
		P1->Move();
		P1->Print();
		/*動作させるプログラムを書くのはここまで*/
                if(Key[KEY_INPUT_ESCAPE]==1){
			break;  //Escapeが押されたら終了
		}
                RefreshTime = GetNowCount();            //今の時間を取得
                while(GetNowCount() - RefreshTime <= (1.00/FPS)){//1周の処理が1/60秒になるまで待つ
		}
		ScreenFlip();                         //表示
        }
	delete P1;    
        DxLib_End() ;
        return 0 ;
}
