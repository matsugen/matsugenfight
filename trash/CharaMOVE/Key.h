#ifndef KEY
#define KEY
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
