#include <stdio.h>

int main(void)
{
  int count = 0, i, x;

  // Get number from user
  printf("Enter a number: ");
  scanf("%d", &x);
  
  for (int j = 2; j <= x; j++)
  {
    for (i = 2; i * i <= j; i++)
      if (j % i == 0)
        break;
    if (i * i > j)
      count++;
  }

  // For reference, there are 1229 primes from 1 to 10000
  printf("\nThere are %d prime numbers from 1 to %d\n", count, x);

  return 0;

}

