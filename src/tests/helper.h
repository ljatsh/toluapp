
#ifndef helper_h
#define helper_h

struct dump_buff
{
  char                buff[4096];
  size_t              offset;
  int                 level;
};

typedef struct dump_buff dump_buff;

struct lua_State;

void init_dump(dump_buff* b);

void print_dump(dump_buff* b);

int write_dump(dump_buff* b, const char* s);

int write_dump_fmt(dump_buff* b, const char* fmt, ...);

int write_dump_tab(dump_buff* b);

int write_dump_lua(dump_buff* b, lua_State* L, int pos);

int write_dump_lua_key(dump_buff* b, lua_State* L, int pos);

int write_dump_lua_table(dump_buff* b, lua_State* L);

#endif /* helper_h */
