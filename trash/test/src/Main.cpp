/*
 * Main.cpp
 *
 *  Created on: 2012/12/09
 *      Author: matsugen
 */


#define DX_GCC_COMPILE
#define DX_NON_INLINE_ASM
#include "Main.h"
#include<Dxlib.h>

Main::Main() {
	// TODO 自動生成されたコンストラクター・スタブ
	Refresh_time=GetNowCount();
}

Main::~Main() {
	// TODO Auto-generated destructor stub
}

void Main::wait(){
	while(GetNowCount()-Refresh_time<17){}
}

void Main::update(){
	Refresh_time=GetNowCount();
}
