//タイトルクラス
#include"Title.h"
#include"DxLib.h"
#include"Menu.h"

Title::Title(){}

Title::~Title(){}

Base* Title::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(D_Key[KEY_INPUT_A]){
		next=new Menu();
	}
	return next;
}

bool Title::update(int *Key,bool *U_Key,bool *D_Key){
	return true;
}

bool Title::draw(){
	DrawFormatString(100,100,GetColor(0,0,0),"Title");
	return true;
}