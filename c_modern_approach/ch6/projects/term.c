// find smallest term after value entered by user
#include <stdio.h>

int main(void)
{
  float a, sum = 1.00f, term_denominator, term_value = 1.00f;

  printf("Enter a small float (ie. .00034): ");
  scanf("%f", &a);

  for (float i = 1.00f; term_value > a; i++)
  {
    term_denominator = i;
    term_value = 1 / i;
    sum+= term_value;
    //printf("%f  %f\n", term_value, sum);
  }

  printf("e = %10.8f and term was 1/%.0f\n", sum, term_denominator);

  return 0;
}

