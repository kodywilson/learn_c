#include <stdio.h>

int main(void)
{
  int i, n, square;

  printf("Enter a number: ");
  scanf("%d", &n);

  for (i = 2; i * i <= n; i+=2)
  {
    square = i * i;
    if (square % 2 == 0)
      printf("%d\n", square);
  }

  return 0;

}

