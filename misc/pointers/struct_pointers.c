#include <stdio.h>
#include <string.h>

int main(void)
{
  struct tag
  {
    char lname[20];   // last name
    char fname[20];   // first name
    int age;          // age
    float rate;       // hourly pay rate
  };

  struct tag employee;

  strcpy(employee.lname, "Roberts");
  strcpy(employee.fname, "Jack");
  printf("\n%s ", employee.fname);
  printf("%s\n", employee.lname);

  return 0;
}

