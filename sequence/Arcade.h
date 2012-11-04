#ifndef ARCADEH
#define ARCADEH
#include"Base.h"
#define ARCADEH
#define A_MENUNUM 4


//ポーズメインメニュークラス
class A_PoseMenu:public A_Pose{
	private:
		A_MenuID m_MenuID;
		int m_pos[A_MENUNUM];
	public:
		A_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,A_MenuID* MenuSignal);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		~A_PoseMenu();
		A_PoseMenu();
};

//アーケードモードクラス
class Arcade:public Base{
	private:
		A_MenuID MenuSignal;
		A_Pose* m_pose;
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Arcade(CharaID m_SelectID[2]);
		~Arcade();
};

#endif