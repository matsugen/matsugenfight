#include"KeyDisplay.h"
#include<string.h>
#include<stdio.h>
#include<iostream.h>
#include"DxLib.h"

void KeyDisplay(int Key[]){
	int y=0,i=0,j;
	static int k=0;
	char Dis[60][6],temp[6];                         
	for(j=0;j<60;j++){
		Dis[j][0]='\0';
	}
	/*
	* •ûŒü“ü—Í‚Ì”»•Ê
	*/
	
	for(j=0;j<6;j++){;
		temp[j]=Dis[k][j];
	}
	if(Key[KEY_INPUT_LEFT]==1&&Key[KEY_INPUT_DOWN]==1&&temp[i]!='1'){
		Dis[k][i]='1';
	}else if(Key[KEY_INPUT_DOWN]==1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
		Dis[k][i]='2';
	}else if(Key[KEY_INPUT_DOWN]>=1&&Key[KEY_INPUT_RIGHT]>=1&&temp[i]!='3'){
		Dis[k][i]='3';
	}else if(Key[KEY_INPUT_LEFT]==1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
		Dis[k][i]='4';
	}else if(Key[KEY_INPUT_RIGHT]==1&&Key[KEY_INPUT_UP]==0&&Key[KEY_INPUT_DOWN]==0){
		Dis[k][i]='6';
	}else if(Key[KEY_INPUT_LEFT]>=1&&Key[KEY_INPUT_UP]>=1&&temp[i]!='7'){
		Dis[k][i]='7';
	}else if(Key[KEY_INPUT_UP]==1&&Key[KEY_INPUT_LEFT]==0&&Key[KEY_INPUT_RIGHT]==0){
		Dis[k][i]='8';
	}else if(Key[KEY_INPUT_UP]>=1&&Key[KEY_INPUT_RIGHT]>=1&&temp[i]!='9'){
		Dis[k][i]='9';
	}
	i++;
	/*
	* ƒ{ƒ^ƒ“‚Ì“ü—Í”»•Ê
	*/
	
	if(Key[KEY_INPUT_Q]==1){
		Dis[k][i]='A';
		i++;
	}
	if(Key[KEY_INPUT_A]==1){
		Dis[k][i]='B';
		i++;
	}
	if(Key[KEY_INPUT_W]==1){
		Dis[k][i]='C';
		i++;
	}
	if(Key[KEY_INPUT_S]==1){
		Dis[k][i]='D';
		i++;
	}
	Dis[k][i]='\0';
	if(Dis[k][0]!='\0'){
		k++;  
		k=k%60;
	}else{
		for(j=0;j<6;j++){
			Dis[k][j]=temp[j];
		}
	} 
	for(j=0;j<60;j++){
		DrawFormatString(0,y+j*12,GetColor(0,0,0),"%s",Dis[j]);
	}
}
	
