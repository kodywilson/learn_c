// calculates the number of digits in an integer

#include <stdio.h>

int main(void)
{
  int i = 0, n;

  printf("Enter a nonnegative integer: ");
  scanf("%d", &n);

  do
  {
    i++;
    n = n / 10;
  }
  while (n != 0);

  printf("The number has %d digit(s).\n", i);

  return 0;
}

