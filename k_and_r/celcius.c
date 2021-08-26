#include <stdio.h>

int main(void)
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0.0f;    // lower limit of temperature scale
  upper = 300.0f;  // upper limit
  step = 20.0f;    // step size

  fahr = lower;
  while (fahr <= upper)
  {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}

