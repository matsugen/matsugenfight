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
	int HP,RG,PG;//体力・特殊ゲージ・パワーゲージ
	double posx,posy;//画像の左上の座標
	double vx,vy;//移動速度
	bool air,Guard,Counter;//空中判定・ガード状態・被カウンター状態フラグ
	bool walk,jmp,Control,UnGuard;//歩行状態・ジャンプ状態・コントロール可能状態・ガード不可能状態フラグ
	bool Rmode;//特殊モード状態フラグ
	int img[MAXBUF][MAXBUF][MAXBUF],Image;//イメージを保管する変数と、表示するイメージハンドルを格納する変数
	class Hit{//当たり判定構造体
		public: 
			double x[MAXBUF][MAXBUF][2],y[MAXBUF][MAXBUF][2];//当たり判定の判定のx座標・y座標
			bool vsattack[MAXBUF][MAXBUF],vsth[MAXBUF][MAXBUF],vsren[MAXBUF][MAXBUF];//各判定毎の無敵フラグ
			double position[MAXBUF];//キャラ軸の座標
			Hit(){}
	} *H;
	class Attack{//攻撃判定構造体
		public:
			double x[MAXBUF][MAXBUF][2],y[MAXBUF][MAXBUF][2];//攻撃判定のx座標,y座標
			bool attack[MAXBUF][MAXBUF],th[MAXBUF][MAXBUF],ren[MAXBUF][MAXBUF];//各判定ごとの攻撃フラグ
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