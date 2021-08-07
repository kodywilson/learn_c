#include <stdio.h>
#include <math.h>

int main()
{
  double x, last_y, y = 1;

  printf("Enter a number: ");
  scanf("%lf", &x);

  do
  {
    last_y = y;
    y = ((x / y) + y) / 2;
  }
  while (fabs(last_y - y) >= .0001 * y);

 printf("Square root: %lf\n", y);

 return 0; 
}

