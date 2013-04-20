#include"set.h"
#include"DxLib.h"
#include"macro.h"
//#define NDEBUG
#include<assert.h>

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	Mainloop *Main;
	Main=Main->create();
	ChangeWindowMode(true);
	if( DxLib_Init() == -1 )
	{
		// ƒGƒ‰[”­¶Žž‚Ìˆ—
		return -1 ;
	}
	SetBackgroundColor(255,255,255); 
	SetDrawScreen( DX_SCREEN_BACK );
	while(ProcessMessage()==0){
		ClearDrawScreen();
		Main->Seq();
		Main->update();
		assert(Main->Debug());
		Main->draw();
		ScreenFlip();
		Main->wait();
	}
	Main->destroy();
	DxLib_End();
	return 0;
}
