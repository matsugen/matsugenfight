#ifndef PRACTICEH
#define PRACTICEH
#include"Base.h"
#define PRACTICEH
#define P_MENUNUM 4


//ポーズメインメニュークラス
class P_PoseMenu:public P_Pose{
	private:
		P_MenuID m_MenuID;
		int m_pos[P_MENUNUM];
	public:
		P_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,P_MenuID* MenuSignal);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		~P_PoseMenu();
		P_PoseMenu();
};
class Practice:public Base{
	private:
		P_MenuID MenuSignal;
		P_Pose* m_pose;
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Practice(CharaID m_SelectID[2]);
		~Practice();
};

#endif
