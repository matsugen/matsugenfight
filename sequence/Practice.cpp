//Practiceクラス
#include"Practice.h"
#include"DxLib.h"
#include"Menu.h"
#include"macro.h"
//Practiceポーズメニュー
P_PoseMenu::P_PoseMenu(){
	for(int i=0;i<MENUNUM;i++){
	m_pos[i]=200;
	}
	m_MenuID=0;
}

P_PoseMenu::~P_PoseMenu(){}
bool P_PoseMenu::update(int *Key,bool *U_Key,bool *D_Key){
	if(Key[KEY_INPUT_DOWN]%30==1&&Key[KEY_INPUT_UP]==0){
		m_MenuID=(m_MenuID+1)%P_MENUNUM;
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

P_Pose* P_PoseMenu::Seq(int *Key,bool *U_Key,bool *D_Key,P_MenuID* MenuSignal){
	P_Pose* next=this;
	if(D_Key[KEY_INPUT_S]&&!D_Key[KEY_INPUT_A]){
		switch(m_MenuID){
			case P_CONTINUE:
				next=0;
				break;
			case P_RESTART:
				next=0;//とりあえず
				break;
			case P_CHARASELECT:
				next=0;//とりあえず
				break;
			case P_MAINMENU:
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

bool P_PoseMenu::draw(){

	DrawFormatString(m_pos[P_CONTINUE],100,GetColor(0,0,0),"続ける");
	DrawFormatString(m_pos[P_RESTART],120,GetColor(0,0,0),"はじめからやり直す");
	DrawFormatString(m_pos[P_CHARASELECT],140,GetColor(0,0,0),"キャラクターセレクトへ");
	DrawFormatString(m_pos[P_MAINMENU],160,GetColor(0,0,0),"メインメニューへ");
	return true;
}


Practice::Practice(CharaID m_SelectID[2]){
	MenuSignal=0;
	m_pose=0;
}

Practice::~Practice(){
	SAFE_DELETE(m_pose);
}

Base* Practice::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	if(m_pose==0&&D_Key[KEY_INPUT_R]){
		m_pose=new P_PoseMenu();
	}
	if(m_pose!=0){
		P_Pose* Pose_next=m_pose->Seq(Key,U_Key,D_Key,&MenuSignal);
		if(Pose_next!=m_pose){
			SAFE_DELETE(m_pose);
			if(MenuSignal!=P_MAINMENU){
				m_pose=Pose_next;
			}else if(MenuSignal==P_MAINMENU){
				next=new Menu();
			}
		}
	}
	return next;
}

bool Practice::update(int *Key,bool *U_Key,bool *D_Key){
	if(m_pose!=0){
		m_pose->update(Key,U_Key,D_Key);
	}else if(m_pose==0){
		/*アップデート情報をここに*/
		/*アップデートはここまで*/
	}
	return true;
}

bool Practice::draw(){
	DrawFormatString(100,100,GetColor(0,0,0),"Practice");
	if(m_pose!=0){
		m_pose->draw();
	}
	return true;
}
