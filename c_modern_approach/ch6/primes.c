#include <stdio.h>

int main(void)
{
  int i, x;

  // Get number from user
  printf("Enter a number: ");
  scanf("%d", &x);
  
  for (int j = 1; j <= x; j++)
  {
    for (i = 2; i < j && j % i != 0; i++);
    if (i < j)
    {
      printf("%d is not prime\n", j);
    }
    else
    {
      printf("%d is prime\n", j);
    }
  }

  return 0;

}

