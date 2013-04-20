/*
 * loop.h
 *
 *  Created on: 2013/02/13
 *      Author: matsukuwa
 */

/*
 *
 * ゲームループの基本関数を入れるクラス
 */
#ifndef LOOP_H_
#define LOOP_H_
#include"Resorce.h"
#include<SDL/SDL.h>
#include<lua.hpp>
#include"SDL_tolua.h"
#include"LuaHelper.h"
#include "SpriteNode.h"
//Loop用のリソース
#define FPS 60
#define N 60//FPSチェックのためのサンプル数
class Loop{
private:
	Uint8 *KeyState;
	int last_time,now_time;//FPS計算用
	int i;//Debug用のジェネレータ
	int Check_start;
	bool m_game_quit;
	char *m_error_mes;//エラーメッセージ保管(リロード時などエラーを無限に吐き続けないように)
	lua_State *m_L;//使用するLuaバーチャルマシン
	SDL_Event m_E;//イベント変数。LuaHelperとLuaParamを使ってイベントをLuaに送る
	Sprite *FPS_Text;//デバッグ用のFPS表示テキストスプライト。Luaのガベージコレクションのメモリ量も
	LuaHelper helper;//ヘルパーを設定。これを使ってLuaにデータを呼ぶ
	DrawSystem m_drawsystem;//描画システム。ここに各スプライトノードを追加して描画させる。
	ImageLoader m_imageloader;//イメージローダ。ここで画像などを読み込んでおく。
	/*デバッグ用関数*/
	//FPSのチェックと表示
	int FPS_Check();
	/*初期化用関数*/
	//Luaの初期化とヘルパーのセット
	int InitLua();
	//SDLの初期化とウィンドウの設定
	int InitSDL();
	//OpenGLの初期化// OpenGLをスプライト描画向けに初期化
	void InitOpenGL(int width, int height);
	void DrawFrame();

	/*ゲーム処理用関数*/
	//ゲームのイベントの取得
	int GetEvent();

	/*グローバルのLoop型の変数を使って色々やるための関数*/


public:
	Loop();
	~Loop();
	/*フレームを進行させる関数*/
	int Proccess_Frame();
	/*描画関数*/
	int Draw();
	/*終了確認*/
	bool IsQuit();
	/*待機関数*/
	int Wait();
	/*デバッグ用関数*/
	//現在はFPSの表示のみ
	int Debug();
	/*終了関数*/
	int End();
	//この関数をLuaに送る
	 void ReloadLuaFiles(const char* arg);
	 bool DoLuaFile(const char* path);
	 void WaitInputOnError(const char *mes, const char *postfix);
	 const char * GetLuaError();
	 int GetState(int Keynum);
	 DrawSystem* GetDrawSystem();
	 ImageLoader* GetImageLoader();

};


#endif /* LOOP_H_ */
