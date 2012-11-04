#include"Skill.h"
#include"DxLib.h"

void Skill(enum Menu ID,int Key[]){
	if(Key[KEY_INPUT_Q]>=1||Key[KEY_INPUT_W]>=1||Key[KEY_INPUT_A]>=1||Key[KEY_INPUT_S]>=1){
		switch(ID){
			case HADO:
				DrawFormatString(50,50+20,GetColor(0,0,0),"Åõ") ;
				break;	
			case TATSU:
				DrawFormatString(50,70+20,GetColor(0,0,0),"Åõ");
				break;
			case YOGA:
				DrawFormatString(50,90+20,GetColor(0,0,0),"Åõ");
				break;
			case R_YOGA:
				DrawFormatString(50,110+20,GetColor(0,0,0),"Åõ");
				break;
			case SYORYU:
				DrawFormatString(50,130+20,GetColor(0,0,0),"Åõ");
				break;
			case R_SYORYU:
				DrawFormatString(50,150+20,GetColor(0,0,0),"Åõ");
				break;
			case SINKU:
				DrawFormatString(50,170+20,GetColor(0,0,0),"Åõ");
				break;
			case R_SINKU:
				DrawFormatString(50,190+20,GetColor(0,0,0),"Åõ");
				break;
			case JIGOKU:
				DrawFormatString(50,210+20,GetColor(0,0,0),"Åõ");
				break;
			case R_JIGOKU:
				DrawFormatString(50,230+20,GetColor(0,0,0),"Åõ");
				break;
			case -1:
			dafault:
				break;
		}
	}
}
