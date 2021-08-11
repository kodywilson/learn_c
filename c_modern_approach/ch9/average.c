// find averages of two numbers
#include <stdio.h>

double average(double a, double b);

int main(void)
{
  double x, y, z;

  printf("Please enter three numbers: ");
  scanf("%lf %lf %lf", &x, &y, &z);

  printf("Average of %g and %g is %g\n", x, y, average(x, y));
  printf("Average of %g and %g is %g\n", x, z, average(x, z));
  printf("Average of %g and %g is %g\n", y, z, average(y, z));

  return 0;
}

double average(double a, double b)
{
  return (a + b) / 2;
}

