//アーケードクラス
#include"Arcade.h"
#include"DxLib.h"
#include"Menu.h"
#include"macro.h"
//アーケードポーズメニュー
A_PoseMenu::A_PoseMenu(){
	for(int i=0;i<MENUNUM;i++){
	m_pos[i]=200;
	}
	m_MenuID=0;
}
  
A_PoseMenu::~A_PoseMenu(){}
bool A_PoseMenu::update(int *Key,bool *U_Key,bool *D_Key){
	if(Key[KEY_INPUT_DOWN]%30==1&&Key[KEY_INPUT_UP]==0){
		m_MenuID=(m_MenuID+1)%A_MENUNUM;
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

A_Pose* A_PoseMenu::Seq(int *Key,bool *U_Key,bool *D_Key,A_MenuID* MenuSignal){
	A_Pose* next=this;
	if(D_Key[KEY_INPUT_S]&&!D_Key[KEY_INPUT_A]){
		switch(m_MenuID){
			case A_CONTINUE:
				next=0;
				break;
			case A_RESTART:
				next=0;//とりあえず
				break;
			case A_CHARASELECT:
				next=0;//とりあえず
				break;
			case A_MAINMENU:
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

bool A_PoseMenu::draw(){

	DrawFormatString(m_pos[A_CONTINUE],100,GetColor(0,0,0),"続ける");
	DrawFormatString(m_pos[A_RESTART],120,GetColor(0,0,0),"はじめからやり直す");
	DrawFormatString(m_pos[A_CHARASELECT],140,GetColor(0,0,0),"キャラクターセレクトへ");
	DrawFormatString(m_pos[A_MAINMENU],160,GetColor(0,0,0),"メインメニューへ");
	return true;
}

//アーケードモード
Arcade::Arcade(CharaID m_SelectID[2]){
	MenuSignal=0;
	m_pose=0;
}

Arcade::~Arcade(){
	SAFE_DELETE(m_pose);
}

Base* Arcade::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(m_pose==0&&D_Key[KEY_INPUT_R]){
		m_pose=new A_PoseMenu();
	}
	if(m_pose!=0){
		A_Pose* Pose_next=m_pose->Seq(Key,U_Key,D_Key,&MenuSignal);
		if(Pose_next!=m_pose){
			SAFE_DELETE(m_pose);
			if(MenuSignal!=A_MAINMENU){
				m_pose=Pose_next;
			}else if(MenuSignal==A_MAINMENU){
				next=new Menu();
			}
		}
	}
	return next;
}

bool Arcade::update(int *Key,bool *U_Key,bool *D_Key){
	if(m_pose!=0){
		m_pose->update(Key,U_Key,D_Key);
	}else if(m_pose==0){
		/*アップデート情報をここに*/
		/*アップデートはここまで*/
		}
	return true;
}

bool Arcade::draw(){
	DrawFormatString(100,100,GetColor(0,0,0),"Arcade");
	if(m_pose!=0){
		m_pose->draw();
	}
	return true;
}
