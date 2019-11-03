
#include <stdio.h>
#include <lualib.h>
#include <lauxlib.h>
#include <string.h>

#include "texample.h"
#include "helper.h"

void
test()
{
  printf("test in c\n");
}

float
sum(float a, float b)
{
  return a + b;
}

student::student(const char* name /* = NULL */, int age /* = 0 */)
{
  memset(this->name, 0, sizeof(this->name));

  set_name(name);
  set_age(age);
  boy = false;

  printf("sutdent %p was allocated\n", this);
}

student::~student()
{
  printf("student %p was released\n", this);
}

void student::set_name(const char* name)
{
  strncpy(this->name, name, sizeof(this->name) - 1);
}

const char* student::get_name() const
{
  return name;
}

void student::set_age(int age)
{
  this->age = age;
}

int student::get_age() const
{
  return age;
}

int student::get_id() const
{
  return 1;
}

float student::sub(float a, float b)
{
  return a - b;
}

student* student::create(int a)
{
  if (a == 1)
    return new student("lj@sh", 31);

  return new stuff("lj@bj", 30);
}

stuff::stuff(const char* name, int age) : student(name, age)
{
  printf("stuff %p was allocated\n", this);
}

stuff::~stuff()
{
  printf("stuff %p was released\n", this);
}

int stuff::get_id() const
{
  return 2;
}

const char* stuff::unique() const
{
  return "unique";
}

extern "C" int tolua_texample_open(lua_State* L);
float d = 0.0f;

int main(int argc, char* argv[])
{
  lua_State* L = lua_open();
  luaopen_base(L);
  tolua_texample_open(L);

  lua_pushcfunction(L, dump_lua);
  lua_setglobal(L, "dump_lua");

  int i;
  int n = luaL_dofile(L,"src/tests/texample.lua");
  if (n == 1)
  {
    for (i=1; i<=lua_gettop(L); i++)
    {
      switch(lua_type(L, i))
      {
        case LUA_TNIL: printf("nil "); break;
        case LUA_TNUMBER: printf("%f ", lua_tonumber(L, i)); break;
        case LUA_TBOOLEAN: printf("%s ", lua_toboolean(L, i) == 0 ? "true" : "false"); break;
        case LUA_TSTRING: printf("%s ", lua_tostring(L, i)); break;
      }
    }
    printf("\n");
  }
  lua_settop(L, 0);

  printf("============== LUA_REGISTRYINDEX ===================\n");
  lua_pushvalue(L, LUA_REGISTRYINDEX);
  dump_lua(L);
  lua_pop(L, 1);

  lua_close(L);
  return 0;
}
