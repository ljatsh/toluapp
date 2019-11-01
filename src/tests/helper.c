
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <lua.h>

#include "helper.h"

void
init_dump(dump_buff* b)
{
  memset(b, 0, sizeof(dump_buff));
}

void
print_dump(dump_buff* b)
{
  printf("%s\n", b->buff);
}

int
write_dump(dump_buff* b, const char* s)
{
  if (s == NULL)
    return 0;

  size_t l = strlen(s);
  size_t m = sizeof(b->buff) - b->offset - 1;
  if (l > m)
    l = m;

  strncpy(b->buff + b->offset, s, l);
  b->offset += l;

  return l;
}

int
write_dump_fmt(dump_buff* b, const char* fmt, ...)
{
  if (fmt == NULL)
    return 0;

  va_list ap;
  va_start(ap, fmt);

  size_t m = sizeof(b->buff) - b->offset - 1;
  // https://linux.die.net/man/3/vsnprintf
  size_t l = vsnprintf(b->buff + b->offset, m, fmt, ap);
  b->offset += l;
  va_end(ap);

  return l;
}

int
write_dump_tab(dump_buff* b)
{
  size_t cnt = b->level << 1;
  size_t m = sizeof(b->buff) - b->offset - 1;
  if (cnt > m)
    cnt = m;

  memset(b->buff + b->offset, ' ', cnt);

  return cnt;
}

int
write_dump_lua(dump_buff* b, lua_State* L, int pos)
{
  int t = lua_type(L, pos);
  printf("t = %d\n", t);
  switch (t)
  {
    case LUA_TNIL: return write_dump(b, "nil");
    case LUA_TNUMBER: return write_dump_fmt(b, "%f", lua_tonumber(L, pos));
    case LUA_TBOOLEAN: return write_dump(b, lua_toboolean(L, pos) == 0 ? "false" : "true");
    case LUA_TSTRING: return write_dump(b, lua_tostring(L, pos));
    case LUA_TTABLE:
      {
        if (b->level >= 1)
        {
          return write_dump(b, "nested t");
        }

        b->level++;
        lua_pushvalue(L, pos);
        int l = write_dump_lua_table(b, L);
        lua_pop(L, 1);
        b->level--;

        return l;
      }
    case LUA_TFUNCTION:
    {
       lua_CFunction f = lua_tocfunction(L, pos);
       return write_dump_fmt(b, "function %p", f);
    }
    case LUA_TLIGHTUSERDATA:
    {
       void* p = lua_touserdata(L, pos);
       return write_dump_fmt(b, "userdata %p", p);
    }
    default: write_dump(b, "."); return 0;
  }
}

int
write_dump_lua_key(dump_buff* b, lua_State* L, int pos)
{
  /*return write_dump_lua(b, L, pos);*/
  int t = lua_type(L, pos);
  switch (t)
  {
    case LUA_TNIL: return write_dump(b, "nil");
    case LUA_TNUMBER: return write_dump_fmt(b, "%f", lua_tonumber(L, pos));
    case LUA_TBOOLEAN: return write_dump(b, lua_toboolean(L, pos) == 0 ? "false" : "true");
    case LUA_TSTRING: return write_dump(b, lua_tostring(L, pos));
    default: write_dump(b, "."); return 0;
  }
}

int
write_dump_lua_table(dump_buff* b, lua_State* L)
{
  int l = 0;
  l += write_dump(b, "{");

  printf("size(begin dump lua table) %d\n", lua_gettop(L));

  lua_pushnil(L);
  while (lua_next(L, -2) != 0)
  {
    l += write_dump_lua_key(b, L, -2);
    l += write_dump(b, ": ");
    l += write_dump_lua(b, L, -1);
    l += write_dump(b, ", ");

    printf("key type %d, value type %d\n", lua_type(L, -2), lua_type(L, -1));

    lua_pop(L, 1);
    printf("size(end looping lua table) -> %d\n", lua_gettop(L));
  }

  l += write_dump(b, "}");
  return l;
}
