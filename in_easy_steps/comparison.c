#include <stdio.h>

int main(void)
{
  // Variables
  int zero = 0, nil = 0, one = 1;
  char upr = 'A', lwr = 'a';
  // test comparisons
  printf("Equality (0==0): %d\n", zero == nil);
  printf("Equality (0==1): %d\n", zero == one);
  printf("Equality (A==a): %d\n", upr == lwr);
  printf("Inequality (A!=a): %d\n", upr != lwr);
  printf("Greater than (1>0): %d\n", one > nil);
  printf("Less than (1<0): %d\n", one < nil);
  printf("Greater or equal (0>=): %d\n", zero >= nil);
  printf("Less or equal (1<=0): %d\n", one <= nil);
  return 0;
}

