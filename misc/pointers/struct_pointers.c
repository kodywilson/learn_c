#include <stdio.h>
#include <string.h>

struct tag
{
  char lname[20];   // last name
  char fname[20];   // first name
  int age;          // age
  float rate;       // hourly pay rate
};

struct tag employee;

// prototypes
void show_name(struct tag *p);

int main(void)
{
  struct tag *emp_ptr = &employee;

  strcpy(employee.lname, "Roberts");
  strcpy(employee.fname, "Jack");
  printf("\n%s ", employee.fname);
  printf("%s\n", employee.lname);
  printf("\n Now the same thing but with struct pointer\n");

  show_name(emp_ptr);

  return 0;
}

void show_name(struct tag *p)
{
  printf("\n%s ", p->fname);
  printf("%s\n", p->lname);
}

