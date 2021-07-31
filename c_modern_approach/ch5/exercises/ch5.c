#include <stdio.h>

int main(void)
{
  int i = 1, j = 1;
  printf("%d\n", (i > j) - (i < j));
  i = -17;
  printf("%d\n", i >= 0 ? i : -i);

  return 0;
}

