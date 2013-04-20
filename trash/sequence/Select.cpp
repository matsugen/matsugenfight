//キャラクターセレクト
#include"DxLib.h"
#include"Select.h"


Base* Select::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if((m_SelectID[1P]!=NONE)&&(m_SelectID[2P]!=NONE)){
		switch(m_nextID){
			case SELECT_ARCADE:
				next=new Arcade(CharaID m_SelectID);
				break;
			case SELECT_VERSUS:
				next=new Versus(CharaID m_SelectID);
				break;
			case SELECT_PRACTICE:
				next=new Practice(CharaID m_SelectID);
				break;
		}
	}
	return next;
};
bool Select::update(int *Key,bool *U_Key,bool *D_Key){
}
bool Select::draw()
Select::Select(Select_next nextID){
	m_SelectID[1P]=m_SelectID[2P]=NONE;
	m_CharaID[1P]=HARU;
	m_CharaID[2P]=MIZUKI;
	m_nextID=nextID;
}
Select::~Select(){}


