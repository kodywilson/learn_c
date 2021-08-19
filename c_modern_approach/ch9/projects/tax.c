#include <stdio.h>

float calc_tax(float income);

int main(void)
{
  // variables
  float income;

  // get input from user
  printf("Enter taxable income: ");
  scanf("%f", &income);

  // display tax owed
  printf("Tax owed: %.2f\n", calc_tax(income));

  return 0;
}

float calc_tax(float income)
{
  float tax;
  // calculate taxes
  if (income < 750.00f)
  {
    tax = income * .01;
  }
  else if (income < 2250.00f)
  {
    tax = 7.50f + (income - 750.00f) * .02;
  }
  else if (income < 3750.00f)
  {
    tax = 37.50f + (income - 2250.00f) * .03;
  }
  else if (income < 5250.00f)
  {
    tax = 82.50f + (income - 3750.00f) * .04;
  }
  else if (income < 7000.00f)
  {
    tax = 142.50f + (income - 5250.00f) * .05;
  }
  else
  {
    tax = 230.00f + (income - 7000.00f) * .06;
  }

  return tax;
}

