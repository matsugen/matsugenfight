//�o�[�T�X�N���X
#include"Versus.h"
#include"DxLib.h"
#include"macro.h"
#include"Dammy.h"
//�o�[�T�X�|�[�Y���j���[

//�o�[�T�X���[�h
Versus::Versus(){
	m_chara[ONE]=new Dammy();
	
}

Versus::~Versus(){	
}

Base* Versus::Seq(int *Key,bool *U_Key,bool *D_Key){
	Base* next=this;
	return next;
}

bool Versus::update(int *Key,bool *U_Key,bool *D_Key){
	/*�A�b�v�f�[�g����������*/
	m_chara[ONE]->update(Key);
	/*�A�b�v�f�[�g�͂����܂�*/
	return true;
}

bool Versus::draw(){
	m_chara[ONE]->draw();
	return true;
}
