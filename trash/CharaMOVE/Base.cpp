//メニュー基底クラス
#include"Base.h"

Base::~Base(){}
CharaState::~CharaState(){}
InputData CharaState::InputToButton(int *Key){
	InputData Return_Data=0;
	if(Key[KEY_INPUT_Q]>=1&&Key[KEY_INPUT_Q]<3){
		Return_Data|=L_P;
	}
	if(Key[KEY_INPUT_A]>=1&&Key[KEY_INPUT_A]<3){
		Return_Data|=L_K;
	}
	if(Key[KEY_INPUT_W]>=1&&Key[KEY_INPUT_W]<3){
		Return_Data|=H_P;
	}
	if(Key[KEY_INPUT_S]>=1&&Key[KEY_INPUT_S]<3){
		Return_Data|=H_K;
	}
	if(Key[KEY_INPUT_Q]==0&&Key[KEY_INPUT_A]==0&&Key[KEY_INPUT_W]==0&&Key[KEY_INPUT_S]==0){
		Return_Data=NO_BUTTON;
	}
	return Return_Data;
}

InputData CharaState::InputToArrow(int *Key){
	InputData Return_Data=0;
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){//5
		Return_Data=NEUTRAL;
	}
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_RIGHT]==0){//1
		Return_Data=B_DOWN;
	}
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_RIGHT]==0){//4
		Return_Data=BACK;
	}
	if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_RIGHT]==0){//7
		Return_Data=B_UP;
	}
	if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){//8
		Return_Data=UP;
	}
	if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]>=1){//9
		Return_Data=F_UP;
	}
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]>=1){//6
		Return_Data=FORWARD;
	}
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]>=1){//3
		Return_Data=F_DOWN;
	}
	if(Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){//2
		Return_Data=DOWN;
	}
	return Return_Data;
}
