#ifndef SELECTH
#define SELECTH
#include"Base.h"
#define CHARANUM 4
#define CHARAWIDENUM 2


class SELECT:public Base{
	private:
		CharaID m_CharaID[2];
		CharaID m_SelectID[2];
		CharaID m_SelectChara[2];
		Select_next m_nextID;
		int CharaColor[CHARANUM];	
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Select(Select_next nextID);
		~Select();
};

#endif
