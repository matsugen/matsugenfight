#include"DxLib.h"

int KeyTime(int *time){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	int i;
	for(i=0;i<256;i++){
		GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
		if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			*(time+i)+=1;     // ���Z
		} else {              // ������Ă��Ȃ����
			*(time+i)= 0;   // 0�ɂ���
		}
	}
	return *time;
}
