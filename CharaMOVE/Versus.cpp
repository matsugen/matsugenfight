//バーサスクラス
#include"Versus.h"
#include"DxLib.h"
#include"macro.h"
#include"Dammy.h"
//バーサスポーズメニュー

//バーサスモード
Versus::Versus(){
	m_chara[ONE]=new Dammy();
	
}

Versus::~Versus(){	
}

Base* Versus::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	return next;
}

bool Versus::update(int *Key,bool *U_Key,bool *D_Key){
	/*アップデート情報をここに*/
	m_chara[ONE]->update(Key);
	/*アップデートはここまで*/
	return true;
}

bool Versus::draw(){
	m_chara[ONE]->draw();
	return true;
}
