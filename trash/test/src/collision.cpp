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



Attack::Attack(){//ファイル名から判定クラスをインスタンス化
	x1=0,x2=0;//luaに導入しやすいよう配列を使わない。
	y1=0,y2=0;
	g_vx=0,g_vy=0;
	a_vx=0,a_vy=0;//ヒット時の吹き飛び方向と速度g_は地上ヒット,a_は空中ヒット
	type=0;//攻撃の種類をビット演算でおこなう。打撃1<<0 特殊1<<2 投げ1<<3 屈ガード不可1<<4 立ちガード不可1<<5 受身可能ダウン1<<6 受身不可ダウン 1<<7
	damage=0;//ダメージ
	point=0;//削減値。この数値で追撃可能かどうかを判定
	time=0;//のけぞり時間
}
Attack::Attack(int file){//ファイル名から判定クラスをインスタンス化
	/*
	 * lua側で判定数→(Attack→Push→Hit)*nの順に読み込む
	 * 1スプライトの判定をすべて取得したら、その判定から移行できるスプライトの名前を取得する。
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
int Attack::GetRect(int* a1,int* a2,int* b1,int* b2){//判定矩形の取得
	*a1=x1;
	*a2=x2;
	*b1=y1;
	*b2=y2;
	return 0;
}
int Attack::GetType(){//攻撃タイプの取得
	return type;
}
int Attack::GetDamage(){//ダメージの取得
	return damage;
}
int Attack::AirHit(int* vx,int* vy,int* p){//削減値の取得
	*vx=a_vx;
	*vy=a_vy;
	*p=point;
	return 0;
}
int Attack::GroundHit(int* vx,int* vy,int* t,int *p){//削減値の取得
	*vx=g_vx;
	*vy=g_vy;
	*t=time;
	*p=point;
	return 0;
}

Hit::Hit(){//ファイル名から判定クラスをインスタンス化
	printf("\n\tHit_construct");
	x1=0,x2=0;//luaに導入しやすいよう配列を使わない。
	y1=0,y2=0;
	type=0;
}

Hit::Hit(int file){//ファイル名から判定クラスをインスタンス化
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

int Hit::GetRect(int *a1,int *a2,int *b1,int *b2){//判定矩形の取得
	*a1=x1;
	*a2=x2;
	*b1=y1;
	*b2=y2;
	return 0;
}

int Hit::GetType(){
	return type;
}
Push::Push(){//ファイル名から判定クラスをインスタンス化
	x1=0,x2=0;//luaに導入しやすいよう配列を使わない。
	y1=0,y2=0;
}

Push::Push(int file){//ファイル名から判定クラスをインスタンス化
	printf("\n\tPush_construct");
	FileRead_read(&x1,sizeof(int),file);
	FileRead_read(&x2,sizeof(int),file);
	FileRead_read(&y1,sizeof(int),file);
	FileRead_read(&y2,sizeof(int),file);
}

Push::~Push(){
	printf("\n\tPush_destruct");
}
int Push::GetRect(int *a1,int *a2,int *b1,int *b2){//判定矩形の取得
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
int State::GetAxis(){//判定軸の取得
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
