//タイトルクラス
#ifndef TITLEH
#define TITLEH
#include"Base.h"

class Title:public Base{
	private:
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Title();
		~Title();
};

#endif