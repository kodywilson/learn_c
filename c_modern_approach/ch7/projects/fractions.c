// Perform math on fraction pairs
#include <stdio.h>

int main(void)
{
  int a, b, c, numerator, denominator, numerator1, denominator1, numerator2, denominator2;
  char operator;

  printf("Enter math expression (1/2*3/4 or 1/3+2/3, etc.): ");
  scanf("%d/%d%c%d/%d", &numerator1, &denominator1, &operator, &numerator2, &denominator2);

  switch (operator)
  {
    case '*':
      numerator = numerator1 * numerator2;
      denominator = denominator1 * denominator2;
  }

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

