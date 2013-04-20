/*
** Lua binding: bind
** Generated automatically by tolua++-1.0.92 on 01/23/13 08:57:27.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_bind_open (lua_State* tolua_S);

#include"../Ctolua.h"
#include"../collision.h"
#include "../collision.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_State (lua_State* tolua_S)
{
 State* self = (State*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Push (lua_State* tolua_S)
{
 Push* self = (Push*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Key (lua_State* tolua_S)
{
 Key* self = (Key*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Hit (lua_State* tolua_S)
{
 Hit* self = (Hit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Attack (lua_State* tolua_S)
{
 Attack* self = (Attack*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"State");
 tolua_usertype(tolua_S,"Push");
 tolua_usertype(tolua_S,"Key");
 tolua_usertype(tolua_S,"Hit");
 tolua_usertype(tolua_S,"Attack");
}

/* function: LoadImagefile */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_LoadImagefile00
static int tolua_bind_Dx_LoadImagefile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* file = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   int tolua_ret = (int)  LoadImagefile(file);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadImagefile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: String */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_String00
static int tolua_bind_Dx_String00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isstring(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int r = ((int)  tolua_tonumber(tolua_S,1,0));
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  int x = ((int)  tolua_tonumber(tolua_S,4,0));
  int y = ((int)  tolua_tonumber(tolua_S,5,0));
  char* text = ((char*)  tolua_tostring(tolua_S,6,0));
  {
   String(r,g,b,x,y,text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'String'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LoadDivImage */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_LoadDivImage00
static int tolua_bind_Dx_LoadDivImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int hundle = ((int)  tolua_tonumber(tolua_S,1,0));
  int start_x = ((int)  tolua_tonumber(tolua_S,2,0));
  int start_y = ((int)  tolua_tonumber(tolua_S,3,0));
  int end_x = ((int)  tolua_tonumber(tolua_S,4,0));
  int end_y = ((int)  tolua_tonumber(tolua_S,5,0));
  {
   int tolua_ret = (int)  LoadDivImage(hundle,start_x,start_y,end_x,end_y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadDivImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: DrawImage */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_DrawImage00
static int tolua_bind_Dx_DrawImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  int hundle = ((int)  tolua_tonumber(tolua_S,3,-1));
  int direction = ((int)  tolua_tonumber(tolua_S,4,DIRECTION_LEFT));
  int Flg = ((int)  tolua_tonumber(tolua_S,5,1));
  {
   int tolua_ret = (int)  DrawImage(x,y,hundle,direction,Flg);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetSize */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_GetSize00
static int tolua_bind_Dx_GetSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int hundle = ((int)  tolua_tonumber(tolua_S,1,0));
  int x = ((int)  tolua_tonumber(tolua_S,2,0));
  int y = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  GetSize(hundle,&x,&y);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: InitImage */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_InitImage00
static int tolua_bind_Dx_InitImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  InitImage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: DrawCollision */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_DrawCollision00
static int tolua_bind_Dx_DrawCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int r = ((int)  tolua_tonumber(tolua_S,1,0));
  int g = ((int)  tolua_tonumber(tolua_S,2,0));
  int b = ((int)  tolua_tonumber(tolua_S,3,0));
  int x1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int x2 = ((int)  tolua_tonumber(tolua_S,5,0));
  int y1 = ((int)  tolua_tonumber(tolua_S,6,0));
  int y2 = ((int)  tolua_tonumber(tolua_S,7,0));
  {
   int tolua_ret = (int)  DrawCollision(r,g,b,x1,x2,y1,y2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DrawCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: FileOpen */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_FileOpen00
static int tolua_bind_Dx_FileOpen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  char* filename = ((char*)  tolua_tostring(tolua_S,1,0));
  {
   int tolua_ret = (int)  FileOpen(filename);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FileOpen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: FileRead */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_FileRead00
static int tolua_bind_Dx_FileRead00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int file = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  FileRead(file);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FileRead'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: FileClose */
#ifndef TOLUA_DISABLE_tolua_bind_Dx_FileClose00
static int tolua_bind_Dx_FileClose00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int file = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  FileClose(file);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FileClose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: XOR */
#ifndef TOLUA_DISABLE_tolua_bind_XOR00
static int tolua_bind_XOR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  XOR(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'XOR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: OR */
#ifndef TOLUA_DISABLE_tolua_bind_OR00
static int tolua_bind_OR00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  OR(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OR'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: AND */
#ifndef TOLUA_DISABLE_tolua_bind_AND00
static int tolua_bind_AND00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int y = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  AND(x,y);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AND'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: NOT */
#ifndef TOLUA_DISABLE_tolua_bind_NOT00
static int tolua_bind_NOT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   int tolua_ret = (int)  NOT(x);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'NOT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: LSHIFT */
#ifndef TOLUA_DISABLE_tolua_bind_LSHIFT00
static int tolua_bind_LSHIFT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int number = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  LSHIFT(x,number);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LSHIFT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: RSHIFT */
#ifndef TOLUA_DISABLE_tolua_bind_RSHIFT00
static int tolua_bind_RSHIFT00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int x = ((int)  tolua_tonumber(tolua_S,1,0));
  int number = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   int tolua_ret = (int)  RSHIFT(x,number);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RSHIFT'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_new00
static int tolua_bind_Key_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Key* tolua_ret = (Key*)  Mtolua_new((Key)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Key");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_new00_local
static int tolua_bind_Key_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Key* tolua_ret = (Key*)  Mtolua_new((Key)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Key");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_delete00
static int tolua_bind_Key_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Key* self = (Key*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: KeyState of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_KeyState00
static int tolua_bind_Key_KeyState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Key* self = (Key*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KeyState'", NULL);
#endif
  {
   int tolua_ret = (int)  self->KeyState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KeyState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPush of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_GetPush00
static int tolua_bind_Key_GetPush00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Key* self = (Key*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPush'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPush();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPush'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDown of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_GetDown00
static int tolua_bind_Key_GetDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Key* self = (Key*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDown'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetDown();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUp of class  Key */
#ifndef TOLUA_DISABLE_tolua_bind_Key_GetUp00
static int tolua_bind_Key_GetUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Key",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Key* self = (Key*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUp'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetUp();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_new00
static int tolua_bind_collision_Attack_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_new00_local
static int tolua_bind_collision_Attack_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_new01
static int tolua_bind_collision_Attack_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Attack_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_new01_local
static int tolua_bind_collision_Attack_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Attack* tolua_ret = (Attack*)  Mtolua_new((Attack)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Attack");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Attack_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_delete00
static int tolua_bind_collision_Attack_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRect of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_GetRect00
static int tolua_bind_collision_Attack_GetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
  int a1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int a2 = ((int)  tolua_tonumber(tolua_S,3,0));
  int b1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int b2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRect'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRect(&a1,&a2,&b1,&b2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)a1);
   tolua_pushnumber(tolua_S,(lua_Number)a2);
   tolua_pushnumber(tolua_S,(lua_Number)b1);
   tolua_pushnumber(tolua_S,(lua_Number)b2);
  }
 }
 return 5;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_GetType00
static int tolua_bind_collision_Attack_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDamage of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_GetDamage00
static int tolua_bind_collision_Attack_GetDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDamage'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetDamage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AirHit of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_AirHit00
static int tolua_bind_collision_Attack_AirHit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
  int vx = ((int)  tolua_tonumber(tolua_S,2,0));
  int vy = ((int)  tolua_tonumber(tolua_S,3,0));
  int p = ((int)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AirHit'", NULL);
#endif
  {
   int tolua_ret = (int)  self->AirHit(&vx,&vy,&p);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)vx);
   tolua_pushnumber(tolua_S,(lua_Number)vy);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 4;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AirHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GroundHit of class  Attack */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Attack_GroundHit00
static int tolua_bind_collision_Attack_GroundHit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Attack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Attack* self = (Attack*)  tolua_tousertype(tolua_S,1,0);
  int vx = ((int)  tolua_tonumber(tolua_S,2,0));
  int vy = ((int)  tolua_tonumber(tolua_S,3,0));
  int t = ((int)  tolua_tonumber(tolua_S,4,0));
  int p = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GroundHit'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GroundHit(&vx,&vy,&t,&p);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)vx);
   tolua_pushnumber(tolua_S,(lua_Number)vy);
   tolua_pushnumber(tolua_S,(lua_Number)t);
   tolua_pushnumber(tolua_S,(lua_Number)p);
  }
 }
 return 5;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GroundHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_new00
static int tolua_bind_collision_Push_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Push* tolua_ret = (Push*)  Mtolua_new((Push)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Push");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_new00_local
static int tolua_bind_collision_Push_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Push* tolua_ret = (Push*)  Mtolua_new((Push)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Push");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_new01
static int tolua_bind_collision_Push_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Push* tolua_ret = (Push*)  Mtolua_new((Push)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Push");
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Push_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_new01_local
static int tolua_bind_collision_Push_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Push* tolua_ret = (Push*)  Mtolua_new((Push)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Push");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Push_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_delete00
static int tolua_bind_collision_Push_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Push* self = (Push*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRect of class  Push */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Push_GetRect00
static int tolua_bind_collision_Push_GetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Push",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Push* self = (Push*)  tolua_tousertype(tolua_S,1,0);
  int a1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int a2 = ((int)  tolua_tonumber(tolua_S,3,0));
  int b1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int b2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRect'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRect(&a1,&a2,&b1,&b2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)a1);
   tolua_pushnumber(tolua_S,(lua_Number)a2);
   tolua_pushnumber(tolua_S,(lua_Number)b1);
   tolua_pushnumber(tolua_S,(lua_Number)b2);
  }
 }
 return 5;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_new00
static int tolua_bind_collision_Hit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hit* tolua_ret = (Hit*)  Mtolua_new((Hit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hit");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_new00_local
static int tolua_bind_collision_Hit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Hit* tolua_ret = (Hit*)  Mtolua_new((Hit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hit");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_new01
static int tolua_bind_collision_Hit_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Hit* tolua_ret = (Hit*)  Mtolua_new((Hit)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hit");
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Hit_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_new01_local
static int tolua_bind_collision_Hit_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Hit* tolua_ret = (Hit*)  Mtolua_new((Hit)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Hit");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_Hit_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_delete00
static int tolua_bind_collision_Hit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hit* self = (Hit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRect of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_GetRect00
static int tolua_bind_collision_Hit_GetRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hit* self = (Hit*)  tolua_tousertype(tolua_S,1,0);
  int a1 = ((int)  tolua_tonumber(tolua_S,2,0));
  int a2 = ((int)  tolua_tonumber(tolua_S,3,0));
  int b1 = ((int)  tolua_tonumber(tolua_S,4,0));
  int b2 = ((int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRect'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetRect(&a1,&a2,&b1,&b2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
   tolua_pushnumber(tolua_S,(lua_Number)a1);
   tolua_pushnumber(tolua_S,(lua_Number)a2);
   tolua_pushnumber(tolua_S,(lua_Number)b1);
   tolua_pushnumber(tolua_S,(lua_Number)b2);
  }
 }
 return 5;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  Hit */
#ifndef TOLUA_DISABLE_tolua_bind_collision_Hit_GetType00
static int tolua_bind_collision_Hit_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Hit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Hit* self = (Hit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_new00
static int tolua_bind_collision_State_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   State* tolua_ret = (State*)  Mtolua_new((State)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"State");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_new00_local
static int tolua_bind_collision_State_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   State* tolua_ret = (State*)  Mtolua_new((State)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"State");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_new01
static int tolua_bind_collision_State_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   State* tolua_ret = (State*)  Mtolua_new((State)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"State");
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_State_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_new01_local
static int tolua_bind_collision_State_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int file = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   State* tolua_ret = (State*)  Mtolua_new((State)(file));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"State");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_bind_collision_State_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_delete00
static int tolua_bind_collision_State_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  State* self = (State*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAxis of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_GetAxis00
static int tolua_bind_collision_State_GetAxis00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  State* self = (State*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAxis'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetAxis();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAxis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetType of class  State */
#ifndef TOLUA_DISABLE_tolua_bind_collision_State_GetType00
static int tolua_bind_collision_State_GetType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"State",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  State* self = (State*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetType'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_bind_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"DIRECTION_LEFT",DIRECTION_LEFT);
  tolua_constant(tolua_S,"DIRECTION_RIGHT",DIRECTION_RIGHT);
  tolua_module(tolua_S,"Dx",0);
  tolua_beginmodule(tolua_S,"Dx");
   tolua_function(tolua_S,"LoadImagefile",tolua_bind_Dx_LoadImagefile00);
   tolua_function(tolua_S,"String",tolua_bind_Dx_String00);
   tolua_function(tolua_S,"LoadDivImage",tolua_bind_Dx_LoadDivImage00);
   tolua_function(tolua_S,"DrawImage",tolua_bind_Dx_DrawImage00);
   tolua_function(tolua_S,"GetSize",tolua_bind_Dx_GetSize00);
   tolua_function(tolua_S,"InitImage",tolua_bind_Dx_InitImage00);
   tolua_function(tolua_S,"DrawCollision",tolua_bind_Dx_DrawCollision00);
   tolua_function(tolua_S,"FileOpen",tolua_bind_Dx_FileOpen00);
   tolua_function(tolua_S,"FileRead",tolua_bind_Dx_FileRead00);
   tolua_function(tolua_S,"FileClose",tolua_bind_Dx_FileClose00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"XOR",tolua_bind_XOR00);
  tolua_function(tolua_S,"OR",tolua_bind_OR00);
  tolua_function(tolua_S,"AND",tolua_bind_AND00);
  tolua_function(tolua_S,"NOT",tolua_bind_NOT00);
  tolua_function(tolua_S,"LSHIFT",tolua_bind_LSHIFT00);
  tolua_function(tolua_S,"RSHIFT",tolua_bind_RSHIFT00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Key","Key","",tolua_collect_Key);
  #else
  tolua_cclass(tolua_S,"Key","Key","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Key");
   tolua_function(tolua_S,"new",tolua_bind_Key_new00);
   tolua_function(tolua_S,"new_local",tolua_bind_Key_new00_local);
   tolua_function(tolua_S,".call",tolua_bind_Key_new00_local);
   tolua_function(tolua_S,"delete",tolua_bind_Key_delete00);
   tolua_function(tolua_S,"KeyState",tolua_bind_Key_KeyState00);
   tolua_function(tolua_S,"GetPush",tolua_bind_Key_GetPush00);
   tolua_function(tolua_S,"GetDown",tolua_bind_Key_GetDown00);
   tolua_function(tolua_S,"GetUp",tolua_bind_Key_GetUp00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"collision",0);
  tolua_beginmodule(tolua_S,"collision");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Attack","Attack","",tolua_collect_Attack);
   #else
   tolua_cclass(tolua_S,"Attack","Attack","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Attack");
    tolua_function(tolua_S,"new",tolua_bind_collision_Attack_new00);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Attack_new00_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Attack_new00_local);
    tolua_function(tolua_S,"new",tolua_bind_collision_Attack_new01);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Attack_new01_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Attack_new01_local);
    tolua_function(tolua_S,"delete",tolua_bind_collision_Attack_delete00);
    tolua_function(tolua_S,"GetRect",tolua_bind_collision_Attack_GetRect00);
    tolua_function(tolua_S,"GetType",tolua_bind_collision_Attack_GetType00);
    tolua_function(tolua_S,"GetDamage",tolua_bind_collision_Attack_GetDamage00);
    tolua_function(tolua_S,"AirHit",tolua_bind_collision_Attack_AirHit00);
    tolua_function(tolua_S,"GroundHit",tolua_bind_collision_Attack_GroundHit00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Push","Push","",tolua_collect_Push);
   #else
   tolua_cclass(tolua_S,"Push","Push","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Push");
    tolua_function(tolua_S,"new",tolua_bind_collision_Push_new00);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Push_new00_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Push_new00_local);
    tolua_function(tolua_S,"new",tolua_bind_collision_Push_new01);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Push_new01_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Push_new01_local);
    tolua_function(tolua_S,"delete",tolua_bind_collision_Push_delete00);
    tolua_function(tolua_S,"GetRect",tolua_bind_collision_Push_GetRect00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Hit","Hit","",tolua_collect_Hit);
   #else
   tolua_cclass(tolua_S,"Hit","Hit","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Hit");
    tolua_function(tolua_S,"new",tolua_bind_collision_Hit_new00);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Hit_new00_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Hit_new00_local);
    tolua_function(tolua_S,"new",tolua_bind_collision_Hit_new01);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_Hit_new01_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_Hit_new01_local);
    tolua_function(tolua_S,"delete",tolua_bind_collision_Hit_delete00);
    tolua_function(tolua_S,"GetRect",tolua_bind_collision_Hit_GetRect00);
    tolua_function(tolua_S,"GetType",tolua_bind_collision_Hit_GetType00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"State","State","",tolua_collect_State);
   #else
   tolua_cclass(tolua_S,"State","State","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"State");
    tolua_function(tolua_S,"new",tolua_bind_collision_State_new00);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_State_new00_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_State_new00_local);
    tolua_function(tolua_S,"new",tolua_bind_collision_State_new01);
    tolua_function(tolua_S,"new_local",tolua_bind_collision_State_new01_local);
    tolua_function(tolua_S,".call",tolua_bind_collision_State_new01_local);
    tolua_function(tolua_S,"delete",tolua_bind_collision_State_delete00);
    tolua_function(tolua_S,"GetAxis",tolua_bind_collision_State_GetAxis00);
    tolua_function(tolua_S,"GetType",tolua_bind_collision_State_GetType00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_bind (lua_State* tolua_S) {
 return tolua_bind_open(tolua_S);
};
#endif

