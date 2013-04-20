//オープニングクラス
#ifndef OPENINGH
#define OPENINGH

#include"Base.h"

class Opening:public Base{
	private:
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Opening();
		~Opening();
};

#endif