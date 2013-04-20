//============================================================================
// Name        : test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include<DxLib.h>
#include<lua.hpp>
#include<tolua++.h>
#include"luabinder/bind.h"
#include"Main.h"
int main(int argc, char **argv) {
	printf("start");
	lua_State *L=luaL_newstate();
	luaL_openlibs(L);
	tolua_bind_open(L);
	int top=lua_gettop(L);
	int ret;
	Main *mainloop=new Main;
	SetDrawScreen( DX_SCREEN_BACK ) ;
	ChangeWindowMode(true);
	SetBackgroundColor(255,255,255);
	char Key[256];
	SetGraphMode(800,600,32) ;
	if(DxLib_Init()==-1){
		return -1;
	}
	ret=luaL_dofile(L,"test.lua");
	while(ProcessMessage() == 0 && GetHitKeyStateAll(Key) == 0){
		mainloop->update();
		ClearDrawScreen();
		luaL_dofile(L,"launch.lua");
		if(Key[KEY_INPUT_RETURN]==1){
			ret=luaL_dofile(L,"test.lua");
		}
		if(ret!=0){
			DrawFormatString(0,100,GetColor(0,0,0),"error:%s",lua_tostring(L,-1));
			lua_pop(L,1);
		}
		ScreenFlip() ;                             //裏画面データを表画面へ反映
		if(Key[KEY_INPUT_ESCAPE]==1){
			break;     //Escapeが押されたら終了
		}
		mainloop->wait();
	}
	lua_settop(L,top);
	DxLib_End();
	delete(mainloop);
	lua_close(L);
	printf("\nend");
	return 0;
}
