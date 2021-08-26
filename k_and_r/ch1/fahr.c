#include <stdio.h>

int main(void)
{
  float fahr, celsius;
  float lower, upper, step;

  lower = -17.8f;    // lower limit of temperature scale
  upper = 300.0f;  // upper limit
  step = 20.0f;    // step size

  printf("Celsius  Fahrenheit\n");
  celsius = lower;
  while (celsius <= upper)
  {
    fahr = (celsius * (9.0 / 5.0)) + 32.0;
    printf("%6.1f\t%3.0f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}

