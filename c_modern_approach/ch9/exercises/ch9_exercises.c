#include <stdio.h>

int check(int x, int y, int n); // ex2

int main(void)
{
  int x = 3, y = 5, n = 4;

  if (check(x, y, n) == 1 )
    printf("Both %d and %d are between 0 and %d\n", x, y, n);
  else
    printf("Both %d and %d are not between 0 and %d\n", x, y, n);

  return 0;
}

int check(int x, int y, int n)
{
  if ( x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1)
    return 1;
  else
    return 0;
}

