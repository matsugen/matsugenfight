#ifndef VERSUSH
#define VERSUSH
#include"Base.h"
#define VERSUSH
#define V_MENUNUM 4


//ポーズメインメニュークラス

//バーサスモードクラス
class Versus:public Base{
	private:
		CharaState* m_chara[2];
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Versus();
		~Versus();
};

#endif