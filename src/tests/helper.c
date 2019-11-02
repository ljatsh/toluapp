
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <lua.h>

#include "helper.h"

void
init_queue(queue* q, const void* data)
{
  q->data = data;
  q->next = NULL;
}

int
is_contain(queue* q, const void* data)
{
  queue* h = q;
  while (h != NULL)
  {
    if (h->data == data)
      return 0;

    h = h->next;
  }

  return 1;
}

void
enqueue(queue* q, const void* data)
{
  queue* h = q;
  while (h != NULL)
  {
    if (h->data == NULL)
    {
      queue* q2 = (queue*)malloc(sizeof(queue));
      init_queue(q2, NULL);
      h->data = data;
      h->next = q2;
      return;
    }
    h = h->next;
  }
}

void
free_queue(queue* q)
{
  queue* h = q;
  queue* t;
  while (h != NULL)
  {
    t = h;
    h = h->next;

    free(t);
  }
}

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
  if (sizeof(b->buff) <= (b->offset + 1))
    m = 0;

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
  if (sizeof(b->buff) <= (b->offset + 1))
    m = 0;

  // https://linux.die.net/man/3/vsnprintf
  size_t l = vsnprintf(b->buff + b->offset, m, fmt, ap);
  b->offset += l;
  va_end(ap);

  return l;
}

int
write_dump_tab(dump_buff* b, int cnt2)
{
  size_t cnt = (b->level == 0 ? 0 : (b->level - 1)) << 1;
  cnt += cnt2;
  
  size_t m = sizeof(b->buff) - b->offset - 1;
  if (sizeof(b->buff) <= (b->offset + 1))
    m = 0;

  if (cnt > m)
    cnt = m;

  memset(b->buff + b->offset, ' ', cnt);
  b->offset += cnt;

  return cnt;
}

int
write_dump_lua(dump_buff* b, lua_State* L, int pos, queue* q)
{
  int t = lua_type(L, pos);
  switch (t)
  {
    case LUA_TNIL: return write_dump(b, "'nil'");
    case LUA_TNUMBER: return write_dump_fmt(b, "%.1f", lua_tonumber(L, pos));
    case LUA_TBOOLEAN: return write_dump(b, lua_toboolean(L, pos) == 0 ? "false" : "true");
    case LUA_TSTRING: return write_dump_fmt(b, "'%s'", lua_tostring(L, pos));
    case LUA_TTABLE:
      {
        b->level++;
        lua_pushvalue(L, pos);
        int l = write_dump_lua_table(b, L, q);
        lua_pop(L, 1);
        b->level--;

        return l;
      }
    case LUA_TFUNCTION:
    {
       const void* p = lua_topointer(L, pos);
       return write_dump_fmt(b, "function %p", p);
    }
    case LUA_TLIGHTUSERDATA:
    {
      const void* p = lua_topointer(L, pos);
      return write_dump_fmt(b, "lightuserdata %p", p);
    }
    case LUA_TUSERDATA:
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
  int t = lua_type(L, pos);
  switch (t)
  {
    case LUA_TNIL: return write_dump(b, "'nil'");
    case LUA_TNUMBER: return write_dump_fmt(b, "%.1f", lua_tonumber(L, pos));
    case LUA_TBOOLEAN: return write_dump(b, lua_toboolean(L, pos) == 0 ? "false" : "true");
    case LUA_TSTRING: return write_dump_fmt(b, "'%s'", lua_tostring(L, pos));
    case LUA_TFUNCTION:
    {
       const void* p = lua_topointer(L, pos);
       return write_dump_fmt(b, "function %p", p);
    }
    case LUA_TLIGHTUSERDATA:
    {
      const void* p = lua_topointer(L, pos);
      return write_dump_fmt(b, "lightuserdata %p", p);
    }
    case LUA_TUSERDATA:
    {
       void* p = lua_touserdata(L, pos);
       return write_dump_fmt(b, "userdata %p", p);
    }
    case LUA_TTABLE:
    {
      const void* p = lua_topointer(L, pos);
      return write_dump_fmt(b, "table %p", p);
    }
    default: write_dump_fmt(b, "type(%d)", t); return 0;
  }
}

int
write_dump_lua_table(dump_buff* b, lua_State* L, queue* q)
{
  const void* p = lua_topointer(L, -1);
  if (is_contain(q, p) == 0)
    return write_dump_fmt(b, "table %p", p);

  enqueue(q, p);

  int l = 0;
  l += write_dump(b, "\n");
  l += write_dump_tab(b, 0);
  l += write_dump_fmt(b, "{ %p\n", p);

  lua_pushnil(L);
  while (lua_next(L, -2) != 0)
  {
    l += write_dump_tab(b, 2);
    l += write_dump_lua_key(b, L, -2);
    l += write_dump(b, ": ");
    l += write_dump_lua(b, L, -1, q);
    l += write_dump(b, "\n");

    lua_pop(L, 1);
  }

  /*metatable*/
  if (lua_getmetatable(L, -1) != 0)
  {
    l += write_dump_tab(b, 2);
    l += write_dump(b, "mt: ");
    l += write_dump_lua(b, L, -1, q);
    l += write_dump(b, "\n");

    lua_pop(L, 1);
  }

  l += write_dump_tab(b, 0);
  l += write_dump(b, "}");
  return l;
}

int
dump_lua(lua_State* L)
{
  int n = lua_gettop(L);
  if (n == 0)
    return 0;

  dump_buff b;
  init_dump(&b);
  queue* p = (queue*)malloc(sizeof(queue));
  init_queue(p, NULL);

  int i = 1;
  for (; i<=n; i++)
  {
    write_dump_lua(&b, L, i, p);
    write_dump(&b, " ");
  }
  free_queue(p);

  print_dump(&b);
  return 0;
}
