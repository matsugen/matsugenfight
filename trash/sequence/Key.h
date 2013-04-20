#ifndef KEY
#define KEY

typedef enum{
	A=(1<<0),//A
	B=(1<<1),//B
	C=(1<<2),//C
	D=(1<<3),//D
	E=(1<<4),//E
	F=(1<<5),//F
	UP=(1<<6),
	DOWN=(1<<7),
	LEFT=(1<<8),
	RIGHT=(1<<9),
	Start=(1<<10),//Start
	Select=(1<<11),//Select
}KeyID;

class Key{
	private:
		int m_KeyID;
		int KeyTime[256];
		static Key* m_Instance;
		bool Down_KeyTrigger[256];
		bool UP_KeyTrigger[256];
		char tmpKey[256];
		char LastKey[256];
		Key(const Key& r);
		Key& operator=(const Key& r);
		Key();
		~Key();
	public:
		static Key* create();
		static bool destroy();
		bool KeyState();
		bool KeyTimeInit();
		bool GetKeyState(bool *D_Key,bool *U_Key,int *Key);			
};
#endif
