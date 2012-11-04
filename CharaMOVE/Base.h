//メニュー基底クラス

#ifndef BASEH
#define BASEH
typedef enum{ONE,TWO}PlayerID;
typedef enum{
	L_P=(1<<0),
	L_K=(1<<1),
	H_P=(1<<2),
	H_K=(1<<3),
	NO_BUTTON=(1<<5),
	UP=(1<<6),
	B_UP=(1<<7),
	BACK=(1<<8),
	B_DOWN=(1<<9),
	DOWN=(1<<10),
	F_DOWN=(1<<11),
	FORWARD=(1<<12),
	F_UP=(1<<13),
	NEUTRAL=(1<<14)
}InputData;
//キャラステート基底クラス
class CharaState{
	protected:
		PlayerID m_PID;
		double m_posx,m_posy;
		InputData InputToArrow(int *Key);
		InputData InputToButton(int *Key);
	
		InputData tmpArrow;
		InputData tmpButton;
	public:
		virtual bool update(int *Key)=0;
		virtual bool draw()=0;
		virtual ~CharaState();
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