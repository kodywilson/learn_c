// Reverse numbers entered by user

#include <stdio.h>

int main(void)
{
  int x;
  printf("Enter a number: ");
  scanf("%d", &x);
  printf("The reversal is: ");
  do
  {
    printf("%d", x % 10);
    x = x / 10;
  }
  while (x > 0);
  printf("\n");

  return 0;
}

