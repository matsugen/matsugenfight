//============================================================================
// Name        : tomakuma.cpp
// Author      : matsugen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<stdio.h>
#include<lua.hpp>
#include<string.h>
#include<locale.h>
#include <SDL/SDL.h>
#include<GL/gl.h>
#include <GL/glu.h>
#include"loop.h"//ゲームの基礎
#include"SDL_tolua.h"
#include"SpriteNode.h"
Loop Game;
int main(int argc, char* argv[]) {
	while(!Game.IsQuit()){
		Game.Proccess_Frame();
		Game.Debug();
		Game.Draw();
		Game.Wait();
		SDL_GL_SwapBuffers();
	}
	Game.End();
	return 0;
}


#ifdef _WIN32
// Windowsの場合のエントリポイント
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	return main(__argc, __argv);
}
#endif
/*Luaにバインドする。*/
void ReloadLuaFiles(const char* arg){
	Game.ReloadLuaFiles(arg);
}

bool DoLuaFile(const char* path){
	return Game.DoLuaFile(path);
}
void WaitInputOnError(const char *mes, const char *postfix){
	Game.WaitInputOnError(mes,postfix);
}
const char * GetLuaError(){
	return Game.GetLuaError();
}
int GetState(int Keynum){
	return Game.GetState(Keynum);
}
DrawSystem *GetDrawSystem(){
	return Game.GetDrawSystem();
}
ImageLoader *GetImageLoader(){
	return Game.GetImageLoader();
}

