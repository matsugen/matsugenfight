//オープニングクラス
#include"Opening.h"
#include"DxLib.h"
#include"Title.h"

Opening::Opening(){}

Opening::~Opening(){}

Base* Opening::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(D_Key[KEY_INPUT_A]){
		next=new Title();
	}
	return next;
}

bool Opening::update(int *Key,bool *U_Key,bool *D_Key){
	return true;
}



bool Opening::draw(){
	DrawFormatString(100,100,GetColor(0,0,0),"Opening");
	return true;
}