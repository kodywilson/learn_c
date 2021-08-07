#include <stdio.h>

int main()
{
  int n, total = 1;
  printf("Enter a positive number: ");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    total *= i;
  printf("Factorial of %d: %d\n", n, total);

  return 0;
}

