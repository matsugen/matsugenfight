//ポーズ基底クラス
#ifndef BASEH
#define BASEH

class Basa_Pose{
	public:
		virtual bool update(int *Key,bool *U_Key,bool *D_Key)=0;
		virtual bool draw()=0;
		virtual ~Basa_Pose();
};

#endif
