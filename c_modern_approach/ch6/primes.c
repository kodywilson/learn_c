#include <stdio.h>

int main(void)
{
  int i, x = 23;

  for (i = 2; i < x && x % i != 0; i++);
  if (i < x)
  {
    printf("%d is not prime\n", x);
  }
  else
  {
    printf("%d is prime\n", x);
  }

  return 0;

}

