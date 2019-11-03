
#ifndef example_h
#define example_h

/* function binding */
void test();
float sum(float a, float b);

/* variable binding */
extern float d;

class student
{
  private:
    char        name[24];
    int         age;
  
  public:
    bool        boy;

  public:
    student(const char* name = NULL, int age = 0);
    virtual ~student();

    void set_name(const char* name);
    const char* get_name() const;

    virtual int get_id() const;

    void set_age(int age);
    int get_age() const;

    static float sub(float a, float b);
    static student* create(int a);
};

class stuff : public student
{
  public:
    stuff(const char* name, int age);
    virtual ~stuff();

    virtual int get_id() const;

    const char* unique() const;
};

#endif /* example_h */
