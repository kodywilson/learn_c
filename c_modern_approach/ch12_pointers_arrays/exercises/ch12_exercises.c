#include <stdio.h>
#define N 10

int main(void)
{
  int ident[N][N], *p;
  for (p = &ident[0][0]; p < &ident[0][0] + (N * N); p++)
    *p = 1;
  for (p = &ident[0][0]; p < &ident[0][0] + (N * N); p++)
    printf("Address: %p  Value: %d\n", p, *p);

  return 0;
}

