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
 * 攻撃判定クラス
 */
class Attack{//tolua_export
private:
	int x1,x2;//luaに導入しやすいよう配列を使わない。
	int y1,y2;
	int g_vx,g_vy,a_vx,a_vy;//ヒット時の吹き飛び方向と速度g_は地上ヒット,a_は空中ヒット
	int type;//攻撃の種類をビット演算でおこなう。打撃1<<0 特殊1<<1 投げ1<<2 ロック1<<3 屈ガード不能1<<4 立ちガード不能1<<5 ダウン1<<6 強制ダウン1<<7
	int damage;//ダメージ
	int point;//削減値。この数値で追撃可能かどうかを判定
	int time;//のけぞり時間
public:
	//tolua_begin
	Attack();
	Attack(int file);
	~Attack();
	int GetRect(int* a1,int* a2,int* b1,int* b2);//判定矩形の取得
	int GetType();//攻撃タイプの取得
	int GetDamage();//ダメージの取得
	int AirHit(int* vx,int* vy,int* p);//空中ヒット時の吹き飛び方向、削減値の取得
	int GroundHit(int* vx,int* vy,int* t,int* p);//地上ヒット時の吹き飛び方向とのけぞり時間。lua側でvy>0のときはのけぞり時間を考えない

};
//tolua_end

/*
 * 押し出し判定クラス
 */
class Push{//tolua_export
private:
	int x1,x2,y1,y2;//押し出し判定の矩形
public:
	//tolua_begin
	Push();
	Push(int file);
	~Push();
	int GetRect(int *a1,int *a2,int *b1,int *b2);//判定矩形の取得
};
//tolua_end
/*
 * 食らい判定クラス
 */
class Hit{//tolua_export
private:
	int x1,x2,y1,y2;//くらい判定の矩形
	int type;//無敵のビット列 対打撃1<<0 対特殊1<<1
public://tolua_begin
	Hit();
	Hit(int file);
	~Hit();
	int GetRect(int *a1,int *a2,int *b1,int *b2);//判定矩形の取得
	int GetType();
};
//tolua_end
/*
 * 状態クラス
 */

class State{//tolua_export
private:
	int axis;//キャラ軸
	int type;//状態のビット列 投げ無敵1<<0 空中判定1<<1 行動可能1<<2 ガード可能1<<3 ...
	int vx,vy;//キャラ自体の移動速度・方向
	int time;//発生フレーム
public:
	//tolua_begin
	State();
	State(int file);
	~State();
	int GetAxis();//キャラ軸取得
	int GetType();
	int GetSpeed(int *x,int *y);
	int GetTime();
};
//tolua_end
#endif /* COLLISION_H_ */
