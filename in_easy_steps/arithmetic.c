#include <stdio.h>

int main(void)
{
  int a =4, b = 8, c =1, d = 1;
  // Math operations
  printf("Addition: %d\n", a + b);
  printf("Subtraction: %d\n", b - a);
  printf("Multipication: %d\n", a * b);
  printf("Division: %d\n", b / a);
  printf("Modulus: %d\n", a % b);
  // Postfix vs prefix increment
  printf("Postfix increment: %d\n", c++);
  printf("Postfix now: %d\n", c);
  printf("Prefix increment: %d\n", ++d);
  printf("Prefix now: %d\n", d);
  return 0;
}

