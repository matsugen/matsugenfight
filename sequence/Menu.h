#ifndef MENUH
#define MENUH
#include"Base.h"
#define MENUNUM 4
typedef enum{
	ARCADE,
	VS,
	PRACTICE,
	TITLE,
}MenuID;

class Menu:public Base{
	private:
		int m_pos[MENUNUM];
		MenuID m_MenuID;
	public:
		Base* Seq(int *Key,bool *U_Key,bool *D_Key);
		bool update(int *Key,bool *U_Key,bool *D_Key);
		bool draw();
		Menu();
		~Menu();
};

#endif