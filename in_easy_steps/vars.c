#include <stdio.h>

int main(void)
{
  int num = 100;
  int num2 = 1000;
  double pi = 3.1415926536;
  printf("Integer is %d\n", num);
  printf("Values are %d and %f\n", num, pi);
  printf("%%7 Displays %7d\n", num);
  printf("Displays %7d\n", num2);
  printf("Displays %07d\n", num);
  printf("Displays %07d\n", num2);
  printf("Pi is approximately %1.10f\n", pi);
  printf("Right-aligned %20.3f rounded pi\n", pi);
  printf("Left-aligned %-20.3f rounded pi\n", pi);
  return 0;
}

