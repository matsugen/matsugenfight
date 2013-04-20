/*
 * SDL_tolua.cpp
 *
 *  Created on: 2013/02/15
 *      Author: matsukuwa
 */


#include"SDL_tolua.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<algorithm>
/*
 * スプライトクラス
 */
Sprite::Sprite(){
	printf("Sprite Construction\n");
	m_Surface=NULL;
	m_font=NULL;
	type=NONE;
	name="";
	m_color={0,0,0};
	pos_x=pos_y=0;
}

Sprite::Sprite(const char *filename){
	printf("Sprite Construction\n");
	m_Surface=IMG_Load(filename);
	m_font=NULL;
	name=filename;
	type=IMAGE;
	m_color={0,0,0};
	pos_x=pos_y=0;
}
Sprite::Sprite(const char* filename,const char* text){
	printf("Sprite Construction\n");
	m_font=TTF_OpenFont(filename,12);
	name=text;
	type=TEXT;
	pos_x=pos_y=0;
	m_color={0,0,0};
	m_Surface=TTF_RenderUTF8_Blended(m_font,text,m_color);
}
Sprite::Sprite(int x,int y,int w,int h){
	printf("Sprite Construction\n");
	SDL_Rect rect;
	rect.x=x;
	rect.y=y;
	rect.w=w;
	rect.h=h;
	pos_x=x;
	pos_y=y;
	m_font=NULL;
	m_Surface=SDL_CreateRGBSurface(SDL_SRCALPHA,w,h,32,0,0,0,0);
	type=RECT;
	SDL_FillRect(m_Surface,&rect,SDL_MapRGB(m_Surface->format,0,0,0));
	SDL_SetAlpha(m_Surface,SDL_SRCALPHA,128);
}
Sprite::~Sprite(){
	SDL_FreeSurface(m_Surface);
	TTF_CloseFont(m_font);
	printf("Sprite Destruction\n");
}


int Sprite::Change_Text(const char* s){
	if(type!=TEXT){//文字サーフェスのみに提供される。
		return -1;
	}
	SDL_FreeSurface(m_Surface);
	name=s;
	m_Surface=TTF_RenderUTF8_Blended(m_font,s,m_color);
	return 0;
}

int Sprite::Change_Font(const char* filename,int size){
	if(type!=TEXT){//文字サーフェスのみに提供される。
		return -1;
	}
	SDL_FreeSurface(m_Surface);
	TTF_CloseFont(m_font);
	m_font=TTF_OpenFont(filename,size);
	m_Surface=TTF_RenderUTF8_Blended(m_font,name,m_color);
	return 0;
}
int Sprite::Change_Color(int r,int g,int b){
	switch(type){
	case TEXT:
		SDL_FreeSurface(m_Surface);
		m_color={r,g,b};
		m_Surface=TTF_RenderUTF8_Blended(m_font,name,m_color);
		break;
	case RECT:
		int w,h;
		w=m_Surface->w;
		h=m_Surface->h;
		SDL_FreeSurface(m_Surface);
		m_Surface=SDL_CreateRGBSurface(SDL_SRCALPHA,w,h,32,0,0,0,0);
		SDL_FillRect(m_Surface,NULL,SDL_MapRGB(m_Surface->format,r,g,b));
		SDL_SetAlpha(m_Surface,SDL_SRCALPHA,128);
		break;
	default:
		printf("Not Text or Rect");
		return -1;
		break;
	}
	return 0;
}
int Sprite::SetBlit(){
	SDL_Rect pos,Rect;
	pos.x=pos_x;
	pos.y=pos_y;
	Rect.x=Rect.y=0;
	Rect.h=m_Surface->h;
	Rect.w=m_Surface->w;
	//すべてのサーフェスに提供され、スクリーンにこのサーフェスを表示する。
	SDL_BlitSurface(m_Surface,NULL,SDL_GetVideoSurface(),&pos);
	return 0;
}

int Sprite::Change_Pos(int x,int y){
	pos_x=x;
	pos_y=y;
	return 0;
}

int Sprite::Change_Alpha(float alpha){
	if(0<=alpha&&alpha<=255){
		SDL_SetAlpha(m_Surface,SDL_SRCALPHA,alpha);
	}else{
		printf("Alpha Set missing");
		return -1;
	}
	return 0;
}



int Sprite::Reverse_X(){
	  int w = m_Surface->w;
	  int h = m_Surface->h;
	  int bps = m_Surface->format->BytesPerPixel;
	  unsigned char* bits = (unsigned char*)m_Surface->pixels;

	  for( int x = 0 ; x < w/2 ; ++x )
	  {
	    int xu = x;
	    int xb = w - x - 1;

	    for( int y = 0 ; y < h ; ++y )
	    {
	      for( int i = 0 ; i < bps ; ++i )
	      {
	        int iu = ( xu + y * w ) * bps + i;
	        int ib = ( xb + y * w ) * bps + i;
	        std::swap( bits[iu] , bits[ib] );
	      }
	    }
	  }
	return 0;
}

int Sprite::Reverse_Y(){
	  int w = m_Surface->w;
	  int h = m_Surface->h;
	  int bps = m_Surface->format->BytesPerPixel;
	  unsigned char* bits = (unsigned char*)m_Surface->pixels;

	  for( int y = 0 ; y < h/2 ; ++y )
	  {
	    int yu = y;
	    int yb = h - y - 1;

	    for( int x = 0 ; x < w ; ++x )
	    {
	      for( int i = 0 ; i < bps ; ++i )
	      {
	        int iu = ( x + yu * w ) * bps + i;
	        int ib = ( x + yb * w ) * bps + i;
	        std::swap( bits[iu] , bits[ib] );
	      }
	    }
	  }
	return 0;
}

int Sprite::Get_H(){
	return m_Surface->h;
}
int Sprite::Get_W(){
	return m_Surface->w;
}


int AND(int a,int b){return a&b;}
int OR(int a,int b){return a|b;}
int NOT(int a){return !a;}
int XOR(int a,int b){return a^b;}
int LBIT(int a,int n){return a<<n;}
int RBIT(int a,int n){return a>>n;}
void Delay(unsigned int ns){
	SDL_Delay(ns);
}
