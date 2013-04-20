/*
 * loop.cpp
 *
 *  Created on: 2013/02/13
 *      Author: matsukuwa
 */
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include"loop.h"
#include <stdio.h>
#include<stdlib.h>
#include<lua.hpp>
#include<string.h>
#include<string>
#include"Bind.h"
#include"Resorce.h"
Loop::Loop(){
	InitLua();
	InitSDL();
	InitOpenGL(SDL_GetVideoSurface()->w,SDL_GetVideoSurface()->h);
	KeyState=SDL_GetKeyState(NULL);
	now_time=0;//
	last_time=SDL_GetTicks();
	i=0;
	Check_start=0;
	m_game_quit=false;
	m_error_mes="";
	FPS_Text=new Sprite("font/VL-Gothic-Regular.ttf","計測中");
	FPS_Text->Change_Color(0,0,0);
	FPS_Text->Change_Font("font/VL-Gothic-Regular.ttf",24);
	// リロードと初期ロードをまとめる
	if (!helper.DoFile("lua/explicit_globals.lua")) {
		WaitInputOnError(helper.GetErr(), "Exit OK?");
		exit(1);
	}
	ReloadLuaFiles("load");

	// 初期化用Lua関数を呼ぶ
	LuaFuncParam result;
	if (!helper.CallFunc("StartGame", &result, 1)) {
		WaitInputOnError(helper.GetErr(), "Exit OK?");
		exit(1);
	}
	else {
		// 関数の返り値
		const char *str = result.GetString(0);
	}
}
Loop::~Loop(){}
int Loop::Wait(){
	now_time=SDL_GetTicks()-last_time;
	if(now_time<1000/FPS){
		SDL_Delay((1000/FPS)-now_time);
	}
	last_time=SDL_GetTicks();
	return 0;
}
int Loop::InitLua(){	// Luaステートを生成
	m_L = lua_open();
    if ( !m_L ) {
        fprintf(stderr, "Unable to init Lua¥n");
        m_game_quit=true;
    }
	// 標準ライブラリをロードする
	luaL_openlibs(m_L);
	helper.SetLua(m_L);
	// print関数を設定
	helper.InitPrintFunc();
	// toluaでCの関数やクラスをインポート
//	tolua_game_open(m_L);
	//Bindでluabindを用いたものもインポートしておく
	Bind(m_L);
	return 0;
}
int Loop::InitSDL(){
	//SDLの初期化
	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)==-1){
    	printf("SDL_Init error\n");
		SDL_Quit();
		return 0;
	}else{
		printf("SDL_Init\n");
	}
	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    //SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	//SDL_TTFの初期化
	if(TTF_Init()==-1){
    	printf("TTF_Init error\n");
		TTF_Quit();
		return 0;
	}else{
		printf("TTF_Init\n");
	}
	//SDLビデオの生成
    if((SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BPP, SDL_HWSURFACE))==NULL){//ウィンドウを生成.ビデオメモリで
    	printf("SDL_SetVideoMode error\n");
    	SDL_Quit();
    	return 0;
	}else{
		printf("SDL_SetVideoMode\n");
	}
    //タイトルとアイコンの設定
    SDL_WM_SetCaption(TITLE,WINDOW_ICON);
	InitOpenGL(SDL_GetVideoSurface()->w, SDL_GetVideoSurface()->h);
	m_drawsystem.SetScreenSize(SDL_GetVideoSurface()->w, SDL_GetVideoSurface()->h);
	SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE); // Window Message取得（サスペンド阻止用）
	return 0;
}
// OpenGLをスプライト描画向けに初期化
void Loop::InitOpenGL(int width, int height)
{
	// テクスチャ関連設定
	glEnable(GL_TEXTURE_2D);
	glShadeModel( GL_FLAT );

	// カリングなし
	glDisable( GL_CULL_FACE );

	// 背景色設定
	glClearColor( 0, 0, 0, 0 );

	// 2D的な座標系設定
	glViewport( 0, 0, width, height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluOrtho2D( 0.0, width, height, 0.0 );

	// ピクセル計算・アルファブレンド
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE); // 加算の場合
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}


void Loop::DrawFrame(){
	// 画面クリア
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	// 座標変換を「なし」にする
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	// キャラクター（背景や文字も含む）描画
	m_drawsystem.DrawGL();
	glFlush();
}
/*
 * フレーム進行関数
 * 黒でまず全画面を塗りつぶしておく
 * switch-case文を用いてLuaに情報を送信したりスクリプトをリロードしたりする。
 */
