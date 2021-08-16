#include <stdio.h>

int poly(int x);

int main(void)
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("The result is: %d\n", poly(n));

  return 0;
}

int poly(int x)
{
  return 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
}

