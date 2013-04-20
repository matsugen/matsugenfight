/*
 * collision.cpp
 *
 *  Created on: 2012/12/28
 *      Author: matsugen
 */
#include"collision.h"
#include<stdio.h>
#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include<DxLib.h>



Attack::Attack(){//�t�@�C�������画��N���X���C���X�^���X��
	x1=0,x2=0;//lua�ɓ������₷���悤�z����g��Ȃ��B
	y1=0,y2=0;
	g_vx=0,g_vy=0;
	a_vx=0,a_vy=0;//�q�b�g���̐�����ѕ����Ƒ��xg_�͒n��q�b�g,a_�͋󒆃q�b�g
	type=0;//�U���̎�ނ��r�b�g���Z�ł����Ȃ��B�Ō�1<<0 ����1<<2 ����1<<3 ���K�[�h�s��1<<4 �����K�[�h�s��1<<5 ��g�\�_�E��1<<6 ��g�s�_�E�� 1<<7
	damage=0;//�_���[�W
	point=0;//�팸�l�B���̐��l�Œǌ��\���ǂ����𔻒�
	time=0;//�̂����莞��
}
Attack::Attack(int file){//�t�@�C�������画��N���X���C���X�^���X��
	/*
	 * lua���Ŕ��萔��(Attack��Push��Hit)*n�̏��ɓǂݍ���
	 * 1�X�v���C�g�̔�������ׂĎ擾������A���̔��肩��ڍs�ł���X�v���C�g�̖��O���擾����B
	 */
	printf("\n\tAttack_construct");
	FileRead_read(&x1,sizeof(int),file);
	FileRead_read(&x2,sizeof(int),file);
	FileRead_read(&y1,sizeof(int),file);
	FileRead_read(&y2,sizeof(int),file);
	FileRead_read(&g_vx,sizeof(int),file);
	FileRead_read(&g_vy,sizeof(int),file);
	FileRead_read(&a_vx,sizeof(int),file);
	FileRead_read(&a_vy,sizeof(int),file);
	FileRead_read(&type,sizeof(int),file);
	FileRead_read(&damage,sizeof(int),file);
	FileRead_read(&time,sizeof(int),file);
	FileRead_read(&point,sizeof(int),file);
}
Attack::~Attack(){
	printf("\n\tAttack_destruct");
}
int Attack::GetRect(int* a1,int* a2,int* b1,int* b2){//�����`�̎擾
	*a1=x1;
	*a2=x2;
	*b1=y1;
	*b2=y2;
	return 0;
}
int Attack::GetType(){//�U���^�C�v�̎擾
	return type;
}
int Attack::GetDamage(){//�_���[�W�̎擾
	return damage;
}
int Attack::AirHit(int* vx,int* vy,int* p){//�팸�l�̎擾
	*vx=a_vx;
	*vy=a_vy;
	*p=point;
	return 0;
}
int Attack::GroundHit(int* vx,int* vy,int* t,int *p){//�팸�l�̎擾
	*vx=g_vx;
	*vy=g_vy;
	*t=time;
	*p=point;
	return 0;
}

Hit::Hit(){//�t�@�C�������画��N���X���C���X�^���X��
	printf("\n\tHit_construct");
	x1=0,x2=0;//lua�ɓ������₷���悤�z����g��Ȃ��B
	y1=0,y2=0;
	type=0;
}

Hit::Hit(int file){//�t�@�C�������画��N���X���C���X�^���X��
	printf("\n\tHit_construct");
	FileRead_read(&x1,sizeof(int),file);
	FileRead_read(&x2,sizeof(int),file);
	FileRead_read(&y1,sizeof(int),file);
	FileRead_read(&y2,sizeof(int),file);
	FileRead_read(&type,sizeof(int),file);
}

Hit::~Hit(){
	printf("\n\tHit_destruct");
}

int Hit::GetRect(int *a1,int *a2,int *b1,int *b2){//�����`�̎擾
	*a1=x1;
	*a2=x2;
	*b1=y1;
	*b2=y2;
	return 0;
}

int Hit::GetType(){
	return type;
}
Push::Push(){//�t�@�C�������画��N���X���C���X�^���X��
	x1=0,x2=0;//lua�ɓ������₷���悤�z����g��Ȃ��B
	y1=0,y2=0;
}

Push::Push(int file){//�t�@�C�������画��N���X���C���X�^���X��
	printf("\n\tPush_construct");
	FileRead_read(&x1,sizeof(int),file);
	FileRead_read(&x2,sizeof(int),file);
	FileRead_read(&y1,sizeof(int),file);
	FileRead_read(&y2,sizeof(int),file);
}

Push::~Push(){
	printf("\n\tPush_destruct");
}
int Push::GetRect(int *a1,int *a2,int *b1,int *b2){//�����`�̎擾
	*a1=x1;
	*a2=x2;
	*b1=y1;
	*b2=y2;
	return 0;
}
State::State(){
	axis=0,type=0;
	vx=vy=0;
	time=0;
}
State::State(int file){
	printf("\n\tState_constructor");
	FileRead_read(&axis,sizeof(int),file);
	FileRead_read(&type,sizeof(int),file);
	FileRead_read(&vx,sizeof(int),file);
	FileRead_read(&vy,sizeof(int),file);
	FileRead_read(&time,sizeof(int),file);
}


int State::GetType(){
	return type;
}
int State::GetAxis(){//���莲�̎擾
	return axis;
}
int State::GetSpeed(int *x,int *y){
	*x=vx;
	*y=vy;
	return 0;
}
int State::GetTime(){
	return time;
}
State::~State(){
	printf("\n\tState_destructor");
}
