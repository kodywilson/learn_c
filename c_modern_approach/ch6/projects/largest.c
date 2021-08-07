#include <stdio.h>

int main(void)
{
  float largest = .0f, number;

  for (;;)
  {
    printf("Enter a number: ");
    scanf("%f", &number);
    if (number <= 0)
      break;
    if (number > largest)
      largest = number;
  }
  printf("\nThe largest number entered was %f\n", largest);

  return 0;
}

