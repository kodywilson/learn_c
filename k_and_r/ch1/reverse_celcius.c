#include <stdio.h>

int main(void)
{
  float fahr;
  float lower, upper, step;

  lower = 0.0f;    // lower limit of temperature scale
  upper = 300.0f;  // upper limit
  step = 20.0f;    // step size

  printf("Fahrenheit Celsius\n");
  for (fahr = upper; fahr >= lower; fahr -= step)
    printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

  return 0;
}

