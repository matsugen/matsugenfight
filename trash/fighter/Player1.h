#ifndef PLAYER
#define PLAYER
#include"macro.h"
#include"Dxlib.h"
#define REDUCE 10
#define SIZEX 72.0f
#define SIZEY 196.0f
#define MOVESPEED  3.0f
#define GRAVITY 2.5f


class Player{
private:
public:
	int HP,RG,PG;//�̗́E����Q�[�W�E�p���[�Q�[�W
	double posx,posy;//�摜�̍���̍��W
	double vx,vy;//�ړ����x
	bool air,Guard,Counter;//�󒆔���E�K�[�h��ԁE��J�E���^�[��ԃt���O
	bool walk,jmp,Control,UnGuard;//���s��ԁE�W�����v��ԁE�R���g���[���\��ԁE�K�[�h�s�\��ԃt���O
	bool Rmode;//���ꃂ�[�h��ԃt���O
	int img[MAXBUF][MAXBUF][MAXBUF],Image;//�C���[�W��ۊǂ���ϐ��ƁA�\������C���[�W�n���h�����i�[����ϐ�
	class Hit{//�����蔻��\����
		public: 
			double x[MAXBUF][MAXBUF][2],y[MAXBUF][MAXBUF][2];//�����蔻��̔����x���W�Ey���W
			bool vsattack[MAXBUF][MAXBUF],vsth[MAXBUF][MAXBUF],vsren[MAXBUF][MAXBUF];//�e���薈�̖��G�t���O
			double position[MAXBUF];//�L�������̍��W
			Hit(){}
	} *H;
	class Attack{//�U������\����
		public:
			double x[MAXBUF][MAXBUF][2],y[MAXBUF][MAXBUF][2];//�U�������x���W,y���W
			bool attack[MAXBUF][MAXBUF],th[MAXBUF][MAXBUF],ren[MAXBUF][MAXBUF];//�e���育�Ƃ̍U���t���O
			Attack(){}
	} *A;
	void Mode(){
		if(Rmode){
			RG-=REDUCE;
		}else if(!Rmode){}
		if(RG<=0){
			RG=0;
			Rmode=false;
		}
	}
	Player(){}
	virtual ~Player(){}
};

#endif