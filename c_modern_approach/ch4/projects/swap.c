// Reverse numbers entered by user

#include <stdio.h>

int main(void)
{
  int x1, x2, x3;
  printf("Enter a three-digit number: ");
  scanf("%1d%1d%1d", &x1, &x2, &x3);
  printf("The reversal is: %d%d%d\n", x3, x2, x1);

  return 0;
}

