#include"set.h"
#include"DxLib.h"
#include"macro.h"
#include<assert.h>
#include"Base.h"
#include"Versus.h"



//Mainloopのメンバ関数

Mainloop* Mainloop::m_Instance=0;
Mainloop::Mainloop(){
	for(int i=0;i<256;i++){
		KeyTime[i]=0;
		D_Key[i]=U_Key[i]=false;
	}
	m_tmptime=0;
	state=new Versus();
	KeyApp=KeyApp->create();
}

Mainloop::~Mainloop(){
	KeyApp->destroy();
	SAFE_DELETE(state);
}

bool Mainloop::Seq(){
	KeyApp->KeyState();
	KeyApp->GetKeyState(D_Key,U_Key,KeyTime);
	m_tmptime=GetNowCount();
	Base* next=state->Seq(KeyTime,U_Key,D_Key);
	if(next!=state){
		KeyApp->KeyTimeInit();
		SAFE_DELETE(state);
		state=next;
	}
	return true;
}

bool Mainloop::update(){
	m_tmptime=GetNowCount();
	state->update(KeyTime,U_Key,D_Key);
	return true;
}



Mainloop* Mainloop::create(){
	assert(!m_Instance);
	m_Instance=new Mainloop();
	return m_Instance;
}                             

bool Mainloop::destroy(){
	SAFE_DELETE(m_Instance);
	return true;
}

bool Mainloop::Debug(){
		static float mFps=0;             //fpsカウンタ
		static int mCount=0;		//カウンタ
		static const int N=60;
		static int mStarttime=0;
		static int mEndtime=0;
		if(mCount==0){
			mStarttime=GetNowCount();
		}
		if(mCount==N){
			mEndtime=GetNowCount();
			mFps = 1000.0f/((mEndtime-mStarttime)/(float)N);
			mCount=0;	
		}else{
			mCount++;
		}
		if(mFps!=0){
			DrawFormatString(0, 0, GetColor(0,0,0), "%.1f",mFps);
		}else{
			DrawFormatString(0, 0, GetColor(0,0,0), "測定中");
		}
	return true;
}

bool Mainloop::wait(){
	int t;
	while(GetNowCount()-m_tmptime<(1000/m_Fps)){};
	return true;
}

bool Mainloop::draw(){
	state->draw();
	return true;
}