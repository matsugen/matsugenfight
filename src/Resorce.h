/*
 * Resorce.h
 *
 *  Created on: 2013/02/21
 *      Author: matsukuwa
 */

#ifndef RESORCE_H_
#define RESORCE_H_
//サーフェス用のリソース
#define NONE -1
#define IMAGE 0
#define TEXT 1
#define RECT 2
//ウィンドウ初期化のリソース
#define WINDOW_WIDTH 640//ウィンドウの幅
#define WINDOW_HEIGHT 480//ウィンドウの高さ
#define BPP 32//ビット深度
#define TITLE "Title" //タイトル
#define WINDOW_ICON NULL
#include<SDL/SDL.h>

//tolua_begin
enum Key{
	UNKNOWN = 0,
	TAB = 9,
	RETURN = 13,
	ESCAPE = 27,
	SPACE = 32,
	ZERO = 48,
	ONE = 49,
	TWO = 50,
	THREE = 51,
	FOUR = 52,
	FIVE = 53,
	SIX = 54,
	SEVEN = 55,
	EIGHT = 56,
	NINE = 57,
	DELETE = 127,

	// keypad
	KP0 = 256,
	KP1 = 257,
	KP2 = 258,
	KP3 = 259,
	KP4 = 260,
	KP5 = 261,
	KP6 = 262,
	KP7 = 263,
	KP8 = 264,
	KP9 = 265,
	KP_PERIOD = 266,
	KP_DIVIDE = 267,
	KP_MULTIPLY = 268,
	KP_MINUS = 269,
	KP_PLUS = 270,
	KP_ENTER = 271,
	KP_EQUALS = 272,

	// arrows
	UP = 273,
	DOWN = 274,
	RIGHT = 275,
	LEFT = 276,
	INSERT = 277,
	HOME = 278,
	END = 279,
	PAGEUP = 280,
	PAGEDOWN = 281,

	// function keys
	F1 = 282,
	F2 = 283,
	F3 = 284,
	F4 = 285,
	F5 = 286,
	F6 = 287,
	F7 = 288,
	F8 = 289,
	F9 = 290,
	F10 = 291,
	F11 = 292,
	F12 = 293,
	F13 = 294,
	F14 = 295,
	F15 = 296,

	NUMLOCK = 300,
	CAPSLOCK = 301,
	RSHIFT = 303,
	LSHIFT = 304,
	RCTRL = 305,
	LCTRL = 306,
	RALT = 307,
	LALT = 308,

	MOD_NONE = 0x0000,
	MOD_LSHIFT = 0x0001,
	MOD_RSHIFT = 0x0002,
	MOD_LCTRL = 0x0040,
	MOD_RCTRL = 0x0080,
	MOD_LALT = 0x0100,
	MOD_RALT = 0x0200,
	MOD_CAPS = 0x2000,

	MOD_CTRL = 0x00C0,
	MOD_SHIFT = 0x0003,
	MOD_ALT = 0x0300,

	A=SDLK_a,
	B=SDLK_b,
	C=SDLK_c,
	D=SDLK_d,
	E=SDLK_e,
	F=SDLK_f,
	G=SDLK_g,
	H=SDLK_h,
	I=SDLK_i,
	J=SDLK_j,
	K=SDLK_k,
	L=SDLK_l,
	M=SDLK_m,
	N=SDLK_n,
	O=SDLK_o,
	P=SDLK_p,
	Q=SDLK_q,
	R=SDLK_r,
	S=SDLK_s,
	T=SDLK_t,
	U=SDLK_u,
	V=SDLK_v,
	W=SDLK_w,
	X=SDLK_x,
	Y=SDLK_y,
	Z=SDLK_z
};
//tolua_end

#endif /* RESORCE_H_ */
