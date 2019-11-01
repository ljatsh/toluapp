
#ifndef helper_h
#define helper_h

struct dump_buff
{
  char                buff[4096000];
  size_t              offset;
  int                 level;
};

struct queue
{
  const void* data;
  struct queue* next;
};

typedef struct dump_buff dump_buff;
typedef struct queue queue;

struct lua_State;

void init_queue(queue* q, const void* data);
int is_contain(queue* q, const void* data);
void enqueue(queue* q, const void* data);
void free_queue(queue*);

void init_dump(dump_buff* b);

void print_dump(dump_buff* b);

int write_dump(dump_buff* b, const char* s);

int write_dump_fmt(dump_buff* b, const char* fmt, ...);

int write_dump_tab(dump_buff* b, int cnt);

int write_dump_lua(dump_buff* b, lua_State* L, int pos, queue* q);

int write_dump_lua_key(dump_buff* b, lua_State* L, int pos);

int write_dump_lua_table(dump_buff* b, lua_State* L, queue* q);

int dump_lua(lua_State* L);

#endif /* helper_h */
