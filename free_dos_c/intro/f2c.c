#include <stdio.h>

int main() {
  float fahr, cels;

  printf("Please enter the temperature in Fahrenheit: \n");
  scanf("%f", &fahr);

  cels = (fahr - 32) * 5 / 9;

  printf("The Fahrenheit temperature %f is %f in Celsius\n", fahr, cels);

  return 0;
}
