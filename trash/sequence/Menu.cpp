#include"Menu.h"
#include"DxLib.h"
#include"Arcade.h"
#include"Versus.h"
#include"Practice.h"
#include"Title.h"
Menu::Menu(){
	for(int i=0;i<MENUNUM;i++){
	m_pos[i]=100;
	}
	m_MenuID=ARCADE;
}

Menu::~Menu(){}

Base* Menu::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(D_Key[KEY_INPUT_S]&&!D_Key[KEY_INPUT_A]){
		switch(m_MenuID){
			case ARCADE:
				next=new Arcade();
				break;
			case VS:
				next=new Versus();
				break;
			case PRACTICE:
				next=new Practice();
				break;
			case TITLE:
				next=new Title();
				break;
			default:
				next=this; 
				break;
		}
	}else if(!D_Key[KEY_INPUT_S]&&D_Key[KEY_INPUT_A]){
		next=new Title();
	}
	return next;
}

bool Menu::update(int *Key,bool *U_Key,bool *D_Key){
	if(Key[KEY_INPUT_DOWN]%30==1&&Key[KEY_INPUT_UP]==0){
		m_MenuID=(m_MenuID+1)%MENUNUM;
	}else if(Key[KEY_INPUT_UP]%30==1&&Key[KEY_INPUT_DOWN]==0){
		m_MenuID=(m_MenuID+MENUNUM-1)%MENUNUM;
	}
	m_pos[m_MenuID]=80;
	for(int i=0;i<MENUNUM;i++){
		if(i!=m_MenuID){
			m_pos[i]=100;
		}
	}
	return true;
}

bool Menu::draw(){
	DrawFormatString(m_pos[ARCADE],100,GetColor(0,0,0),"アーケード");
	DrawFormatString(m_pos[VS],120,GetColor(0,0,0),"バーサス");
	DrawFormatString(m_pos[PRACTICE],140,GetColor(0,0,0),"プラクティス");
	DrawFormatString(m_pos[TITLE],160,GetColor(0,0,0),"タイトル");
	return true;
}
