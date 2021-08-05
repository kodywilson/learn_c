#include <stdio.h>

int main(void)
{
  double number, sum = 0;

  printf("This program sums a series of numbers.\n");
  printf("Enter integers (0 to terminate): ");

  scanf("%lf", &number);
  
  // get numbers from user
  while (number > 0)
  {
    sum += number;
    scanf("%lf", &number);
  }

  printf("The sum is: %f\n", sum);

  return 0;

}

