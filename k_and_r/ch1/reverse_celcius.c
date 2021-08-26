#include <stdio.h>

#define LOWER 0.0f
#define UPPER 300.0f
#define STEP 20.0f

int main(void)
{
  float fahr;

  printf("Fahrenheit Celsius\n");
  for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    printf("%3.0f\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));

  return 0;
}

