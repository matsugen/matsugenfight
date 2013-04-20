/*
 * SDL_tolua.h
 *
 *  Created on: 2013/02/15
 *      Author: matsukuwa
 */

#ifndef SDL_TOLUA_H_
#define SDL_TOLUA_H_
#include"Resorce.h"
#include"SpriteNode.h"
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_image.h>
		/*Spriteクラスのコンストラクタについて*
		 * flg:これを用いてサーフェスの種類を決定
		 * 	IMAGE…画像サーフェスとして定義
		 * 		デフォルト
		 * 			[x,y]=[0,0]
		 *	TEXT…文字サーフェスとして定義
		 *		デフォルト
		 *			[r,g,b]=[0,0,0]
		 *			[x,y]=[0,0]
		 *			pt=12
		 *	RECT…矩形サーフェス
		 *		デフォルト
		 *			α=128(半透明)
		 *			[r,g,b]=[0,0,0]
		 *	共通の提供メソッド
		 *		SetBlit();
		 *			このサーフェスを画面に表示する。
		 *		SetPos(x,y);
		 *			サーフェスの座標を変更する。
		 */
		/*画像サーフェス(IMAGE)*
		 * filename:読み込む画像のファイル名
		 * n:サーフェス名
		 * 提供するメソッドは以下
		 */
		/*文字サーフェス(TEXT)*
		 * filename:使用するフォントファイル(*.ttf)
		 * n:サーフェス名かつ表示する文字列
		 * 提供するメソッドは以下
		 * Change_Text(char *s):サーフェスの文字列を変更。同時に名前も変更される。
		 * Change_Font(char *filename,int size):サーフェスのフォントを変更。
		 * Change_Color(int r,int g,int b):サーフェスのカラー変更。
		/*矩形サーフェス*
		 * x,y:座標
		 * w,h:サイズ
		 *
		 */

class Sprite{
private:
	int pos_x,pos_y;
	SDL_Surface *m_Surface;//使用するサーフェス。これを使うためのクラス
	TTF_Font *m_font;//フォントの保存。
	const char *name;
	int type;
	SDL_Rect pos;
	SDL_Color m_color;

public:
	Sprite();
	Sprite(const char *filename);//画像サーフェスのコンストラクタ
	Sprite(const char *filename,const char *text);//文字サーフェスのコンストラクタ
	Sprite(int x,int y,int w,int h);//矩形サーフェスのコンストラクタ
	~Sprite();
	int Change_Color(int r,int g,int b);
	int Change_Text(const char* s);
	int Change_Font(const char* filename,int size);
	int SetBlit();
	int Change_Pos(int x,int y);
	int Change_Alpha(float alpha);
	int Reverse_X();//左右反転
	int Reverse_Y();//上下反転
	int Get_W();//幅の取得
	int Get_H();//高さの取得
};

/*
 * 論理演算の関数
 */
int AND(int a,int b);
int OR(int a,int b);
int NOT(int a);
int XOR(int a,int b);
int LBIT(int a,int n);
int RBIT(int a,int n);
/*
 * Luaに送る。
 */
void ReloadLuaFiles(const char* arg);
bool DoLuaFile(const char* path);
void WaitInputOnError(const char *mes, const char *postfix);
const char * GetLuaError();
void Delay(unsigned int ns);
int GetState(int Keynum);
DrawSystem* GetDrawSystem();
ImageLoader* GetImageLoader();

#endif /* SDL_TOLUA_H_ */
