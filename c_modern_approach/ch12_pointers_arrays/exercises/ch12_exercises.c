#include <stdio.h>
#define N 10
#define DAYS 7
#define HOURS 24

int main(void)
{
  // exe 13
  int ident[N][N], *p;
  for (p = &ident[0][0]; p < &ident[0][0] + (N * N); p++)
    *p = 1;
  for (p = &ident[0][0]; p < &ident[0][0] + (N * N); p++)
    printf("Address: %p  Value: %d\n", p, *p);

  // exe 14 and 15
  int temperatures[DAYS][HOURS];
  for (p = &temperatures[0][0]; p < &temperatures[DAYS-1][HOURS-1]; p++)
    *p = 1;
  p = temperatures[3];
  *p = 32;

  for (p = &temperatures[0][0]; p < &temperatures[DAYS-1][HOURS-1]; p++)
    if (*p == 32)
      printf("Found a 32 at %p\n", &p);

  for (p = temperatures[3]; p < temperatures[3] + HOURS; p++)
    printf("%d ", *p);
  printf("\n");

  return 0;
}

