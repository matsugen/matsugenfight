#ifndef DAMMYH
#define DAMMYH
#include"Base.h"
#define COMMANDNUM 2

typedef enum{
	NONE=-1,
	SYORYU=0,
	HADO,
}CommandID;                   
typedef struct{
	InputData commandlist[16];//�F���������R�}���h�̃r�b�g��
	int Interval[16];
	int HoldTime;//�^������,0�Ń^���Ȃ�
	CommandID ID;//�R�}���h��ID(enum�Œ�`)
}CommandData;

typedef struct{
	int commandcount;
	int IntervalCount;
	int Holdcount;
}CountData;

class Dammy:public CharaState{
	private:
		CommandData m_Data[COMMANDNUM];
		CountData count_Data[COMMANDNUM];
		CommandID SearchCommand(int *Key);
		CommandID m_ID;
		void Count_Init(CountData *Data);
	public:
		bool update(int *Key);
		bool draw();
		~Dammy();
		Dammy();
};

#endif