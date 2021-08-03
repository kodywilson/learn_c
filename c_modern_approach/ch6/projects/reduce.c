#include <stdio.h>

int main(void)
{
  int a, b, c, numerator, denominator;

  printf("Enter a fraction: ");
  scanf("%d/%d", &numerator, &denominator);

  // set a to highest val
  if (numerator > denominator)
  {
    a = numerator;
    b = denominator;
  }
  else
  {
    a = denominator;
    b = numerator;
  }

  // find greatest common factor
  while (a != 0 || b != 0 || c != 0)
  {
    c = a % b;
    a = b;
    if (c == 0)
      break;
    b = c;
  }

  printf("In lowest terms: %d/%d\n", numerator / a, denominator / a);

  return 0;
}

