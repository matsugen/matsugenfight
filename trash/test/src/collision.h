/*
 * collision.h
 *
 *  Created on: 2012/12/26
 *      Author: matsugen
 */

#ifndef COLLISION_H_
#define COLLISION_H_
#include<stdio.h>

/*
 * �U������N���X
 */
class Attack{//tolua_export
private:
	int x1,x2;//lua�ɓ������₷���悤�z����g��Ȃ��B
	int y1,y2;
	int g_vx,g_vy,a_vx,a_vy;//�q�b�g���̐�����ѕ����Ƒ��xg_�͒n��q�b�g,a_�͋󒆃q�b�g
	int type;//�U���̎�ނ��r�b�g���Z�ł����Ȃ��B�Ō�1<<0 ����1<<1 ����1<<2 ���b�N1<<3 ���K�[�h�s�\1<<4 �����K�[�h�s�\1<<5 �_�E��1<<6 �����_�E��1<<7
	int damage;//�_���[�W
	int point;//�팸�l�B���̐��l�Œǌ��\���ǂ����𔻒�
	int time;//�̂����莞��
public:
	//tolua_begin
	Attack();
	Attack(int file);
	~Attack();
	int GetRect(int* a1,int* a2,int* b1,int* b2);//�����`�̎擾
	int GetType();//�U���^�C�v�̎擾
	int GetDamage();//�_���[�W�̎擾
	int AirHit(int* vx,int* vy,int* p);//�󒆃q�b�g���̐�����ѕ����A�팸�l�̎擾
	int GroundHit(int* vx,int* vy,int* t,int* p);//�n��q�b�g���̐�����ѕ����Ƃ̂����莞�ԁBlua����vy>0�̂Ƃ��͂̂����莞�Ԃ��l���Ȃ�

};
//tolua_end

/*
 * �����o������N���X
 */
class Push{//tolua_export
private:
	int x1,x2,y1,y2;//�����o������̋�`
public:
	//tolua_begin
	Push();
	Push(int file);
	~Push();
	int GetRect(int *a1,int *a2,int *b1,int *b2);//�����`�̎擾
};
//tolua_end
/*
 * �H�炢����N���X
 */
class Hit{//tolua_export
private:
	int x1,x2,y1,y2;//���炢����̋�`
	int type;//���G�̃r�b�g�� �ΑŌ�1<<0 �Γ���1<<1
public://tolua_begin
	Hit();
	Hit(int file);
	~Hit();
	int GetRect(int *a1,int *a2,int *b1,int *b2);//�����`�̎擾
	int GetType();
};
//tolua_end
/*
 * ��ԃN���X
 */

class State{//tolua_export
private:
	int axis;//�L������
	int type;//��Ԃ̃r�b�g�� �������G1<<0 �󒆔���1<<1 �s���\1<<2 �K�[�h�\1<<3 ...
	int vx,vy;//�L�������̂̈ړ����x�E����
	int time;//�����t���[��
public:
	//tolua_begin
	State();
	State(int file);
	~State();
	int GetAxis();//�L�������擾
	int GetType();
	int GetSpeed(int *x,int *y);
	int GetTime();
};
//tolua_end
#endif /* COLLISION_H_ */
