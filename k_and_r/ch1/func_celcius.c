#include <stdio.h>

float fahr_2_celsius(float fahr);

int main(void)
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0.0f;    // lower limit of temperature scale
  upper = 300.0f;  // upper limit
  step = 20.0f;    // step size

  printf("Fahrenheit Celsius\n");
  fahr = lower;
  while (fahr <= upper)
  {
    celsius = fahr_2_celsius(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr += step;
  }

  return 0;
}

float fahr_2_celsius(float fahr)
{
  return (5.0 / 9.0) * (fahr - 32.0);
}

