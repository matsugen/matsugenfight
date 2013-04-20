//バーサスクラス
#include"Versus.h"
#include"DxLib.h"
#include"Menu.h"
#include"macro.h"
//バーサスポーズメニュー
V_PoseMenu::V_PoseMenu(){
	for(int i=0;i<MENUNUM;i++){
	m_pos[i]=200;
	}
	m_MenuID=0;	
}
V_PoseMenu::~V_PoseMenu(){}

bool V_PoseMenu::update(int *Key,bool *U_Key,bool *D_Key){
	if(Key[KEY_INPUT_DOWN]%30==1&&Key[KEY_INPUT_UP]==0){
		m_MenuID=(m_MenuID+1)%V_MENUNUM;
	}else if(Key[KEY_INPUT_UP]%30==1&&Key[KEY_INPUT_DOWN]==0){
		m_MenuID=(m_MenuID+MENUNUM-1)%MENUNUM;
	}
	m_pos[m_MenuID]=180;
	for(int i=0;i<MENUNUM;i++){
		if(i!=m_MenuID){
			m_pos[i]=200;
		}
	}
}

V_Pose* V_PoseMenu::Seq(int *Key,bool *U_Key,bool *D_Key,V_MenuID* MenuSignal){
	V_Pose* next=this;
	if(D_Key[KEY_INPUT_S]&&!D_Key[KEY_INPUT_A]){
		switch(m_MenuID){
			case V_CONTINUE:
				next=0;
				break;
			case V_RESTART:
				next=0;//とりあえず
				break;
			case V_CHARASELECT:
				next=0;//とりあえず
				break;
			case V_MAINMENU:
				next=0;
				break;
			default:
				next=this; 
				break;
		}
	}else if(!D_Key[KEY_INPUT_S]&&D_Key[KEY_INPUT_A]){
		next=0;
	}
	*MenuSignal=m_MenuID;
	return next;
}

bool V_PoseMenu::draw(){

	DrawFormatString(m_pos[V_CONTINUE],100,GetColor(0,0,0),"続ける");
	DrawFormatString(m_pos[V_RESTART],120,GetColor(0,0,0),"はじめからやり直す");
	DrawFormatString(m_pos[V_CHARASELECT],140,GetColor(0,0,0),"キャラクターセレクトへ");
	DrawFormatString(m_pos[V_MAINMENU],160,GetColor(0,0,0),"メインメニューへ");
	return true;
}
//バーサスモード
Versus::Versus(CharaID m_SelectID[2]){
	MenuSignal=0;
	m_pose=0;
}

Versus::~Versus(){
	SAFE_DELETE(m_pose);	
}

Base* Versus::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(m_pose==0&&D_Key[KEY_INPUT_R]){
		m_pose=new V_PoseMenu();
	}
	if(m_pose!=0){
		V_Pose* Pose_next=m_pose->Seq(Key,U_Key,D_Key,&MenuSignal);
		if(Pose_next!=m_pose){
			SAFE_DELETE(m_pose);
			if(MenuSignal!=V_MAINMENU){
				m_pose=Pose_next;
			}else if(MenuSignal==V_MAINMENU){
				next=new Menu();
			}
		}
	}
	return next;
}

bool Versus::update(int *Key,bool *U_Key,bool *D_Key){
	if(m_pose!=0){
		m_pose->update(Key,U_Key,D_Key);
	}else if(m_pose==0){
		/*アップデート情報をここに*/
		/*アップデートはここまで*/
		if(D_Key[KEY_INPUT_R]){
			m_pose=new V_PoseMenu();
		}
	}
	return true;
}

bool Versus::draw(){
	DrawFormatString(100,80,GetColor(0,0,0),"Versus");
	if(m_pose!=0){
		m_pose->draw();
	}
	return true;
}
