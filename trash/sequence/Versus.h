#ifndef VERSUSH
#define VERSUSH
#include"Base.h"
#define VERSUSH
#define V_MENUNUM 4


//ポーズメインメニュークラス
class V_PoseMenu:public V_Pose{
	private:
		V_MenuID m_MenuID;
		int m_pos[V_MENUNUM];
	public:
		V_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,V_MenuID* MenuSignal);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		~V_PoseMenu();
		V_PoseMenu();
};

//バーサスモードクラス
class Versus:public Base{
	private:
		V_MenuID MenuSignal;
		V_Pose *m_pose;
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Versus(CharaID m_SelectID[2]);
		~Versus();
};

#endif