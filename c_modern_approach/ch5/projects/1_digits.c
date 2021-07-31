#include <stdio.h>

int main(void)
{
  //variables
  int number, digits;

  // get number from user
  printf("Enter a number: ");
  scanf("%d", &number);

  // determine number of digits
  if (number > 9999)
    printf("I can't count that high, choose a number under 10000!\n");
  else if (number > 999)
    digits = 4;
  else if (number > 99)
    digits = 3;
  else if (number > 9)
    digits = 2;
  else digits = 1;

  // Display digit count
  if (digits < 5)
    printf("The number %d has %d digits\n", number, digits);

  return 0;
}

