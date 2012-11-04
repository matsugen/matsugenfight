#ifndef PLAYER
#define PLAYER

class Player{
public:
	int HP,PG,RG;//体力,パワーゲージ,特殊ゲージ
	double posx,posy,vx,vy;//キャラの位置と移動速度
	int jmp,GD,pose,attack,air,UGD;//キャラ状態のフラグ変数
	/*
	jmp:ジャンプ中(1)か否(0)か
	GD:ガード中(1)か否(0)か
	pose:しゃがみ(1)or立ち(0)
	attack:攻撃中(1)か否(0)か
	air:空中判定(1)か否(0)か
	UGD:ガード不可能(1)か可能(0)か
	*/
	int vsthrow,vsRG,vsknock//無敵状態フラグ変数
	/*
	vsthrow:投げ無敵
	vsRG:特殊ゲージ使用技無敵
	vsknock:打撃無敵
	*/
}                  


#endif