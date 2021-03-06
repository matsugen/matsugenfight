/*
 * Ctolua.h
 *
 *  Created on: 2012/12/11
 *      Author: matsugen
 */
/*
 * Cからluaに公開する関数を定義
 */
#ifndef CTOLUA_H_
#define CTOLUA_H_

/*
 * ここからDxライブラリ関係の関数を登録
 */
#define DIRECTION_LEFT 0
#define DIRECTION_RIGHT 1
extern int LoadImagefile(char *file);
extern void String(int r,int g,int b,int x,int y,char *text);
extern int LoadDivImage(int hundle,int start_x,int start_y,int end_x,int end_y);
extern int DrawImage(int x=0,int y=0,int hundle=-1,int direction=DIRECTION_LEFT,int Flg=1);
extern bool GetSize(int hundle,int *x,int *y);
extern int InitImage() ;
extern int DrawCollision(int r,int g,int b,int x1,int x2,int y1,int y2);
extern int FileOpen(char *filename);
extern int FileRead(int file);
extern int FileClose(int file);
/*
 * ここまでDxライブラリ関係の関数を登録
 */

/*
 * 論理演算関数ここから
 */
extern int XOR(int x,int y);
extern int OR(int x,int y);
extern int AND(int x,int y);
extern int NOT(int x);
extern int LSHIFT(int x,int number);
extern int RSHIFT(int x,int number);

/*
 * 論理演算関数ここまで
 */

/*
 * キー入力関係の関数ここから
 */
#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include<DxLib.h>
class Key{
private:
	int KeyUp;
	int KeyDown;
	int KeyPush;
	int last_Key;
	int Keymember[8]={
			KEY_INPUT_Q,
			KEY_INPUT_A,
			KEY_INPUT_W,
			KEY_INPUT_S,
			KEY_INPUT_LEFT,
			KEY_INPUT_UP,
			KEY_INPUT_RIGHT,
			KEY_INPUT_DOWN
	};
public:
	Key();
	~Key();
	int KeyState();
	int GetPush();
	int GetDown();
	int GetUp();
};
/*
 * キー入力関係の関数ここまで
 */
#endif /* CTOLUA_H_ */
