#include <stdio.h>

int main(void)
{
  float a, sum = 1.00f;

  printf("Enter an integer: ");
  scanf("%f", &a);

  for (float i = 1.00f; i <= a; i++)
    sum = sum + (1 / i);

  printf("e = %10.8f\n", sum);

  return 0;
}

