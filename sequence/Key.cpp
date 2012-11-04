#include"Key.h"
#include"DxLib.h"
#include"macro.h"

Key* Key::m_Instance=0;

Key::Key(){
	m_KeyID=0;
	for(int i=0;i<256;i++){
		KeyTime[i]=0;
		Down_KeyTrigger[i]=0;
		UP_KeyTrigger[i]=0;
		tmpKey[i]=0;
		LastKey[i]=0;
	}
}

Key::~Key(){
}

Key* Key::create(){
	m_Instance=new Key();
	return m_Instance;
}
bool Key::destroy(){
	SAFE_DELETE(m_Instance);
}
bool Key::KeyState(){
	GetHitKeyStateAll(tmpKey);
	for(int i=0;i<256;i++){
		if(tmpKey[i]==0){
			if(LastKey[i]==0){
				Down_KeyTrigger[i]=false;
				UP_KeyTrigger[i]=false;	
			}else if(LastKey[i]==1){
				Down_KeyTrigger[i]=false;
				UP_KeyTrigger[i]=true;	
			}
			KeyTime[i]=0;
		}
		if(tmpKey[i]==1){
			if(LastKey[i]==0){
				Down_KeyTrigger[i]=true;
				UP_KeyTrigger[i]=false;	
			}else if(LastKey[i]==1){
				Down_KeyTrigger[i]=false;
				UP_KeyTrigger[i]=false;	
			}
			KeyTime[i]++;
		}
		LastKey[i]=tmpKey[i];
	}
	return true;
}
bool Key::KeyTimeInit(){
	for(int i=0;i<256;i++){
		KeyTime[i]=0;
	}
	return true;
}
bool Key::GetKeyState(bool *D_Key,bool *U_Key,int *Key){
	for(int i=0;i<256;i++){
		D_Key[i]=Down_KeyTrigger[i];
		U_Key[i]=UP_KeyTrigger[i];
		Key[i]=KeyTime[i];
	}
}