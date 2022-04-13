#include <stdio.h>

int main() {
  int cels, fahr;

  //puts("Please enter a temperature in Fahrenheit:");
  //scanf("%d", &fahr);

  for (fahr = 98; fahr <= 104; fahr++) {
    cels = (fahr - 32) * 5 / 9;
    printf("The Fahrenheit temperature %d is the same as %d in Celsius.\n", fahr, cels);
  }

  return 0;
}
