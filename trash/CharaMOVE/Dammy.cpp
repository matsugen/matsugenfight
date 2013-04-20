#include"Dammy.h"
#include"DxLib.h"

Dammy::Dammy(){ 
	m_Data[HADO].commandlist[0]=DOWN;
	m_Data[HADO].commandlist[1]=F_DOWN;
	m_Data[HADO].commandlist[2]=FORWARD;
	for(int i=3;i<16;i++){
		m_Data[HADO].commandlist[i]=0;
	}
	m_Data[HADO].Interval[0]=20;
	m_Data[HADO].Interval[1]=20;
	m_Data[HADO].Interval[2]=20;
	for(int i=3;i<16;i++){
		m_Data[HADO].Interval[i]=0;
	}
	m_Data[SYORYU].commandlist[0]=FORWARD;
	m_Data[SYORYU].commandlist[1]=DOWN;
	m_Data[SYORYU].commandlist[2]=FORWARD|F_DOWN,0;
	for(int i=3;i<16;i++){
		m_Data[SYORYU].commandlist[i]=0;
	}
	m_Data[SYORYU].Interval[0]=20;
	m_Data[SYORYU].Interval[1]=20;
	m_Data[SYORYU].Interval[2]=20;
	for(int i=3;i<16;i++){
		m_Data[SYORYU].Interval[i]=0;
	}
	m_Data[HADO].HoldTime=0;
	m_Data[SYORYU].HoldTime=0;
	m_Data[HADO].ID=HADO;
	m_Data[SYORYU].ID=SYORYU;
	count_Data[HADO].commandcount=0;
	count_Data[SYORYU].commandcount=0;
	count_Data[HADO].Holdcount=0;
	count_Data[SYORYU].Holdcount=0;
	count_Data[HADO].IntervalCount=0;
	count_Data[SYORYU].IntervalCount=0;
}

Dammy::~Dammy(){}

bool Dammy::update(int *Key){
	static ID_time=0;
	if(m_ID==NONE||ID_time<=0){
		m_ID=SearchCommand(Key);
		ID_time=20;
	}else{
		ID_time--;
	}
	return true;	
}
bool Dammy::draw(){
	switch(m_ID){
	case HADO:	DrawFormatString(0,200,GetColor(0,0,0),"HADO");
			break;
	case SYORYU:	DrawFormatString(0,200,GetColor(0,0,0),"SYORYU");
			break;
	}
	return true;	
}

CommandID Dammy::SearchCommand(int *Key){
	InputData tmpArrow;
	InputData tmpButton;
	tmpArrow=InputToButton(Key);
	tmpButton=InputToButton(Key);
	//�ȏ�œ��͂ɑ΂���r�b�g����擾
	/*�����L�[�̃R�}���h�F��*/
	for(int i=1;i<COMMANDNUM;i++){//���ׂĂ̋Z������
		if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)>0){//�����L�[�̈�v����
			if(count_Data[i].Holdcount<m_Data[i].HoldTime){//�^�����Ԃ�����Ă��Ȃ���΃^�����Ԃ����Z
				count_Data[i].Holdcount++;
 			}else if(count_Data[i].Holdcount==m_Data[i].HoldTime){//�^�����Ԃ�����Ă���΃R�}���h�F���̃J�E���^�����߂�
				count_Data[i].commandcount++;
				count_Data[i].IntervalCount=m_Data[i].Interval[count_Data[i].commandcount];
			}
		}else if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)==0){
			if(count_Data[i].IntervalCount>0){//���͗P�\��0�łȂ���Ό��Z
				count_Data[i].IntervalCount--;
			}else if(count_Data[i].IntervalCount==0){//���͗P�\���؂�Ă����ꍇ�J�E���^��������
				Count_Init(&(count_Data[i]));
			}
		}
	}
	/*�{�^���̃R�}���h�F��*/
	for(int i=0;i<COMMANDNUM;i++){
		if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)>tmpButton){//�����L�[�̈�v����
			if(count_Data[i].Holdcount<m_Data[i].HoldTime){//�^�����Ԃ�����Ă��Ȃ���΃^�����Ԃ����Z
				count_Data[i].Holdcount++;
 			}else if(count_Data[i].Holdcount==m_Data[i].HoldTime){//�^�����Ԃ�����Ă���΃R�}���h�F���̃J�E���^�����߂�
				count_Data[i].commandcount++;
				count_Data[i].IntervalCount=m_Data[i].Interval[count_Data[i].commandcount];
			}
		}else if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpButton)==0){
			if(count_Data[i].IntervalCount>0){//���͗P�\��0�łȂ���Ό��Z
				count_Data[i].IntervalCount--;
			}else if(count_Data[i].IntervalCount==0){//���͗P�\���؂�Ă����ꍇ�J�E���^��������
				Count_Init(&(count_Data[i]));
			}
		}
	}
	for(int i=0;i<COMMANDNUM;i++){
		if(m_Data[i].commandlist[count_Data[i].commandcount]==0){//�R�}���h�F�����I�������ꍇ�ȍ~�̃R�}���h�J�E���^������������
			for(int j=i;j<COMMANDNUM;j++){
				Count_Init(&(count_Data[j]));
			}
			return m_Data[i].ID;
		}
	}
		return NONE;	
}

void Dammy::Count_Init(CountData *Data){
	Data->IntervalCount=0;
	Data->commandcount=0;
	Data->Holdcount=0;
}


