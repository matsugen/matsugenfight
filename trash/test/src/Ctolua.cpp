/*
 * Ctolua.cpp
 *
 *  Created on: 2012/12/11
 *      Author: matsugen
 */
/*
 * C����lua�Ɍ��J����֐����`
 */
#include"Ctolua.h"
#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include<DxLib.h>
int LoadImagefile(char *file){//�t�@�C�����ŉ摜�ǂݍ���
	return LoadGraph(file);
}
void String(int r,int g,int b,int x,int y,char *text){//�F�ƍ��W�ŕ������\��
	DrawFormatString(x,y,GetColor(r,g,b),text);
}
int LoadDivImage(int hundle,int start_x,int start_y,int end_x,int end_y){//�摜�̃n���h������ꕔ��؂���B
	int tmp_hundle;
	tmp_hundle=DerivationGraph(start_x,start_y,end_x,end_y,hundle);
	return tmp_hundle;
}
int DrawImage(int x,int y,int hundle,int direction,int Flg){//direction�͍��E�BFlg�͓��߃t���O
	if(hundle==-1){
		return -1;
	}else{
		switch(direction){
		case DIRECTION_LEFT:DrawTurnGraph(x,y,hundle,Flg);
			break;
		case DIRECTION_RIGHT:DrawGraph(x,y,hundle,Flg);
			break;
		}
	}
	return 0;
}
int DrawCollision(int r,int g,int b,int x1,int x2,int y1,int y2){//�F�ŋ�`�𔼓����ɂ��ĕ\���Bswitchcase�ŐF����ނ��Ƃɕ����邩��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox(x1,y1,x2,y2,GetColor(r,g,b),true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	return 0;
}
bool GetSize(int hundle,int *x,int *y){//�摜�̃T�C�Y���n���h������擾
	GetGraphSize(hundle,x,y);
	return true;
}
int FileOpen(char *filename){//�t�@�C���l�[�����瓯���ǂݍ��݂Ƃ��ăn���h�����擾
	printf("\n FileOpen Load");
	return FileRead_open(filename,FALSE);
}
int FileRead(int file){//�n���h������8�o�C�g�̃f�[�^���擾����B
	printf("\n FileRead Load");
	int buf;
	FileRead_read(&buf,sizeof(int),file);
	return buf;
}
int FileClose(int file){
	printf("\n FileClose Load");
	return FileRead_close(file);
}
int InitImage(){//�摜�n���h�������ׂď�����
	return InitGraph();
}
int XOR(int x,int y){
	return x^y;
}
int AND(int x,int y){
	return x&y;
}
int OR(int x,int y){
	return x|y;
}
int NOT(int x){
	return ~x;
}
int LSHIFT(int x,int number){
	return x<<number;
}
int RSHIFT(int x,int number){
	return x>>number;
}
Key::Key(){
	KeyUp=KeyDown=last_Key=KeyPush=0;
}
Key::~Key(){

}
int Key::KeyState(){
	int i;
	char tmp_Key[256];
	GetHitKeyStateAll(tmp_Key);
	KeyPush=0;
	for(i=0;i<8;i++){
		KeyPush|=tmp_Key[Keymember[i]]<<i;
	}
	KeyUp=(~KeyPush)&last_Key;
	KeyDown=KeyPush&(~last_Key);
	last_Key=KeyPush;
	return 0;
}
int Key::GetPush(){
	return KeyPush;
}
int Key::GetDown(){
	return KeyDown;
}
int Key::GetUp(){
	return KeyUp;
}

