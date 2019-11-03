/*
** Lua binding: texample
** Generated automatically by tolua++-1.0.92 on Sun Nov  3 15:10:05 2019.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_texample_open (lua_State* tolua_S);

#include "texample.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_student (lua_State* tolua_S)
{
 student* self = (student*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_stuff (lua_State* tolua_S)
{
 stuff* self = (stuff*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
 tolua_usertype(tolua_S,"student");
 Mtolua_typeid(tolua_S,typeid(student), "student");
 tolua_usertype(tolua_S,"stuff");
 Mtolua_typeid(tolua_S,typeid(stuff), "stuff");
}

/* function: test */
#ifndef TOLUA_DISABLE_tolua_texample_test00
static int tolua_texample_test00(lua_State* tolua_S)
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
   test();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: sum */
#ifndef TOLUA_DISABLE_tolua_texample_sum00
static int tolua_texample_sum00(lua_State* tolua_S)
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
  float a = ((float)  tolua_tonumber(tolua_S,1,0));
  float b = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   float tolua_ret = (float)  sum(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: d */
#ifndef TOLUA_DISABLE_tolua_get_d
static int tolua_get_d(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)d);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: d */
#ifndef TOLUA_DISABLE_tolua_set_d
static int tolua_set_d(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  d = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: boy of class  student */
#ifndef TOLUA_DISABLE_tolua_get_student_boy
static int tolua_get_student_boy(lua_State* tolua_S)
{
  student* self = (student*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boy'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->boy);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: boy of class  student */
#ifndef TOLUA_DISABLE_tolua_set_student_boy
static int tolua_set_student_boy(lua_State* tolua_S)
{
  student* self = (student*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'boy'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->boy = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_new00
static int tolua_texample_student_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  int age = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   student* tolua_ret = (student*)  Mtolua_new((student)(name,age));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"student");
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

/* method: new_local of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_new00_local
static int tolua_texample_student_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  int age = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   student* tolua_ret = (student*)  Mtolua_new((student)(name,age));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"student");
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

/* method: delete of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_delete00
static int tolua_texample_student_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  student* self = (student*)  tolua_tousertype(tolua_S,1,0);
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

/* method: set_name of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_set_name00
static int tolua_texample_student_set_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  student* self = (student*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_name'", NULL);
#endif
  {
   self->set_name(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_name of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_get_name00
static int tolua_texample_student_get_name00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const student",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const student* self = (const student*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_name'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->get_name();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_name'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set_age of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_set_age00
static int tolua_texample_student_set_age00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  student* self = (student*)  tolua_tousertype(tolua_S,1,0);
  int age = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set_age'", NULL);
#endif
  {
   self->set_age(age);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set_age'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_age of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_get_age00
static int tolua_texample_student_get_age00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const student",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const student* self = (const student*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_age'", NULL);
#endif
  {
   int tolua_ret = (int)  self->get_age();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_age'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_id of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_get_id00
static int tolua_texample_student_get_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const student",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const student* self = (const student*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->get_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_sub00
static int tolua_texample_student_sub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
  float b = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   float tolua_ret = (float)  student::sub(a,b);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  student */
#ifndef TOLUA_DISABLE_tolua_texample_student_create00
static int tolua_texample_student_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"student",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int a = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   student* tolua_ret = (student*)  student::create(a);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"student");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  stuff */
#ifndef TOLUA_DISABLE_tolua_texample_stuff_new00
static int tolua_texample_stuff_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"stuff",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int age = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   stuff* tolua_ret = (stuff*)  Mtolua_new((stuff)(name,age));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"stuff");
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

/* method: new_local of class  stuff */
#ifndef TOLUA_DISABLE_tolua_texample_stuff_new00_local
static int tolua_texample_stuff_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"stuff",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  int age = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   stuff* tolua_ret = (stuff*)  Mtolua_new((stuff)(name,age));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"stuff");
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

/* method: delete of class  stuff */
#ifndef TOLUA_DISABLE_tolua_texample_stuff_delete00
static int tolua_texample_stuff_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"stuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  stuff* self = (stuff*)  tolua_tousertype(tolua_S,1,0);
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

/* method: get_id of class  stuff */
#ifndef TOLUA_DISABLE_tolua_texample_stuff_get_id00
static int tolua_texample_stuff_get_id00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const stuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const stuff* self = (const stuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_id'", NULL);
#endif
  {
   int tolua_ret = (int)  self->get_id();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_id'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unique of class  stuff */
#ifndef TOLUA_DISABLE_tolua_texample_stuff_unique00
static int tolua_texample_stuff_unique00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const stuff",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const stuff* self = (const stuff*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unique'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->unique();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unique'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_texample_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"test",tolua_texample_test00);
  tolua_function(tolua_S,"sum",tolua_texample_sum00);
  tolua_variable(tolua_S,"d",tolua_get_d,tolua_set_d);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"student","student","",tolua_collect_student);
  #else
  tolua_cclass(tolua_S,"student","student","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"student");
   tolua_variable(tolua_S,"boy",tolua_get_student_boy,tolua_set_student_boy);
   tolua_function(tolua_S,"new",tolua_texample_student_new00);
   tolua_function(tolua_S,"new_local",tolua_texample_student_new00_local);
   tolua_function(tolua_S,".call",tolua_texample_student_new00_local);
   tolua_function(tolua_S,"delete",tolua_texample_student_delete00);
   tolua_function(tolua_S,"set_name",tolua_texample_student_set_name00);
   tolua_function(tolua_S,"get_name",tolua_texample_student_get_name00);
   tolua_function(tolua_S,"set_age",tolua_texample_student_set_age00);
   tolua_function(tolua_S,"get_age",tolua_texample_student_get_age00);
   tolua_function(tolua_S,"get_id",tolua_texample_student_get_id00);
   tolua_function(tolua_S,"sub",tolua_texample_student_sub00);
   tolua_function(tolua_S,"create",tolua_texample_student_create00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"stuff","stuff","student",tolua_collect_stuff);
  #else
  tolua_cclass(tolua_S,"stuff","stuff","student",NULL);
  #endif
  tolua_beginmodule(tolua_S,"stuff");
   tolua_function(tolua_S,"new",tolua_texample_stuff_new00);
   tolua_function(tolua_S,"new_local",tolua_texample_stuff_new00_local);
   tolua_function(tolua_S,".call",tolua_texample_stuff_new00_local);
   tolua_function(tolua_S,"delete",tolua_texample_stuff_delete00);
   tolua_function(tolua_S,"get_id",tolua_texample_stuff_get_id00);
   tolua_function(tolua_S,"unique",tolua_texample_stuff_unique00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_texample (lua_State* tolua_S) {
 return tolua_texample_open(tolua_S);
};
#endif

