// This program calculates the check digit for EAN codes

#include <stdio.h>

int main()
{
  // Variables - check, first, sum1, sum2, and code digits
  int check, first, sum1, sum2, x1, x2, x3, x4, x5, x6,
      y1, y2, y3, y4, y5;

  // Take input from user
  printf("Enter the first 12 digits of an EAN: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first, &x1, &x2, &x3, &x4, &x5, &x6, &y1, &y2, &y3, &y4, &y5);

  // Calculate check digit
  sum1 = x1 + x3 + x5 + y1 + y3 + y5;
  sum2 = first + x2 + x4 + x6 + y2 + y4;
  check = 9 - ((sum1 * 3 + sum2 - 1) % 10);

  // Display result
  printf("Check digit: %d\n", check);
  return 0;
}

