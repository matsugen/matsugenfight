#include"DxLib.h"

int KeyTime(int *time){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	int i;
	for(i=0;i<256;i++){
		GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
		if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
			*(time+i)+=1;     // 加算
		} else {              // 押されていなければ
			*(time+i)= 0;   // 0にする
		}
	}
	return *time;
}
