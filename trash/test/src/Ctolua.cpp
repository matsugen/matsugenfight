/*
 * Ctolua.cpp
 *
 *  Created on: 2012/12/11
 *      Author: matsugen
 */
/*
 * Cからluaに公開する関数を定義
 */
#include"Ctolua.h"
#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include<DxLib.h>
int LoadImagefile(char *file){//ファイル名で画像読み込み
	return LoadGraph(file);
}
void String(int r,int g,int b,int x,int y,char *text){//色と座標で文字列を表示
	DrawFormatString(x,y,GetColor(r,g,b),text);
}
int LoadDivImage(int hundle,int start_x,int start_y,int end_x,int end_y){//画像のハンドルから一部を切り取る。
	int tmp_hundle;
	tmp_hundle=DerivationGraph(start_x,start_y,end_x,end_y,hundle);
	return tmp_hundle;
}
int DrawImage(int x,int y,int hundle,int direction,int Flg){//directionは左右。Flgは透過フラグ
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
int DrawCollision(int r,int g,int b,int x1,int x2,int y1,int y2){//色で矩形を半透明にして表示。switchcaseで色を種類ごとに分けるかも
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox(x1,y1,x2,y2,GetColor(r,g,b),true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,255);
	return 0;
}
bool GetSize(int hundle,int *x,int *y){//画像のサイズをハンドルから取得
	GetGraphSize(hundle,x,y);
	return true;
}
int FileOpen(char *filename){//ファイルネームから同期読み込みとしてハンドルを取得
	printf("\n FileOpen Load");
	return FileRead_open(filename,FALSE);
}
int FileRead(int file){//ハンドルから8バイトのデータを取得する。
	printf("\n FileRead Load");
	int buf;
	FileRead_read(&buf,sizeof(int),file);
	return buf;
}
int FileClose(int file){
	printf("\n FileClose Load");
	return FileRead_close(file);
}
int InitImage(){//画像ハンドルをすべて初期化
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

