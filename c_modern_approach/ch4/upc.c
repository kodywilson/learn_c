// This program calculates the check digit for UPC codes

#include <stdio.h>

int main()
{
  // Variables - check, first, sum1, sum2, and manufacturer group of 5 digits
  int check, first, sum1, sum2, x1, x2, x3, x4, x5,
      y1, y2, y3, y4, y5; // item code group of 5

  // Take input from user
  printf("Enter the first (single) digit: ");
  scanf("%d", &first);
  printf("Enter first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &x1, &x2, &x3, &x4, &x5);
  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &y1, &y2, &y3, &y4, &y5);

  // Calculate check digit
  sum1 = first + x2 + x4 + y1 + y3 + y5;
  sum2 = x1 + x3 + x5 + y2 + y4;
  check = 9 - ((sum1 * 3 + sum2 - 1) % 10);

  // Display result
  printf("Check digit: %d\n", check);
  return 0;
}

