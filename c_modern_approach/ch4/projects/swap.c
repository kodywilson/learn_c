// Reverse numbers entered by user

#include <stdio.h>

int main(void)
{
  int number;
  printf("Enter a three-digit number: ");
  scanf("%3d", &number);
  printf("The reversal is: %d%d%d\n", (number % 100) % 10, (number % 100) / 10, number / 100);

  return 0;
}

