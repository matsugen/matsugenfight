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
	//以上で入力に対するビット列を取得
	/*方向キーのコマンド認識*/
	for(int i=1;i<COMMANDNUM;i++){//すべての技を見る
		if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)>0){//方向キーの一致判定
			if(count_Data[i].Holdcount<m_Data[i].HoldTime){//タメ時間が足りていなければタメ時間を加算
				count_Data[i].Holdcount++;
 			}else if(count_Data[i].Holdcount==m_Data[i].HoldTime){//タメ時間が足りていればコマンド認識のカウンタを勧める
				count_Data[i].commandcount++;
				count_Data[i].IntervalCount=m_Data[i].Interval[count_Data[i].commandcount];
			}
		}else if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)==0){
			if(count_Data[i].IntervalCount>0){//入力猶予が0でなければ減算
				count_Data[i].IntervalCount--;
			}else if(count_Data[i].IntervalCount==0){//入力猶予が切れていた場合カウンタを初期化
				Count_Init(&(count_Data[i]));
			}
		}
	}
	/*ボタンのコマンド認識*/
	for(int i=0;i<COMMANDNUM;i++){
		if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpArrow)>tmpButton){//方向キーの一致判定
			if(count_Data[i].Holdcount<m_Data[i].HoldTime){//タメ時間が足りていなければタメ時間を加算
				count_Data[i].Holdcount++;
 			}else if(count_Data[i].Holdcount==m_Data[i].HoldTime){//タメ時間が足りていればコマンド認識のカウンタを勧める
				count_Data[i].commandcount++;
				count_Data[i].IntervalCount=m_Data[i].Interval[count_Data[i].commandcount];
			}
		}else if((m_Data[i].commandlist[count_Data[i].commandcount]&tmpButton)==0){
			if(count_Data[i].IntervalCount>0){//入力猶予が0でなければ減算
				count_Data[i].IntervalCount--;
			}else if(count_Data[i].IntervalCount==0){//入力猶予が切れていた場合カウンタを初期化
				Count_Init(&(count_Data[i]));
			}
		}
	}
	for(int i=0;i<COMMANDNUM;i++){
		if(m_Data[i].commandlist[count_Data[i].commandcount]==0){//コマンド認識が終了した場合以降のコマンドカウンタを初期化する
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


