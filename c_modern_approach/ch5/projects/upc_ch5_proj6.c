// This program calculates the check digit for UPC codes

#include <stdio.h>

int main()
{
  // Variables - check, first, sum1, sum2, and all upc code digits
  int check, first, sum1, sum2, x1, x2, x3, x4, x5,
      y1, y2, y3, y4, y5, y6;

  // Take input from user
  printf("Enter UPC code: ");
  scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &first, &x1, &x2, &x3, &x4, &x5, &y1, &y2, &y3, &y4, &y5, &y6);

  // Calculate check digit
  sum1 = first + x2 + x4 + y1 + y3 + y5;
  sum2 = x1 + x3 + x5 + y2 + y4;
  check = 9 - ((sum1 * 3 + sum2 - 1) % 10);

  // Display result
  if (check == y6)
  {
    printf("VALID\n");
  }
  else
  {
    printf("NOT VALID\n");
  }

  return 0;
}

