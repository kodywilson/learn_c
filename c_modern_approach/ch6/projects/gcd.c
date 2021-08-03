#include <stdio.h>

int main(void)
{
  int a, b, c;

  printf("Enter two integers: ");
  scanf("%d%d", &a, &b);

  // Find the greatest common denominator
  while (a != 0 || b != 0 || c != 0)
  {
    c = a % b;
    a = b;
    if (c == 0)
      break;
    b = c;
  }

  printf("Greatest common factor: %d\n", a);

  return 0;
}

