#include"command.h"
#include"DxLib.h"
#include"KeyTime.h"
#define DELAYTIME 20 //�R�}���h���̓��͗P�\




/*	7 8 9 
*
*       4 5 6
*
*       1 2 3
*/


/*
	1
	if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_DOWN]>=1)
	2
	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0)
	3
        if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_RIGHT]>=1)
	4
	if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0)
	5
	if(Key[KEY_INPUT_DOWN]==0&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_RIGHT]>=0&&Key[KEY_INPUT_LEFT]==0)
	6
        if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0)
	7
	if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]>=1)
	8      
	if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0)
	9
	if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_RIGHT]>=1)
*/
int Command(int Key[]){
	static int Skill[10]={0,0,0,0,0,0,0,0,0};
	static enum Menu ID=-1;
	static int time=0;
	int i;
	if(time>0){
		time--;
	}else if(time==0){
		ID=-1;
		for(i=0;i<10;i++){
			Skill[i]=0;
		}
	}
	
	/*
	* 	�g�����F��
	*/
	switch(Skill[HADO]){
		case 0:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[HADO]++;
				if(ID!=HADO){
					time=DELAYTIME;
				}
			}
			break;
		case 1:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_RIGHT]>=1){
				Skill[HADO]++;
				if(ID!=HADO){
					time=DELAYTIME;
				}
			}
			break;
		case 2:	if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[HADO]=0;
				if(ID!=HADO){
					time=DELAYTIME;
				}
				ID=HADO;
			}
			break;
		default :
			break;
	}
	
	/*
	* 	���������r�F��
	*/
	switch(Skill[TATSU]){
		case 0:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[TATSU]++;
				if(ID!=TATSU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_DOWN]>=1){
				Skill[TATSU]++;
				if(ID!=TATSU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[TATSU]=0;
				if(ID!=TATSU){
					time=DELAYTIME;
				}
				ID=TATSU;
			}
			break;
		default :
			break;	
	}
	/*
	* 	���K�t���F��
	*/
	
	switch(Skill[YOGA]){
		case 0:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[YOGA]++;
				if(ID!=YOGA){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[YOGA]++;
				if(ID!=YOGA){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[YOGA]=0;
				if(ID!=YOGA){
					time=DELAYTIME;
				}
				ID=YOGA;
			}
			break;
		default :
			break;	
	}
	/*
	* 	�t���K�t���F��
	*/
	switch(Skill[R_YOGA]){
		case 0:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_YOGA]++;
				if(ID!=R_YOGA){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_YOGA]++;
				if(ID!=R_YOGA){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_YOGA]=0;
				if(ID!=R_YOGA){
					time=DELAYTIME;
				}
				ID=R_YOGA;
			}
			break;
		default :
			break;	
	}
	/*
	* 	�������F��
	*/
	switch(Skill[SYORYU]){
		case 0:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[SYORYU]++;
				if(ID!=SYORYU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[SYORYU]++;
				if(ID!=SYORYU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0){
				Skill[SYORYU]++;
				if(ID!=SYORYU){
					time=DELAYTIME;
				}
				ID=SYORYU;
			}
			break;
		default :
			break;	
	}
	/*
	* 	�t�����F��
	*/
		switch(Skill[R_SYORYU]){
		case 0:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_SYORYU]++;
				if(ID!=R_SYORYU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_SYORYU]++;
				if(ID!=R_SYORYU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0){
				Skill[R_SYORYU]++;
				if(ID!=R_SYORYU){
					time=DELAYTIME;
				}
				ID=R_SYORYU;
			}
			break;
		default :
			break;	
	}
	/*
	* 	�^��g�����F��
	*/
	switch(Skill[SINKU]){
		
		case 0:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[SINKU]++;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_RIGHT]>=1){
				Skill[SINKU]++;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:	if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[SINKU]++;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
			}
		case 3:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[SINKU]++;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 4:	if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_RIGHT]>=1){
				Skill[SINKU]++;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 5:	if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[SINKU]=0;
				if(ID!=SINKU){
					time=DELAYTIME;
				}
				ID=SINKU;
			}
			break;
		default :
			break;
	}
	
	/*
	* 	�t�^��g�����F��
	*/
	switch(Skill[R_SINKU]){
		case 0:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_SINKU]++;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_DOWN]>=1){
				Skill[R_SINKU]++;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_SINKU]++;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
			}
		case 3:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_SINKU]++;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 4:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_DOWN]>=1){
				Skill[R_SINKU]++;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
			}
			break;
		case 5:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_SINKU]=0;
				if(ID!=R_SINKU){
					time=DELAYTIME;
				}
				ID=R_SINKU;
			}
			break;
		default :
			break;
	}
	/*
	* 	�n���Ɋy���Ƃ��F��
	*/
	switch(Skill[JIGOKU]){
		case 0:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[JIGOKU]++;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[JIGOKU]++;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[JIGOKU]++;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
			}
		case 3:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[JIGOKU]++;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 4:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[JIGOKU]++;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 5:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[JIGOKU]=0;
				if(ID!=JIGOKU){
					time=DELAYTIME;
				}
				ID=JIGOKU;
			}
			break;
		default :
			break;
	}
	/*
	* 	�t�n���Ɋy�F��
	*/
	switch(Skill[R_JIGOKU]){
		case 0:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_JIGOKU]++;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 1:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_JIGOKU]++;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 2:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_JIGOKU]++;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
			}
		case 3:if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_JIGOKU]++;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 4:if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
				Skill[R_JIGOKU]++;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
			}
			break;
		case 5:if(Key[KEY_INPUT_RIGHT]>=1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
				Skill[R_JIGOKU]=0;
				if(ID!=R_JIGOKU){
					time=DELAYTIME;
				}
				ID=R_JIGOKU;
			}
	}
	DrawFormatString(100,50,GetColor(0,0,0),"ID=%d ���͗P�\=%d",ID,time);
	DrawFormatString(100,70,GetColor(0,0,0),"�g����=%d",Skill[0]);
	DrawFormatString(100,90,GetColor(0,0,0),"���������r=%d",Skill[1]);
	DrawFormatString(100,110,GetColor(0,0,0),"���K�t���C��=%d",Skill[2]);
	DrawFormatString(100,130,GetColor(0,0,0),"�t���K�t���C��=%d",Skill[3]);
	DrawFormatString(100,150,GetColor(0,0,0),"������=%d",Skill[4]);
	DrawFormatString(100,170,GetColor(0,0,0),"�t������=%d",Skill[5]);
	DrawFormatString(100,190,GetColor(0,0,0),"�^��g����=%d",Skill[6]);
	DrawFormatString(100,210,GetColor(0,0,0),"�t�^��g����=%d",Skill[7]);
	DrawFormatString(100,230,GetColor(0,0,0),"�n���Ɋy���Ƃ�=%d",Skill[8]);
	DrawFormatString(100,250,GetColor(0,0,0),"�t�n���Ɋy���Ƃ�=%d",Skill[9]);
	return ID;
}
