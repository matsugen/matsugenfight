#ifndef PLAYER
#define PLAYER

class Player{
public:
	int HP,PG,RG;//�̗�,�p���[�Q�[�W,����Q�[�W
	double posx,posy,vx,vy;//�L�����̈ʒu�ƈړ����x
	int jmp,GD,pose,attack,air,UGD;//�L������Ԃ̃t���O�ϐ�
	/*
	jmp:�W�����v��(1)����(0)��
	GD:�K�[�h��(1)����(0)��
	pose:���Ⴊ��(1)or����(0)
	attack:�U����(1)����(0)��
	air:�󒆔���(1)����(0)��
	UGD:�K�[�h�s�\(1)���\(0)��
	*/
	int vsthrow,vsRG,vsknock//���G��ԃt���O�ϐ�
	/*
	vsthrow:�������G
	vsRG:����Q�[�W�g�p�Z���G
	vsknock:�Ō����G
	*/
}                  


#endif