int Loop::Proccess_Frame(){
	GetEvent();
	KeyState=SDL_GetKeyState(NULL);
	SDL_FillRect( SDL_GetVideoSurface(), NULL, SDL_MapRGB(SDL_GetVideoSurface()->format, 0,0,0));
	switch(m_E.type){
		case SDL_QUIT:
			m_game_quit=true;
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
				bool is_down = (m_E.type == SDL_KEYDOWN);
				// フルスクリーン切り替え（可能な場合のみ）
				if (m_E.key.keysym.sym == SDLK_RETURN && (SDL_GetModState() & KMOD_ALT)) {
					if (!SDL_WM_ToggleFullScreen(SDL_GetVideoSurface())) {
						printf("Toggle Fullscreen Failed\n");
					}
				}
				// ESCキー→ゲーム終了
				else if (m_E.key.keysym.sym == SDLK_ESCAPE) {
					m_game_quit = true;
				}
				// Luaにキー押下情報を渡す
				{
					// on_keyevent(key, is_down, is_ctrl, is_alt, is_shift) という関数を呼ぶ
					LuaFuncParam params;
					params.Number(m_E.key.keysym.sym)
						.Bool(is_down)
						.Bool((SDL_GetModState() & KMOD_CTRL) != 0)
						.Bool((SDL_GetModState() & KMOD_ALT) != 0)
						.Bool((SDL_GetModState() & KMOD_SHIFT) != 0);
					if (!helper.CallFunc("on_keyevent", NULL, 0, &params)) {
						WaitInputOnError(helper.GetErr(), "Continue OK?");
					}
				}
			break;
	}
	LuaFuncParam result;
	while (!helper.CallFunc("Frame", &result, 1)) {
		WaitInputOnError(helper.GetErr(), "Reload OK?");
		ReloadLuaFiles("all");
	}
	DrawFrame();
	return 0;
}
int Loop::Draw(){
	SDL_Flip(SDL_GetVideoSurface());
	return 0;
}

bool Loop::IsQuit(){
	return m_game_quit;
}

int Loop::GetEvent(){
	SDL_PollEvent(&m_E);
	return 0;
}

int Loop::Debug(){
	FPS_Check();
	i++;
	return 0;
}

int Loop::End(){
	SDL_Quit();
	TTF_Quit();
	lua_close(m_L);
	delete FPS_Text;
	FPS_Text=0;
	LuaFuncParam result;
	if (!helper.CallFunc("EndGame", &result, 1)) {
		WaitInputOnError(helper.GetErr(), "Exit OK?");
		exit(1);
	}
	else {
		// 関数の返り値
		const char *str = result.GetString(0);
	}
	return 0;
}

int Loop::FPS_Check(){
	double fps;
	char tmp_str[500];
	int tmp_time;
	if(i==0){
		Check_start=SDL_GetTicks();
	}else if(i>N){
		int script_memory_size = lua_gc(helper.GetLua(),LUA_GCCOUNT,0);
		tmp_time=SDL_GetTicks()-Check_start;
		fps=1000.f/((tmp_time)/(float)N);
		sprintf(tmp_str,"FPS:%3.1f Lua:%5dKB",fps,script_memory_size);
		FPS_Text->Change_Text(tmp_str);
		i=-1;
	}
	FPS_Text->SetBlit();
	return 0;
}

/*バインドする関数用*/
// エラー時の入力待ち関数
void Loop::WaitInputOnError(const char *mes, const char *postfix)
{
#ifdef _WIN32
	char text[1000];
	strcpy(text, mes);
	strcat(text, ".¥r¥n");
	strcat(text, postfix);
	printf(mes);
	MessageBox(NULL, text, "Error", MB_OK);
#else
	char text[1000];
	strcpy(text, mes);
	strcat(text, ".¥n ");
	strcat(text, postfix);
	strcat(text, "¥n>");
	printf(text);
	getchar();
#endif
}

// エラーがなくなるまでリロードを繰り返す
void Loop::ReloadLuaFiles(const char* arg = "") {
	LuaFuncParam param;
	printf("%s\n",arg);
	param.String(arg);
	LuaFuncParam result;
	while (true) {
		if (helper.DoFile("lua/reload.lua", &result, 2, &param)) {
			if (result.GetBool(0)) {
				// スクリプトリロード成功
				break;
			}
			WaitInputOnError(result.GetString(1), "Reload OK?");
		}
		else {
			WaitInputOnError(helper.GetErr(), "Reload OK?");
		}
	}
}

// Luaファイルを実行
bool Loop::DoLuaFile(const char* path) {
	std::string err;
	if (!helper.DoFile(path, NULL, 0, NULL)) {
		// エラー文字列を返す
		err = helper.GetErr();
		printf("DoLuaFile: %s\n", err.c_str());
		return false;
	}
	return true;
}

// Luaのエラーを取得する
const char * Loop::GetLuaError() {
	return helper.GetErr();
}

//キーステートを取得する。
int Loop::GetState(int Keynum){
	return KeyState[Keynum];
}
DrawSystem* Loop::GetDrawSystem(){
	return &m_drawsystem;
}
ImageLoader* Loop::GetImageLoader(){
	return &m_imageloader;
}
