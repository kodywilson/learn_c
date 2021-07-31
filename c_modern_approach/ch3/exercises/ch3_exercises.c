#include <stdio.h>

int main(void)
{
  // ex1
  printf("%12.5e\n", 30.253);
  printf("%.4f\n", 83.162);
  printf("%-6.2g\n", .0000009979);
  
  // ex2
  printf("%-8.1e\n", 12345.678);
  printf("%10.6e\n", 1.2345);
  printf("%-8.3f\n", 1.345);
  printf("%6.0f\n", 12.5);

  //ex4
  int i, j;
  float x;
  printf("Enter three numbers: ");
  scanf("%d%f%d", &i, &x, &j);
  printf("You entered %d, %f, and %d\n", i, x, j);
  return 0;
}

