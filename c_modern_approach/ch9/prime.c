// test if number is prime

#include <stdio.h>

int prime(int n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main(void)
{
  int x = 1;

  printf("This program checks if a number is prime. Enter 0 to stop.\n");
  for (;;)
  {
    printf("Enter a number: ");
    scanf("%d", &x);
    if (x == 0)
      break;
    if (prime(x) == 0)
      printf("%d is not prime\n", x);
    else
      printf("%d is prime\n", x);
  }

  return 0;
}

