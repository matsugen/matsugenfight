//メニュー基底クラス

#ifndef BASEH
#define BASEH
typedef enum{
	V_CONTINUE,
	V_RESTART,
	V_CHARASELECT,
	V_MAINMENU,
}V_MenuID;
typedef enum{
	A_CONTINUE,
	A_RESTART,
	A_CHARASELECT,
	A_MAINMENU,
}A_MenuID;
typedef enum{
	P_CONTINUE,
	P_RESTART,
	P_CHARASELECT,
	P_MAINMENU,
}P_MenuID;
typedef enum{
	SELECT_ARCADE,
	SELECT_VERSUS,
	SELECT_PRACTICE
}Select_next;
typedef enum{
	NONE=-1,
	HARU=0,
	MIZUKI,
	LUKE,
	ZEN
}CharaID;
enum{1P,2P};

//ポーズ基底クラス
class V_Pose{
	private:
	public:
		virtual V_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,V_MenuID* MenuSignal)=0;
		virtual bool update(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool draw()=0;
		virtual ~V_Pose();
};
class A_Pose{
	private:
	public:
		virtual A_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,A_MenuID* MenuSignal)=0;
		virtual bool update(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool draw()=0;
		virtual ~A_Pose();
};
class P_Pose{
	private:
	public:
		virtual P_Pose* Seq(int *Key,bool *U_Key,bool *D_Key,P_MenuID* MenuSignal)=0;
		virtual bool update(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool draw()=0;
		virtual ~P_Pose();
};

//メニュー基底クラス
class Base{
	public:
		virtual Base* Seq(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool update(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool draw()=0;
		virtual ~Base();
};

#endif